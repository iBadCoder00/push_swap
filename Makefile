GREEN		=		\033[0;32m
RED			=		\033[0;31m
BLACK		=		\033[0;30m
YELLOW		=		\033[1;33m
BLUE		=		\033[0;34m
PURPLE		=		\033[1;95m
END			=		\033[0m


CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror
RM			=		rm -rf
LIBS		=		-L ./libft -lft
LIBFT		=		./libft/libft.a


NAME		=		push_swap
BONUS		=		checker
SRC_SRC		=	\
 
CHECKER_SRC		=	\
					cmd_parsing.c \
					commands.c \
					main.c \
 
PUSH_SWAP_SRC		=	\
					instructions.c \
					main.c \
					parsing.c \
					sort.c \
					sort_utils.c \
					stack.c \
					utils.c \
 
SRC_FILES		=	\
					$(addprefix $(SRC_DIR)/, $(SRC_SRC)) \
					$(addprefix $(PUSH_SWAP_DIR)/, $(PUSH_SWAP_SRC)) \

BONUS_FILES		=	$(addprefix $(CHECKER_DIR)/, $(CHECKER_SRC))
 
OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJ		=	$(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o)) \
					$(filter-out obj/src/push_swap/main.o, $(OBJ))


SRC_DIR		=	src
CHECKER_DIR		=	src/checker
PUSH_SWAP_DIR		=	src/push_swap
INC_DIR		=		include
OBJ_DIR		=		obj


all: $(NAME)

bonus: $(BONUS)

$(LIBFT):
	@make -s -C ./libft

$(BONUS): $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $(BONUS) -fsanitize=address
	@printf "                                   \r"
	@printf "$(GREEN)> BUILDING CHECKER			[✓]$(END)\n"

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) -fsanitize=address
	@printf "                                   \r"
	@printf "$(GREEN)> BUILDING PUSH_SWAP			[✓]$(END)\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@printf "$(YELLOW)> BUILDING $<               \r$(END)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I libft/include -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p obj/src
	@mkdir -p obj/src/checker
	@mkdir -p obj/src/push_swap

clean:
	@make clean -s -C ./libft
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -s -C ./libft
	@$(RM) $(NAME)
	@$(RM) $(BONUS)

re: fclean all

.PHONY: all clean fclean re