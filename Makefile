# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 17:04:47 by efriedma          #+#    #+#              #
#    Updated: 2018/05/22 13:22:38 by efriedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -g -Wall -Wextra -Werror

NAME = libftprintf.a

TRASH = rm -f

LIBFT := libft/

SRC = handle/handle_flags.c \
	  handle/ft_parse.c \
	  base/ft_itoabase.c \
	  base/ft_uitoabase.c \
	  print/ft_printf.c \
	  print/ft_print.c \
	  print/ft_print3.c \
	  print/ft_mputstr.c \
	  print/ft_print2.c \
	  print/ft_print_addy.c \
	  print/ft_printint.c \
	  chars/ft_printchr.c \
	  chars/ft_printwchr.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME) libft/libft.a

clean:
	$(TRASH) $(OBJ)

fclean: clean
	$(TRASH) $(NAME)

re: fclean all

#   @$(MAKE) -C $(LIBFT) clean
#   @$(MAKE) -C $(LIBFT) fclean
#   @$(MAKE) -C $(LIBFT)
