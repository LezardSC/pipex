/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:09:59 by jrenault          #+#    #+#             */
/*   Updated: 2023/06/11 03:23:24 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			*free_tab(char **tab);
void			*free_tab_void(void **tab);
void			*free_tab_int(int **tab, int size);
int				ft_atoi(const char *str);
void			*ft_bzero(void *pointer, size_t n);
void			*ft_calloc( size_t elCount, size_t elSize);
int				ft_count(int n);
int				ft_count_long(long int n);
int				ft_count_ul(unsigned long int n);
int				ft_count_unsigned(unsigned int n);
int				ft_isalnum(int ch);
int				ft_isalpha(int ch);
int				ft_isascii(int c);
int				ft_isdigit(int ch);
int				ft_isprint(int ch);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memchr(const void *memBlock, int srchChar, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memset(void *pointer, int value, size_t count);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_base(int nbr, char *base);
void			ft_putnbr_base_ul(unsigned long nbr, char *base);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int nb);
void			ft_putunbr(unsigned int nb);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *str);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char	*string, int searchCh);
char			*ft_strdup( const char *source );
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strncpy(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
int				ft_strlen_doublechar(char **str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_strrchr(const char *string, int searchedCh);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_swap_int(int *a, int *b);
int				ft_tolower(int ch);
int				ft_toupper(int ch);

#endif