/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:27:54 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/06 19:40:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

# define BASE_HEXA "0123456789abcdef"
# define BASE_HEXA_UP "0123456789ABCDEF"
# define BASE_OCTAL "01234567"
# define BASE_BINARY "01"
# define BASE_DENARY "0123456789"

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_hash
{
	int				key;
	size_t			data_size;
	void			*data;
	struct s_hash	*next;
}					t_hash;

typedef union		u_dbl
{
	double			val;
	struct
	{
		size_t		mant: 52;
		t_uint		expn: 11;
		t_uint		sign: 1;
	}				bits;
}					t_dbl;

/*
** IO FUNCTIONS
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_npr(char *str);
int					ft_putnbr_base(int n, char *base);
void				*ft_print_memory(void *addr, unsigned int size);
void				ft_print_bits(uint64_t val, size_t type);

/*
** LIST FUNCTIONS
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpush(t_list **alist, t_list *list);

/*
** MEMORY FUNCTIONS
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *src, size_t n);

/*
** STRING FUNCTIONS
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strchri(const char *s, int c);
int					ft_strchrn(const char *s, int c);
char				*ft_strstr(const char *src, const char *find);
char				*ft_strcasestr(const char *src, const char *find);
char				*ft_strnstr(const char *src, const char *find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcasenequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_issign(int c);
int					ft_char_count(char *s, char find);
char				*ft_strappend(char *dst, char *append);
char				*ft_strnappend(char *dst, char *append, size_t n);
char				*ft_itoa_base(int nbr, char *base);
int					ft_strcinsert(char *str, char ins, size_t pos);
int					ft_wcstombs(unsigned char *s, wchar_t *wcs, size_t n);
int					ft_wctomb(unsigned char *s, wchar_t wc);
char				*ft_strrev(char *str);
size_t				ft_wcslen(wchar_t *wcs);
size_t				ft_wcsnlen(wchar_t *wcs, size_t n);
int					ft_ccat(char *dst, char app);
char				*ft_strtoupper(char *str);

/*
** HASH FUNCTIONS
*/

t_hash				*ft_hashnew(int key, void const *data, size_t data_size);
t_hash				*ft_hashpop(t_hash **list, int key);
void				ft_hashpush(t_hash **list, t_hash *elem);
void				ft_hashdel(t_hash **elem);
int					ft_hashadd(t_hash **list, int key, void *data, size_t size);
void				*ft_hashget(t_hash **list, int key);

/*
** BINARY FUNCTIONS
*/

int					ft_is_bit_set(int64_t set, int bit);
int64_t				ft_toggle_bit(int64_t set, int bit);

#endif
