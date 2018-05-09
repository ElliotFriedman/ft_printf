# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efriedma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 17:04:47 by efriedma          #+#    #+#              #
#    Updated: 2018/05/08 22:27:41 by efriedma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

TRASH = rm -f

LIBFT := libft/

SRC = handle/handle_flags.c \
	  handle/ft_parse.c \
	  base/ft_itoabase.c \
	  base/ft_uitoabase.c \
	  base/ft_matoi.c \
	  print/ft_printf.c \
	  print/ft_print.c \
	  print/ft_mputstr.c \
	  print/ft_print2.c \
	  chars/ft_printchr.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	$(TRASH) $(OBJ)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(TRASH) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all
