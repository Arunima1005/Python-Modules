MAKEFLAGS += --no-print-directory

GREEN		= $(shell printf "\033[0;32m")
GREY			= $(shell printf "\033[0;90m")
RED			= $(shell printf "\033[0;31m")
RESET		= $(shell printf "\033[0m")
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -Iinclude -Ilibft
RM          = rm -f
LIBFT_DIR   = libft
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR  = ft_printf
SRC         = push_swap.c stack_utils.c push_swap_utlis.c free_memory_utlis.c bench_utils.c sort_algo.c sort_algo_2.c linear_time.c linear_time_utils.c\
              operation/pa.c operation/pb.c \
              operation/ra.c operation/rb.c operation/rr.c \
              operation/rra.c operation/rrb.c operation/rrr.c \
              operation/sa.c operation/sb.c operation/ss.c

OBJS        = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREY)push_swap: -o files $(GREEN)created$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C libft clean
	@$(RM) $(OBJS)
	@echo "$(GREY)push_swap: all object files were $(RED)deleted $(RESET)"	

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean
	@echo "$(GREY)push_swap: $(NAME) and libft.a were $(RED)deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
