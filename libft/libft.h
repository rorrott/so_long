/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:51:33 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/01 12:29:54 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>

/*****************************************************************************/
/*				STRUCT					     */
/*****************************************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*****************************************************************************/
/*                        	CHECK                                        */
/*****************************************************************************/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/****************************************************************************/
/*				MEMORY	                                    */
/****************************************************************************/

void	ft_bzero(void *ptr, size_t num);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memchr(const void *ptr, int value, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t num);
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_free_split(char **split);

/****************************************************************************/
/*				PRINT					    */
/****************************************************************************/

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/****************************************************************************/
/*				STRING					    */
/****************************************************************************/

int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_freejoin(char *s1, char *s2, int sizeS1, int sizeS2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

/*****************************************************************************/
/*				LIST					     */
/*****************************************************************************/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
