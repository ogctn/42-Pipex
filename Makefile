CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex
HEADER = pipex.h
SRC = ft_arg_checker.c ft_child_fd.c ft_error.c ft_path_finder.c main.c
OBJ = $(SRC:c=o)

all: $(NAME)

%.o: %.c
	@echo "Generating $(NAME) objects"
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@echo "Done"
	@echo "-----------------------------"
	@echo "Compiling pipex"
	@make -C Libft	
	@$(CC) $(OBJ) Libft/libft.a $(CFLAGS) -o $(NAME)
	@echo "$(NAME) is ready to use!"
	@echo "Done"
	@echo "-----------------------------"

clean:
	@echo "-----------------------------"
	@echo "Deleting $(NAME) objects"
	@make clean -C Libft
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting $(NAME) executable"
	@rm -f $(NAME)
	@echo "Done"
	@echo "-----------------------------"

re: fclean all

.PHONY: clean fclean re