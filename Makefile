NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
LIBFT_DIR 	= libft
LIBFT_LIB 	= $(LIBFT_DIR)/libft.a
INCLUDE 	= -Iinclude -I$(LIBFT_DIR)

SRCS = 	src/pipex.c \
		src/pipex_utils.c

OBJS = $(SRCS:src/%.c=obj/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m
CHECK = \033[0;34m✔\033[0m
BOLD = \033[1m

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "$(CHECK) $(BOLD)Executable '$(NAME)' built successfully!$(RESET)\n"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(BOLD)$(BLUE)  ⚙️  How to run '$(NAME)':$(RESET)"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(GREEN)  • Usage:$(RESET)"
	@echo "    $(BOLD)./$(NAME) infile \"cmd1 [args]\" \"cmd2 [args]\" outfile$(RESET)\n"
	@echo "$(GREEN)  • Example:$(RESET)"
	@echo "    $(BOLD)./$(NAME) infile \"ls -l\" \"grep '.c'\" outfile$(RESET)\n"
	@echo "$(GREEN)  • Behaviour:$(RESET) Equivalent to: \"< infile cmd1 | cmd2 > outfile\"\n"
	@echo "$(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)\n"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@$(RM) -r obj
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "$(RED)Fully cleaned everything.$(RESET)"
re: fclean all

.PHONY: all clean fclean re run valgrind
