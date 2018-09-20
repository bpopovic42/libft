# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 08:42:00 by bopopovi          #+#    #+#              #
#*   Updated: 2018/09/20 15:14:26 by bopopovi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

############################## SRCS ############################################

# **************************************************************************** #
# Input/Output :

SRC_IO		=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
			ft_putstr_npr.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_print_memory.c ft_print_bits.c get_next_line.c

# **************************************************************************** #
# Lists :

SRC_LST		=	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_lstpush.c ft_dlstnew.c ft_dlstdel.c \
			ft_dlstdelone.c ft_dlstpop.c ft_dlstpush.c

# **************************************************************************** #
# Memory :

SRC_MEM		=	ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
			ft_memdel.c ft_memdup.c

# **************************************************************************** #
# Strings :

SRC_STR		=	ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c \
			ft_toupper.c ft_tolower.c ft_strlen.c ft_strcpy.c \
			ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strcat.c \
			ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strchr.c \
			ft_strchri.c ft_strstr.c ft_strnstr.c ft_itoa_base.c \
			ft_atoi.c ft_strdup.c ft_strndup.c ft_strnew.c \
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
			ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			ft_itoa.c ft_issign.c ft_char_count.c ft_strappend.c \
			ft_strnappend.c ft_strcinsert.c ft_wctomb.c ft_wcstombs.c \
			ft_wcslen.c ft_strrev.c ft_wcsnlen.c ft_strchrn.c ft_ccat.c \
			ft_strtoupper.c ft_strcasestr.c ft_strcasenequ.c ft_atol.c

# **************************************************************************** #
# Hash :

SRC_HASH	=	ft_hashnew.c ft_hashpop.c ft_hashpush.c ft_hashdel.c \
			ft_hashget.c ft_hashadd.c

# **************************************************************************** #
# Binary :

SRC_BIN		=	ft_toggle_bit.c ft_is_bit_set.c

# **************************************************************************** #
# Printf :

SRC_PTF		=	ft_printf.c ft_printf_buffer.c ft_printf_tools.c \
			ft_printf_print_arg.c ft_printf_get_flags.c ft_vprintf.c \
			ft_printf_type_int.c ft_printf_type_str.c ft_printf_type_char.c \
			ft_printf_type_dbl.c ft_printf_type_others.c ft_printf_dtoa.c \
			ft_printf_color.c

############################## VAR #############################################

IO			=	$(addprefix ft_io/, $(SRC_IO))

LST			=	$(addprefix ft_lst/, $(SRC_LST))

MEM			=	$(addprefix ft_mem/, $(SRC_MEM))

STR			=	$(addprefix ft_str/, $(SRC_STR))

HASH		=	$(addprefix ft_hash/, $(SRC_HASH))

BIN			=	$(addprefix ft_bin/, $(SRC_BIN))

PTF			=	$(addprefix ft_printf/, $(SRC_PTF))

SRCS		=	$(IO) $(LST) $(MEM) $(STR) $(HASH) $(BIN) $(PTF)

INC			=	$(addprefix -I,$(IDIR)/)

SRC			=	$(addprefix $(SDIR)/, $(SRCS))

OBJ			=	$(addprefix $(ODIR)/, $(OBJS))

IDIR		=	./includes

SDIR		=	./srcs

ODIR		=	./objs

LFTS		=	libft.h ft_printf.h get_next_line.h

LFT			=	$(addprefix $(IDIR)/, $(LFTS))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	$(DEBUG) -Wall -Wextra -Werror

############################## RULES ###########################################

all			:	$(NAME)

$(NAME)		:	$(OBJ)
			@ar rcs $(NAME) $(OBJ)
			@$(CLR)
			@echo $(UP) $(CUT) $(UP)
			@if [ "$(DEBUG)" == "-g" ]; then echo $(UP) $(CUT) $(UP); fi;
			@/bin/rm -f .cmp
			@echo $(G)[$(B)LIBFT $(G)COMPILED]$(X)


$(ODIR)/%.o	:	$(SDIR)/%.c $(LFT)
			@$(CMP)
			@$(MKODIR)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@
			@$(CLR)
			@echo -n $@

clean		:
			@echo $(R)Cleaning $(X)the $(B)Libft $(X)files...
			@/bin/rm -f $(OBJ)
			@/bin/rm -rf $(ODIR)
			@echo $(UP) $(CUT) $(UP)
			@echo $(G)[$(B)LIBFT $(G)CLEANED]$(X)

fclean		:	clean
			@/bin/rm -f $(NAME)

re			:	fclean all

.PHONY		:	all, clean, fclean, re

############################## FUN #############################################

BY			=	"\033[33;1m"
BR			=	"\033[31;1m"
BG			=	"\033[32;1m"
BB			=	"\033[34;1m"
BM			=	"\033[35;1m"
BC			=	"\033[36;1m"
BW			=	"\033[37;1m"
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
KW			=	"\033[37;5m"
KR			=	"\033[31;5m"
KG			=	"\033[32;5m"
KB			=	"\033[34;5m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
CLR			=	printf "\r%40c\r" " "

MKODIR		=	if [ ! -d $(ODIR) ]; then \
			/bin/mkdir -p $(ODIR); \
			/bin/mkdir -p objs/ft_io; \
			/bin/mkdir -p objs/ft_lst; \
			/bin/mkdir -p objs/ft_mem; \
			/bin/mkdir -p objs/ft_str; \
			/bin/mkdir -p objs/ft_hash; \
			/bin/mkdir -p objs/ft_bin; \
			/bin/mkdir -p objs/ft_printf; fi

CMP			=	if [ ! -e .cmp ]; then \
			echo $(Y)Compiling $(X)the $(B)Libft $(X)files...$(Y); \
			if [ "$(DEBUG)" == "-g" ]; then \
			echo \($(R)Debugging $(G)activated$(Y)\); fi; \
			touch .cmp; fi
