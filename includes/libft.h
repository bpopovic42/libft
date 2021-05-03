/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:27:54 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:31:07 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

# define STDERR 2
# define BASE_HEXA "0123456789abcdef"
# define BASE_HEXA_UP "0123456789ABCDEF"
# define BASE_OCTAL "01234567"
# define BASE_BINARY "01"
# define BASE_DENARY "0123456789"
# define VECTOR_INITIAL_SIZE 1
# define WSPCS "\040\t"

typedef unsigned int	t_uint;
typedef unsigned long long t_uint64;
typedef unsigned char	t_uchar;
typedef int				t_word;

typedef struct		s_node
{
	void			*data;
	size_t			data_size;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_list
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_dict
{
	int				key;
	size_t			data_size;
	void			*data;
	struct s_dict	*next;
}					t_dict;

typedef struct		s_hash
{
	char			*key;
	size_t			data_size;
	void			*data;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_htable
{
	size_t			size;
	struct s_hash	**table;
}					t_htable;

typedef struct		s_vect
{
	size_t			size;
	size_t			capacity;
	void			**data;
	size_t			data_size;
}					t_vect;

typedef struct		s_bmap
{
	size_t			size;
	int				*bits;
}					t_bmap;

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
void				ft_print_bits(u_int64_t val, size_t type);
void				ft_perror(const char *error);

/*
** LIST FUNCTIONS
*/

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list *alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list *alst, t_node *new);
void				ft_lstiter(t_list *lst, void (*f)(t_node *node));
void				ft_lstpush_node(t_list *alst, t_node *node);
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
t_dlist				*ft_dlstpop(t_dlist *elem);
void				ft_dlstpush(t_dlist **head, t_dlist *elem);
void				ft_dlstadd(t_dlist **alst, t_dlist *elem);
void				ft_dlstinsert(t_dlist **alst, t_dlist *elem);
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
int					ft_lstadd_data(t_list *alst, void *data, size_t data_size);
void				ft_lstsort(t_list *alst, int (*cmp)(void*, void*));
t_list				*ft_lstnew(void);
t_node				*ft_node_new(void const *data, size_t data_size);
void				ft_node_del(t_node **node, void (*del)(void *, size_t));
t_node				*ft_node_dup(t_node *node);
void				ft_lstpush_back(t_list *list, t_node *node);
int					ft_lstpush_back_data(t_list *lst, void *d, size_t d_size);
t_node				*ft_lstpop(t_list *list);
void				*ft_lstpop_data(t_list *list);
t_node				*ft_lstget_tail(t_list *list);
void				*ft_lstget_tail_data(t_list *list);
t_list				*ft_lstdup(t_list *list);
void				ft_lstnode_remove(t_list *list, t_node *target);
void				ft_lstinsert_after(t_list *src, t_node *dest);
void				ft_lst_filter(t_list *list, t_list **result,
						int (f)(t_node *node));
int					ft_lstmap(t_list *lst, void *res,
						int (map)(t_node *node, void *res));
int					ft_lstapply(t_list *lst, int (apply)(t_node *node));
int					ft_lstmutate(t_list *src, t_list *dst,
						int (mut)(t_node *src, t_node **dst));

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
int					ft_realloc(void **ptr, size_t size, size_t new_size);
void				ft_delarray(void *array);

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
char				**ft_strsplit(char const *s, char *split);
char				*ft_itoa(int n);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_issign(int c);
int					ft_char_count(char *s, char find);
char				*ft_strappend(char *dst, char *append);
char				*ft_strappendn(char *dst, size_t ac, ...);
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
long				ft_atol(const char *str);
size_t				ft_count_words(const char *s, const char *spaces);
int					ft_is_valid_int(const char *nbr);
char				*ft_strcatn(char *s1, size_t ac, ...);
size_t				ft_intlen(int nbr);

/*
** DICTIONARY FUNCTIONS
*/

int					ft_dictadd(t_dict **list, int key, void *data, size_t size);
void				ft_dictdel(t_dict **elem, void (*del)(void **, size_t));
void				*ft_dictget(t_dict **list, int key);
t_dict				*ft_dictnew(int key, void const *data, size_t data_size);
t_dict				*ft_dictpop(t_dict **list, int key);
void				ft_dictpush(t_dict **list, t_dict *elem);

/*
** HASH FUNCTIONS
*/

t_htable			*ft_hash_newtable(size_t table_size);
void				ft_hash_freetable(t_htable **t, void (*d)(void *));
t_hash				*ft_hashnew(char *key, void *data, size_t data_size);
t_hash				*ft_hashpop(t_htable *table, char *key);
void				ft_hashpush(t_htable *table, t_hash *elem);
void				ft_hashdel(t_hash *hash, void (*del)(void *));
int					ft_hashadd(t_htable *table, t_hash *entry);
t_hash				*ft_hashget(t_htable *table, char *key);
void				*ft_hashget_data(t_htable *table, char *key);
int					ft_hash(t_htable *table, char *key);
int					ft_hashpush_data(t_htable *t, char *k, void *d, size_t s);

/*
** VECTOR FUNCTIONS
*/

void				ft_vector_free(t_vect *v, void (*del)(void **, size_t));
t_vect				*ft_vector_init(size_t data_size, size_t capacity);
int					ft_vector_append(t_vect *v, void **value);
void				*ft_vector_get(t_vect *v, size_t index);
int					ft_vector_resize(t_vect *v);
void				ft_vector_iter(t_vect *v, void (*f)(void *data));

/*
** BITMAP FUNCTIONS
*/

void				ft_bitmap_clear_bit(t_bmap *bmap, size_t bit);
t_bmap				*ft_bitmap_dup(t_bmap *bmap);
int					ft_bitmap_has_bit(t_bmap *bmap, size_t bit);
t_bmap				*ft_bitmap_new(size_t binary_size);
void				ft_bitmap_set_bit(t_bmap *bmap, size_t bit);

/*
** ARRAY FUNCTIONS
*/

void				**ft_array_new(size_t x, size_t y, size_t data_size);

#endif
