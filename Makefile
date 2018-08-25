NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_PATH = ./

INC_DIR = ./ft_ls.h

SRC_PATH = ./src/

SRC = fill_list.c \
	actions_file_folder.c \
	argv_parsing.c \
	display_l.c \
	error_options.c \
	pointer_functions.c \
	display_tools.c \
	size.c \
	recursion.c \
	time_functions.c \
	ft_ls.c \
	sort.c \

GREEN = \033[0;32m

SRC_LS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC_LS:.c=.o)

INC	= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	@$(CC) $(OBJ) -o $(NAME) -L ./libft/ -lft

%.o: %.c $(INC_DIR)
	@printf "$(GREEN)Created $@\r"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	$(MAKE) fclean -C libft


re: fclean all

.PHONY : clean fclean all re
