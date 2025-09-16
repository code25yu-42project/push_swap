# Project names
NAME        = push_swap
B_NAME      = checker

# Compiler
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g

# Directories
INC_DIR     = includes
SRC_DIR     = srcs
LIBFT_DIR   = libft
LIBFT_INC   = $(LIBFT_DIR)/includes
LIBFT_A     = $(LIBFT_DIR)/libft.a

# Includes
INCLUDES    = -I$(INC_DIR) -I$(LIBFT_INC)

# Source files
## Common sources
COMMON_SET_FILES = \
	chk_cond.c chk_idx_argv.c free.c idx_argv.c \
	set_argcv.c set_chk_center.c set_lst_stack.c

COMMON_CMD_FILES = \
	full_empty.c push_ab.c push_pop.c \
	rev_rotate_ab.c rotate_ab.c swap_ab.c swap_rotate.c

## push_swap specific
PUSH_QS_FILES = \
	center.c exchandle.c loop.c pivot.c \
	print_cmd.c print_cmd_cmp.c print_cmd_exchandle.c stack_ab.c

PUSH_SWAP_FILES = \
	$(addprefix common/set/, $(COMMON_SET_FILES)) \
	$(addprefix common/cmd/, $(COMMON_CMD_FILES)) \
	$(addprefix push_swap/quick_sort/, $(PUSH_QS_FILES)) \
	push_swap/main.c

## checker specific
CHECKER_FILES = \
	$(addprefix common/set/, $(COMMON_SET_FILES)) \
	$(addprefix common/cmd/, $(COMMON_CMD_FILES)) \
	checker/sort_cmd/stack_sort_cmd.c \
	checker/main.c

# Full paths
M_SRCS = $(addprefix $(SRC_DIR)/, $(PUSH_SWAP_FILES))
B_SRCS = $(addprefix $(SRC_DIR)/, $(CHECKER_FILES))

M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

# Rules
all: $(LIBFT_A) $(NAME)

$(NAME): $(M_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -L$(LIBFT_DIR) -lft -o $@

checker: $(LIBFT_A) $(B_NAME)

test: $(NAME) checker
	chmod +x ./tests/test.sh
	./tests/test.sh

$(B_NAME): $(B_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -L$(LIBFT_DIR) -lft -o $@

## libft build
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

## Object file build
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(M_OBJS) $(B_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re test
