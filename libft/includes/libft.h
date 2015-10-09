/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:19:32 by shamdani          #+#    #+#             */
/*   Updated: 2015/05/21 18:41:53 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 42

char		*ft_strcat(char *s1, const char *s2);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_strlen(const char *s);
int			ft_strequ(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
void		ft_putstr(const char *str);
void		ft_putstr_fd(const char *str, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl(const char *str);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
void		ft_bzero(void *s, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strstr(const char *s1, const char *s2);
void		ft_strdel(char **as);
char		*ft_strncat(char *s1, const char *s2, size_t n);
void		*ft_memalloc(size_t size);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strnew(size_t size);
void		ft_memdel(void **ap);
int			ft_memcmp (const void *s1, const void *s2, size_t n);
char		*ft_strchr(char const *s, int c);
char		*ft_strrchr(char const *s, int c);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
void		ft_strclr(char *s);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s);
int			ft_isblank(int c);
char		**ft_strsplit(char const *s, char c);
int			ft_getnbr(char *str);
int			get_next_line(int const fd, char **line);

#endif
