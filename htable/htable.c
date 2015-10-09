/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:34:40 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 15:26:04 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <htable.h>

hashtable_t				*ht_create(int size)
{
	hashtable_t			*hashtable = NULL;
	int			i;

	if (size < 1)
		return (NULL);
	if (( hashtable = (hashtable_t *)malloc(sizeof(hashtable_t))) == NULL)
		return (NULL);
	if ((hashtable->table = (entry_t **)malloc(sizeof(entry_t *) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		hashtable->table[i++] = NULL;
	hashtable->size = size;
	return (hashtable);
}

int						ht_hash(hashtable_t *hashtable, char *key)
{

	unsigned long int	hashval;
	int					i;

	i = 0;
	hashval = 0;
	while (hashval < ULONG_MAX && i < ft_strlen(key))
	{
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}
	return (hashval % hashtable->size);
}

entry_t					*ht_newpair(char *key, void *value)
{
	entry_t				*newpair;

	if ((newpair = (entry_t *)malloc( sizeof(entry_t))) == NULL)
		return (NULL);
	if ((newpair->key = key) == NULL)
		return (NULL);
	if ((newpair->value = value) == NULL)
		return (NULL);
	newpair->next = NULL;
	return (newpair);
}

void					ht_set(hashtable_t *hashtable, char *key, void *value )
{
	int					bin;
	entry_t				*newpair;
	entry_t				*next;
	entry_t				*last;

	bin = ht_hash(hashtable, key);
	newpair = NULL;
	next = hashtable->table[bin];
	last = NULL;
	while(next != NULL && next->key != NULL && ft_strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	if( next != NULL && next->key != NULL && ft_strcmp(key, next->key) == 0)
	{
		free( next->value );
		next->value = value;

	}
	else
	{
		newpair = ht_newpair( key, value );
		if(next == hashtable->table[ bin ])
		{
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
		}
		else if (next == NULL)
			last->next = newpair;
		else
		{
			newpair->next = next;
			last->next = newpair;
		}
	}
}

char					*ht_get(hashtable_t *hashtable, char *key)
{
	int					bin;
	entry_t				*pair;

	bin = ht_hash(hashtable, key);
	pair = hashtable->table[bin];
	while (pair != NULL && pair->key != NULL && ft_strcmp(key, pair->key) > 0)
		pair = pair->next;
	if (pair == NULL || pair->key == NULL || ft_strcmp(key, pair->key) != 0)
		return (NULL);
	else
		return (pair->value);
}
