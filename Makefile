NAME = push_swap

FILES = main.c check_args.c sort_check.c sort_op.c node_op.c

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = include/
OBJ_DIRS = obj/
LIBFT_PATH = lib/libft/
LIBFT_INC = $(LIBFT_PATH)include/

LIBFT = $(LIBFT_PATH)libft.a

CC	  = cc
CFLAGS	  = -Wall -Wextra -Werror
CFLAGS	  += -I $(INC_PATH) -I $(LIBFT_INC) -g

LIB_FLAGS = -lft

RM = rm -rf

SRC	 = $(addprefix $(SRC_PATH), $(FILES))
OBJ	 = $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

COLOR_RED = \e[0;31m
COLOR_GREEN = \e[0;32m
COLOR_YELLOW = \e[0;33m
COLOR_BLUE = \e[0;34m
COLOR_PURPLE = \e[0;35m
COLOR_CYAN = \e[0;36m
COLOR_WHITE = \e[0;37m

all : $(NAME)

$(OBJ_DIRS):
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ_DIRS) $(OBJ) $(LIBFT)
	@printf "$(COLOR_GREEN)Making $(COLOR_PURPLE)$(NAME)$(COLOR_WHITE)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) $(LIB_FLAGS)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

clean :
	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)Libft$(COLOR_WHITE) objects...\n"
	@make -C $(LIBFT_PATH) clean
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)$(NAME)$(COLOR_WHITE) objects...\n"
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIRS)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

fclean : clean
	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)Libft\n$(COLOR_WHITE)"
	@make -C $(LIBFT_PATH) fclean
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"


	@printf "$(COLOR_RED)Cleaning $(COLOR_PURPLE)$(NAME)\n$(COLOR_WHITE)"
	$(RM) $(NAME)
	@printf "$(COLOR_GREEN)Done!\n$(COLOR_WHITE)"

re : fclean all

.PHONY: all clean fclean re