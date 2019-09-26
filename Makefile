# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmansou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 14:23:41 by ahmansou          #+#    #+#              #
#    Updated: 2019/09/26 14:23:43 by ahmansou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ahmansou.filler

SRCS = src/main.c src/get_assets.c \
		src/get_next_line.c src/misc.c \
		src/heat_map.c src/piece_proc.c \
		src/attack.c

OBJS = $(SRCS:.c=.o) 

FLG = -Wall -Werror -Wextra

$(NAME): $(OBJS)	
	make -C libft
	make -C ft_printf
	gcc -o $(NAME) $(FLG) $(OBJS) libft/libft.a	ft_printf/libftprintf.a
	
clean:
	make clean -C libft	
	make clean -C ft_printf	
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf	
	rm -f $(NAME) 

re: fclean all

all : $(NAME)
