#ifndef INTERPRETE_H
# define INTERPRETE_H

# include <shell.h>
# include <string.h>

# define INTERPRETED 0
# define SPACING 1
# define SIMPLE_QUOTED 2
# define DOUBLE_QUOTED 3
# define BACK_QUOTED 4
# define BACKSLASHED 5
# define START_LOCAL_VARIABLE 6
# define LOCAL_VARIABLE 7
# define ALONE_LOCAL_VARIABLE 8
# define TILDE 9
# define DELIMITER 10
# define REMOVE 11

# define NO_TOKEN 0
# define COMMA 1
# define AND 2
# define OR 3
# define PIPE 4
# define BACKGROUND 5

# define STOP 0
# define CONTINUE 1
# define NOT_CLOSED 2

char		start_interprete(t_env *env);
char		launch_interprete(t_env *env);

void		debug_env(t_env *env);
void		put_env(t_env *env);

void		set_argc(t_env *env);
int			set_argv(t_env *env);
int			set_arguments(t_env *env);

void		do_interprete(t_env *env);
void		interprete_simple_quote(t_env *env);
void		interprete_double_quote(t_env *env);
void		interprete_back_quote(t_env *env);
void		interprete_value(t_env *env);
void		interprete_backslash(t_env *env);
void		interprete_tilde(t_env *env);
void		interprete_spacing(t_env *env);
void		interprete_normal(t_env *env);
void		interprete_null(t_env *env);
void		interprete_comma(t_env *env);
void		interprete_and(t_env *env);
void		interprete_or(t_env *env);
void		interprete_background(t_env *env);
void		interprete_pipe(t_env *env);

void		do_process(t_env *env);
void		process_back_quotes(t_env *env);

void		do_simplify(t_env *env);

size_t		len_normal(t_env *env, size_t *pos);
size_t		len_simple_quote(t_env *env, size_t *pos);
size_t		len_double_quote(t_env *env, size_t *pos);
size_t		len_back_quote(t_env *env, size_t *pos);
size_t		len_backslash(t_env *env, size_t *pos);
size_t		len_value(t_env *env, size_t *pos);

void		extract_normal(t_env *env, size_t *pos, char **ptr);
void		extract_simple_quote(t_env *env, size_t *pos, char **ptr);
void		extract_double_quote(t_env *env, size_t *pos, char **ptr);
void		extract_back_quote(t_env *env, size_t *pos, char **ptr);
void		extract_backslash(t_env *env, size_t *pos, char **ptr);
void		extract_value(t_env *env, size_t *pos, char **ptr);

void		add_local_variable(t_env *env, const char *key, const char *value);

void		*malloc(size_t size);

#endif
