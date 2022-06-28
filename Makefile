NAME=gen_map
LIBFT=libft/libft.a
INCLUDES=inc
SRC=src/main.c src/init_file.c src/utilities.c
OBJ=main.o init_file.o utilities.o
MSJ=echo "./gen_map (give a name ex. arda) (width) (height) ((optional) (collectibles) (exits))"

all: fclean $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $? $(LIBFT) -lm
	@mkdir object_files
	@mkdir maps
	@mv *.o ./object_files/
	@$(MSJ)

$(OBJ): $(SRC)
	@make -C libft
	@gcc -c $? -I $(INCLUDES)

clean:
	@rm -rf object_files/
	@rm -rf maps/
	@make clean -C libft

fclean:
	@make clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@rm -rf *.ber

re:
	@make fclean
	@make -C ./

.PHONY: all re clean fclean
