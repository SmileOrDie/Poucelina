#include <interprete.h>
#include <string.h>

#include <stdio.h>

void			set_argc(t_env *env)
{
	char	in_word;
	size_t	pos;

	env->argc = 0;
	pos = env->start;
	in_word = FALSE;
	while (pos < env->len && env->interprete[pos] != DELIMITER)
	{
		if (env->interprete[pos] == SPACING)
				in_word = FALSE;
		else
		{
			if (in_word == FALSE)
				++env->argc;
			in_word = TRUE;
		}
		++pos;
	}
}

int			avoid_allocation(t_env *env, size_t *pos, char ***ptr)
{
	size_t		saved_pos;
	char		tmp_char;

	saved_pos = *pos;
	if (env->interprete[*pos] == TILDE)
	{
		**ptr = env->home;
		++*pos;
	}
	else if (env->interprete[saved_pos + 1] == ALONE_LOCAL_VARIABLE)
	{
		++saved_pos;
		while (env->interprete[saved_pos] == ALONE_LOCAL_VARIABLE)
			++saved_pos;
		tmp_char = env->buffer[saved_pos];
		env->buffer[saved_pos] = '\0';
		**ptr = ht_get(env->local_variables, env->buffer + *pos + 1);
		env->buffer[saved_pos] = tmp_char;
		*pos = saved_pos;
	}
	else
	{
		while (saved_pos < env->len && env->interprete[saved_pos] != SPACING)
		{
			if (env->interprete[saved_pos] != INTERPRETED)
				return (0);
			++saved_pos;
		}
		**ptr = env->buffer + *pos;
		*pos = saved_pos;
		env->buffer[saved_pos] = '\0';
	}
	++*ptr;
	++env->argc;
	return (1);
}

size_t		should_len(t_env *env, size_t *pos, char ***ptr)
{
	size_t	len;

	if (avoid_allocation(env, pos, ptr))
		return (0);
	len = 0;
	while (*pos < env->len && env->interprete[*pos] != SPACING &&
		env->interprete[*pos] != DELIMITER)
	{
		if (env->interprete[*pos] == INTERPRETED)
			len += len_normal(env, pos);
		else if (env->interprete[*pos] == SIMPLE_QUOTED)
			len += len_simple_quote(env, pos);
		else if (env->interprete[*pos] == DOUBLE_QUOTED)
			len += len_double_quote(env, pos);
		else if (env->interprete[*pos] == BACK_QUOTED)
			len += len_back_quote(env, pos);
		else if (env->interprete[*pos] == BACKSLASHED)
			len += len_backslash(env, pos);
		else if (env->interprete[*pos] == START_LOCAL_VARIABLE)
			len += len_value(env, pos);
	}
	return len;
}

void		extract_content(t_env *env, size_t pos, char *ptr)
{
	while (pos < env->len && env->interprete[pos] != SPACING &&
		env->interprete[env->pos] != DELIMITER)
	{
		if (env->interprete[pos] == INTERPRETED)
			extract_normal(env, &pos, &ptr);
		else if (env->interprete[pos] == SIMPLE_QUOTED)
			extract_simple_quote(env, &pos, &ptr);
		else if (env->interprete[pos] == DOUBLE_QUOTED)
			extract_double_quote(env, &pos, &ptr);
		else if (env->interprete[pos] == BACK_QUOTED)
			extract_back_quote(env, &pos, &ptr);
		else if (env->interprete[pos] == BACKSLASHED)
			extract_backslash(env, &pos, &ptr);
		else if (env->interprete[pos] == START_LOCAL_VARIABLE)
			extract_value(env, &pos, &ptr);
	}
	*ptr = '\0';
}

int			set_argv(t_env *env)
{
	size_t	pos;
	size_t	tmp_pos;
	size_t	len;
	char	**ptr;

	ptr = env->argv;
	env->error = NO_ERROR;
	pos = env->start;
	while (pos < env->len && env->interprete[pos] != DELIMITER)
	{
		while (pos < env->len && env->interprete[pos] == SPACING)
			++pos;
		tmp_pos = pos;
		if ((len = should_len(env, &pos, &ptr)))
		{
			if (!(*ptr = (char *)malloc(sizeof(char) * (len + 1))))
				return (ERROR);
			if (env->argv_pool_size < _POSIX_ARG_MAX)
				env->argv_pool[env->argv_pool_size++] = *ptr;
			else
				env->error = ERROR;
			extract_content(env, tmp_pos, *ptr);
			++ptr;
		}
		else
			--env->argc;
		if (env->error == ERROR)
			return (ERROR);
	}
	*ptr = NULL;
	env->start = pos + 1;
	return (NO_ERROR);
}