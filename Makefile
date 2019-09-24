NAME = ahmansou.filler

SRCS = src/main.c src/get_assets.c \
		src/get_next_line.c src/misc.c \
		src/heat_map.c src/piece_proc.c \
		src/attack.c

# OBJS = obj/main.o obj/get_assets.o obj/get_next_line.o obj/misc.o

OBJS = $(SRCS:.c=.o) 

FLG = -Wall -Werror -Wextra

$(NAME): $(OBJS)	
	make -C libft	
	gcc -o $(NAME) $(FLG) $(OBJS) libft/libft.a	
	
clean:
	make clean -C libft	
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) 

re: fclean all

all : $(NAME)
