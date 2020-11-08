/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:15:05 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/17 22:46:15 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define CHECK0RET(x, r) if (!(x)) return (r)
# define CHECK0RET0(x) CHECK0RET(x, 0)
# define CHECK0RET1(x) CHECK0RET(x, -1)
# define CHECK1RET1(x) if ((x) < 0) return (-1)

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_itoa(int n);
int					ft_atoi(const char *str);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_clear(char **p);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src,
								int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *string);
size_t				ft_len(void **s);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *destptr, const char *srcptr);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *destptr, const char *srcptr, size_t num);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
								const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin_left(const char *s1, char *s2);
char				*ft_strjoin_right(char *s1, const char *s2);
char				*ft_strjoin_char(char *str, char end);

# ifndef IS_SPACE
#  define IS_SPACE(x) (x==' '||x=='\n'||x=='\t')
# endif

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buff
{
	char	*data;
	size_t	len;
	size_t	size;
}					t_buff;

int					t_buff_append(t_buff *b, void *data, size_t len);
void				*t_buff_init(t_buff *b, size_t size);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_countwords(char const *str, char c);
char				*ft_strndup(const char *s1, size_t n);
void				*ft_memdup(void *s1, size_t n);
char				*ft_capitalize(char *s);
t_list				*ft_lst_reverse(t_list *alst);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char				*ft_strjoinch(char const *s1, char c);
char				*ft_strnchr(char *s, char c, int offset);
int					ft_copyuntil(char **dst, char *src, char c);
int					ft_strstartswith(char *s1, char *s2);
int					ft_intlen(int num);
int					ft_strendswith(char *s1, char *s2);
char				*ft_pathjoin(char *p1, char *p2);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_putnstr(char *str, int n);
char				*ft_strreplace(char *str, char *term, char *replace_by);
int					ft_isemptystr(char *str, int consider_space);
char				**ft_strsplitall(char const *s);
int					ft_countwordsall(char const *str);
void				ft_freestrarr(char **arr);
char				*ft_strjoincl(char *s1, char *s2, int free_both);
char				*ft_strjoinchcl(char *s1, char c);
int					ft_count2darray(char **arr);
int					ft_strarrmax(char **arr);
char				*ft_get_parent_path(char *path);

#endif