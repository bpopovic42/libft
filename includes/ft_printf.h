/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:28:14 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/06 19:17:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <locale.h>

# define FT_PRINTF_BUFF_SIZE 128
# define MAX_INT_LEN 21
# define MAX_DBL_PRECISION 200
# define MAX_DBL_LEN 500
# define FT_PRINTF_EOC "\e[39m"
# define FT_PRINTF_BLK "\e[30m"
# define FT_PRINTF_RED "\e[31m"
# define FT_PRINTF_GRN "\e[32m"
# define FT_PRINTF_YLW "\e[33m"
# define FT_PRINTF_BLU "\e[34m"
# define FT_PRINTF_MAG "\e[35m"
# define FT_PRINTF_CYA "\e[36m"

typedef struct		s_fmt
{
	const char		*format;
	uint64_t		i;
}					t_fmt;

typedef struct		s_buff
{
	char			buff[FT_PRINTF_BUFF_SIZE + 1];
	size_t			pos;
	uint64_t		read;
}					t_buff;

typedef struct		s_ptf
{
	struct s_buff	buff;
	struct s_fmt	fmt;
	int				fd;
	int				width;
	int				precision;
	char			spec;
	char			flags[11];
	char			*base;
}					t_ptf;

/*
** FT_PRINTF
*/

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);
int					ft_vdprintf(int fd, const char *restrict fmt, va_list ap);

/*
** FT_PRINTF_TYPE
*/

int					ft_printf_type_int(t_ptf *ptf, int64_t param);
int					ft_printf_type_str(t_ptf *ptf, wchar_t *param);
int					ft_printf_type_char(t_ptf *ptf, wchar_t param);
int					ft_printf_type_dbl(t_ptf *ptf, double param);
int					ft_printf_type_n(t_ptf *ptf, int *n);
int					ft_printf_type_mod(t_ptf *ptf);

/*
** FT_PRINTF_GET_FLAGS
*/

uint64_t			ft_printf_get_flags(t_ptf *ptf, va_list ap, uint64_t i);

/*
** FT_PRINTF_PRINT_ARG
*/

void				ft_printf_print(t_ptf *ptf, char *prfx, char *inp, int n);
void				ft_printf_print_wcs(t_ptf *ptf, wchar_t *input, int n);

/*
** FT_PRINTF_BUFFER
*/

void				ft_printf_buff_cat(t_ptf *ptf, char *inp, uint64_t siz);
void				ft_printf_buff_catn(t_ptf *ptf, char *inp, uint64_t n);
void				ft_printf_buff_cat_npr(t_ptf *ptf, char *inp, uint64_t siz);
void				ft_printf_dump_fmt(t_ptf *ptf);

/*
** FT_PRINTF_TOOLS
*/

int					ft_printf_is_flag(int c);
int					ft_printf_is_spec(int c);
size_t				ft_printf_atoi(const char *str, int *res);
int					ft_printf_lltoa_base(char *buff, char *chrst, int64_t nb);
int					ft_printf_ulltoa_base(char *buff, char *chrst, uint64_t nb);
int					ft_printf_dtoa(double val, int prec, char *buff, char spec);

/*
** MISC
*/

int					ft_printf_color(t_ptf *ptf);

#endif
