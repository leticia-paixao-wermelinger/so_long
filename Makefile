
NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror -g $(DEB)

SRCS = main.c map.c declare_structs.c map_validations.c map_validations2.c map_validations3.c playable_map.c clear_struct.c hooks.c img.c play.c

OBJS = ${SRCS:.c=.o}

LIBFT = libs/libft/libft.a
MINILIBX = libs/minilibx/libmlx.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo "so_long ready to be used"

$(LIBFT): 
	make -s -C libs/libft
	@echo "libft ready to be used"

$(MINILIBX):
	make -s -C libs/minilibx
	@echo "minilibx ready to be used"

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME) -Llibs/minilibx -lmlx -lX11 -lXext

clean:
	make clean -C libs/libft
	make clean -C libs/minilibx
	rm -f $(OBJS)
	@echo "Objects deleted"

fclean: clean
	make fclean -C libs/libft
	rm -f $(NAME)
	@echo "All cleaned"

re: fclean all

run: re
	./so_long "maps/map.ber"

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map.ber

sanitize: fclean $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME) -Llibs/minilibx -lmlx -lX11 -lXext -fsanitize=address
	./so_long "maps/map.ber"
