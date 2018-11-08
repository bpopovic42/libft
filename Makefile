# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 08:42:00 by bopopovi          #+#    #+#              #
#*   Updated: 2018/10/22 18:29:15 by bopopovi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

############################## DIRS ############################################

IDIR		=	includes

SDIR		=	srcs

ODIR		=	objs

IODIR		=	ft_io

LSTDIR		=	ft_lst

MEMDIR		=	ft_mem

STRDIR		=	ft_str

HASHDIR		=	ft_hash

BINDIR		=	ft_bin

PTFDIR		=	ft_printf

############################## SRCS ############################################

# **************************************************************************** #
# Input/Output :

IO_FILES	=	$(addprefix $(IODIR)/, \
			ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
			ft_putstr_npr.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_print_memory.c ft_print_bits.c get_next_line.c)

# **************************************************************************** #
# Lists :

LST_FILES	=	$(addprefix $(LSTDIR)/, \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_lstpush.c ft_dlstnew.c ft_dlstdel.c \
			ft_dlstdelone.c ft_dlstpop.c ft_dlstpush.c ft_dlstadd.c)

# **************************************************************************** #
# Memory :

MEM_FILES	=	$(addprefix $(MEMDIR)/, \
			ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
			ft_memdel.c ft_memdup.c)

# **************************************************************************** #
# Strings :

STR_FILES	=	$(addprefix $(STRDIR)/, \
			ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c \
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
			ft_strtoupper.c ft_strcasestr.c ft_strcasenequ.c ft_atol.c)

# **************************************************************************** #
# Hash :

HASH_FILES	=	$(addprefix $(HASHDIR)/, \
			ft_hashnew.c ft_hashpop.c ft_hashpush.c ft_hashdel.c \
			ft_hashget.c ft_hashadd.c)

# **************************************************************************** #
# Binary :

BIN_FILES	=	$(addprefix $(BINDIR)/, \
			ft_toggle_bit.c ft_is_bit_set.c)

# **************************************************************************** #
# Printf :

PTF_FILES	=	$(addprefix $(PTFDIR)/, \
			ft_printf.c ft_printf_buffer.c ft_printf_tools.c \
			ft_printf_print_arg.c ft_printf_get_flags.c ft_vprintf.c \
			ft_printf_type_int.c ft_printf_type_str.c ft_printf_type_char.c \
			ft_printf_type_dbl.c ft_printf_type_ldbl.c ft_printf_type_others.c \
			ft_printf_dtoa.c ft_printf_ldtoa.c ft_printf_color.c)

SRCS		=	$(IO_FILES) $(LST_FILES) $(MEM_FILES) $(STR_FILES) \
				$(HASH_FILES) $(BIN_FILES) $(PTF_FILES)

############################## OBJS ############################################

OBJS		=	$(SRCS:.c=.o)

OBJ			=	$(addprefix $(ODIR)/, $(OBJS))

############################## INCS ############################################

HEADERS		=	libft.h ft_printf.h

LFT			=	$(addprefix $(IDIR)/, $(HEADERS))

INCS		=	$(addprefix -I,$(IDIR)/)

############################## COMP ############################################

CC			=	gcc

CFLAGS		=	$(DEBUG) -Wall -Wextra -Werror

############################## RULES ###########################################

all			:	$(NAME)

$(NAME)		:	$(OBJ)
			@ar rcs $(NAME) $(OBJ)
			@$(CLR)
			@echo $(UP) $(CUT) $(UP)
			@/bin/rm -f .cmp
			@echo $(BG)[$(BLB)LIBFT $(BG)COMPILED$(BG)]$(X)


$(ODIR)/%.o	:	$(SDIR)/%.c $(LFT)
			@$(CMP)
			@$(MKODIR)
			@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
			@$(CLR)
			@echo -n $@

clean		:
			@echo $(R)Cleaning $(X)the $(B)Libft $(X)files...
			@/bin/rm -f $(OBJ)
			@/bin/rm -rf $(ODIR)
			@echo $(UP) $(CUT) $(UP)
			@echo $(BG)[$(BLB)LIBFT $(BG)CLEANED$(BG)]$(X)

fclean		:	clean
			@/bin/rm -f $(NAME)

re			:	fclean all

############################## UTIL ############################################

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
			echo $(BY)Compiling $(B)Libft $(X)files...$(BY); \
			touch .cmp; fi

############################## DISPLAY #########################################

BY			=	"\033[1;33m"
BR			=	"\033[1;31m"
BG			=	"\033[1;32m"
BLB			=	"\033[1;36m"
BP			=	"\033[1;35m"
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[0;32m"
B			=	"\033[34m"
P			=	"\033[35m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
CLR			=	printf "\r%40c\r" " "
CUT_UP		=	$(UP)$(CUT)$(UP)

############################## OTHER ###########################################

.PHONY		:	all, clean, fclean, re
