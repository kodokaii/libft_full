/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kodokai <kodokai.featheur@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:43:09 by kodokai           #+#    #+#             */
/*   Updated: 2023/11/08 19:04:44 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>

# define INVALID_PID -1
# define INVALID_FD -1

typedef unsigned char		t_byte;
typedef unsigned int		t_uint;
typedef unsigned long long	t_llu;

typedef enum e_bool
{
	FT_FALSE	= 0,
	FT_TRUE		= 1
}	t_bool;

typedef struct s_buf
{
	t_byte	*buf;
	ssize_t	len;
}	t_buf;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_uint		ft_bytelen(t_byte n, t_byte base);
t_uint		ft_intlen(int n, int base);
t_uint		ft_uintlen(t_uint n, int base);
t_uint		ft_llulen(t_llu n, int base);

int			ft_min_int(int a, int b);
t_uint		ft_min_uint(t_uint a, t_uint b);
size_t		ft_min_size_t(size_t a, size_t b);
ssize_t		ft_min_ssize(ssize_t a, ssize_t b);
double		ft_min_double(double a, double b);

int			ft_max_int(int a, int b);
t_uint		ft_max_uint(t_uint a, t_uint b);
size_t		ft_max_size(size_t a, size_t b);
ssize_t		ft_max_ssize(ssize_t a, ssize_t b);
double		ft_max_double(double a, double b);

t_byte		ft_abs_char(t_byte n);
t_uint		ft_abs_int(t_uint n);
double		ft_abs_double(double n);

t_bool		ft_isalpha(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_isalnum(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isprint(int c);
t_bool		ft_isspace(int c);

int			ft_toupper(int c);
int			ft_tolower(int c);

void		ft_bzero(void *s, size_t n);
void		*ft_memdup(const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memchrset(void const *s, void const *set,
				size_t size_s, size_t size_set);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strpbrk(const char *s, const char *charset);

size_t		ft_word_len(char const *str, char const *sep);
size_t		ft_count_word(char const *str, char const *sep);
char		**ft_split(char const *s, char *sep);

int			ft_atoi(const char *str);
double		ft_atof(const char *str);
int			ft_strtoi(const char *nptr, char **endptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_substr(char const *s, size_t start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(size_t, char));
void		ft_striteri(char *s, void (*f)(size_t, char*));

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putstrn_fd(const char *s, size_t n, int fd);
void		ft_putendl_fd(const char *s, int fd);

void		ft_putuint_fd(t_uint n, int fd);
void		ft_putint_fd(int n, int fd);

void		ft_putint_base_fd(int n, char *base, int fd);
void		ft_putuint_base_fd(t_uint n, char *base, int fd);
void		ft_putllu_base_fd(t_llu n, char *base, int fd);

int			ft_printf(const char *str, ...);
int			ft_dprintf(int fd, const char *str, ...);

char		**ft_argv(char **init_argv);

char		*ft_basename(char const *s);
char const	*ft_get_envp(char const *var, char *const *envp);

t_buf		ft_gnl(int fd);
int			ft_close(int *fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *mew);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *mew);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif 
