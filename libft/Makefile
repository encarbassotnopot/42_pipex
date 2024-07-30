SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_memchr.c ft_memchr_idx.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar_fd_st.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putstr_fd_st.c ft_raw_atoi.c ft_raw_atoi_fwd.c ft_split.c ft_strchr.c ft_strchr_idx.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_sttoa_base.c ft_substr.c ft_tolower.c ft_toupper.c ft_utoa_base.c ft_utoa.c ft_strbeginswith.c ft_free_arr.c ft_strjoinc.c ft_strcmp.c
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = libft.h 

BUILD_DIR = build

NAME = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fPIC

ARFLAGS = rcs

all: $(NAME).so $(NAME).a

$(NAME).so: $(OBJ_FILES)
	$(CC) -shared -o $@ $?

$(NAME).a: $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $?

$(BUILD_DIR)/%.o: %.c $(HDR_FILES) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean reclean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

info:
	$(info $(SRC_FILES))

.PHONY: all clean fclean reclean re info
