NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_PATH = ./

SRC = ./src/fill_list.c \
	./src/actions_file_folder.c \
	./src/argv_parsing.c \
	./src/display_l.c \
	./src/error_options.c \
	./src/pointer_functions.c \
	./src/display_tools.c \
	./src/size.c \
	./src/recursion.c \
	./src/time_functions.c \
	./src/ft_ls.c \
	./src/sort.c \

GREEN	=\033[0;32m

OBJ=$(SRC:.c=.o)

INC		= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) -L libft/ -lft
	cd ./libft && $(MAKE)

%.o: %.c
	@printf "$(GREEN)Created $@\n"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	 cd ./libft && $(MAKE) clean

fclean: clean
	@/bin/rm -f $(NAME)


re: fclean all

.PHONY : clean fclean all re
