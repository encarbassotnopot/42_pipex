SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = 

HDR_FLAGS = -I $(LIBFT) -I $(FT_PRINTF)
LIB_FLAGS = -rpath $(LIBFT) -L $(LIBFT) -lft -rpath $(FT_PRINTF) -L $(FT_PRINTF) -lftprintf
BUILD_DIR = build

NAME = pipex
CFLAGS = -Wall -Wextra -Fsanitize=address

CC = clang
LIBFT = $(CURDIR)/libft
FT_PRINTF = $(CURDIR)/ft_printf

all: $(NAME)

libft:
	make -C $(LIBFT)

ft_printf:
	make -C $(FT_PRINTF)

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(HDR_FLAGS)

$(BUILD_DIR):
	mkdir -p $@

$(NAME): libft ft_printf $(OBJ_FILES) 
	$(CC) $(OBJ_FILES) $(LIB_FLAGS) $(HDR_FLAGS) -o $(NAME)

clean reclean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) clean

re: fclean all reclean

.PHONY: all clean fclean re libmlx libft ft_printf
