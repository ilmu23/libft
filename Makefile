# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 15:26:18 by ivalimak          #+#    #+#              #
#    Updated: 2023/12/28 21:43:32 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
#CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	ft_atoi.c \
			ft_atol.c \
			ft_free.c \
			ft_bzero.c \
			ft_alloc.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isinteger.c \
			ft_contains.c \
			ft_itoa.c \
			ft_uitoa.c \
			ft_intlen.c \
			ft_uintlen.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_putnbr_fd.c \
			ft_putunbr_fd.c \
			ft_putxnbr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_splitstrs.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strremove.c \
			ft_subescstr.c \
			ft_strupper.c \
			ft_strlower.c \
			ft_strsjoin.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strclen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strrev.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_format.c \
			ft_printf.c \
			ft_putc.c \
			ft_putd.c \
			ft_putp.c \
			ft_puts.c \
			ft_putu.c \
			ft_putx.c \
			printf_utils.c \
			get_next_line.c \
			gnl_utils.c \
			ft_clean.c \
			ft_sweep.c \
			ft_mark.c \
			ft_obj.c \
			ft_vm.c

OBJS	= $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo Creating libft...
	@ar -crs $(NAME) $(OBJS)

%.o: %.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
