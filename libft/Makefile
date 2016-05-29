# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 23:00:32 by sguillia          #+#    #+#              #
#    Updated: 2016/02/12 22:08:20 by sguillia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = libft.a

CC_FLAGS = -Wall -Wextra -Werror -O3

C_FILES = get_next_line.c \
		  ft_abs.c \
		  ft_atoi.c \
		  ft_atoi_base.c \
		  ft_bzero.c \
		  ft_check_malloc.c \
		  ft_expo.c \
		  ft_free_tab.c \
		  ft_get_bits.c \
		  ft_is42space.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_islower.c \
		  ft_isprint.c \
		  ft_isspace.c \
		  ft_isupper.c \
		  ft_itoa.c \
		  ft_itoa_base.c \
		  ft_lstadd.c \
		  ft_lstaddend.c \
		  ft_lstat.c \
		  ft_lstbeforelast.c \
		  ft_lstcount.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstlast.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lst_strlen.c \
		  ft_lst_to_str.c \
		  ft_maxof.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmem_type1.c \
		  ft_memmem_type2.c \
		  ft_memmove.c \
		  ft_memrchr.c \
		  ft_memset.c \
		  ft_minof.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_stralloc.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strndup.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strrealloc.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtolower.c \
		  ft_strtoupper.c \
		  ft_strtrim.c \
		  ft_tablen.c \
		  ft_tab_strlen.c \
		  ft_tab_to_str.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_wchar_numbytes.c \
		  ft_wchar_to_str.c \
		  ft_wstr_strlen.c \
		  ft_wstr_to_str.c


FT_PRINTF_C_FILES = \
		  ft_printf/add_prefix.c				\
		  ft_printf/adjust_left.c				\
		  ft_printf/adjust_right.c				\
		  ft_printf/check_field_width.c			\
		  ft_printf/error.c						\
		  ft_printf/flag_zero_d.c				\
		  ft_printf/flag_zero_ouxpb.c			\
		  ft_printf/flag_zero_s.c				\
		  ft_printf/ft_asprintf.c				\
		  ft_printf/ft_intmaxtoa_base.c			\
		  ft_printf/ft_lltoa_base.c				\
		  ft_printf/ft_lst_freestr.c			\
		  ft_printf/ft_lstprintstr.c			\
		  ft_printf/ft_lstprintstr_fd.c			\
		  ft_printf/ft_printf.c					\
		  ft_printf/ft_printf_fd.c				\
		  ft_printf/ft_printf_buffer_add.c		\
		  ft_printf/ft_sizettoa_base.c			\
		  ft_printf/ft_strjoin3.c				\
		  ft_printf/ft_uintmaxtoa_base.c		\
		  ft_printf/ft_ulltoa_base.c			\
		  ft_printf/get_args.c					\
		  ft_printf/get_n_chars.c				\
		  ft_printf/handle_converted_b.c		\
		  ft_printf/handle_converted_d.c		\
		  ft_printf/handle_converted_nullc.c	\
		  ft_printf/handle_converted_p.c		\
		  ft_printf/handle_converted_s.c		\
		  ft_printf/handle_converted_oux.c		\
		  ft_printf/handle_modulo.c				\
		  ft_printf/handle_nonmodulo.c			\
		  ft_printf/handle_specifier.c			\
		  ft_printf/handle_specifier_b.c		\
		  ft_printf/handle_specifier_c.c		\
		  ft_printf/handle_specifier_d.c		\
		  ft_printf/handle_specifier_p.c		\
		  ft_printf/handle_specifier_r.c		\
		  ft_printf/handle_specifier_s.c		\
		  ft_printf/handle_specifier_oux.c		\
		  ft_printf/handle_precision_b.c		\
		  ft_printf/handle_precision_d.c		\
		  ft_printf/handle_precision_nullc.c	\
		  ft_printf/handle_precision_p.c		\
		  ft_printf/handle_precision_s.c		\
		  ft_printf/handle_precision_oux.c		\
		  ft_printf/handle_unknown_specifier.c	\
		  ft_printf/parse_aliases.c				\
		  ft_printf/parse_argpos.c				\
		  ft_printf/parse_casters.c				\
		  ft_printf/parse_color.c				\
		  ft_printf/parse_options.c				\
		  ft_printf/parse_precision.c			\
		  ft_printf/parse_flags.c				\
		  ft_printf/parse_field_width.c

O_FILES = $(C_FILES:.c=.o)

FT_PRINTF_O_FILES = $(FT_PRINTF_C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES) $(FT_PRINTF_O_FILES)
	ar rc $(NAME) $(O_FILES) $(FT_PRINTF_O_FILES)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(CC_FLAGS) -c -o $@ $^ -I.

clean:
	rm -f $(O_FILES) $(FT_PRINTF_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
