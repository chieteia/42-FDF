NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror
RM			=	rm -f
RM_DIR		=	rm -rf
SRCS_FILES	=	ft_atoi.c \
				ft_atoi_base.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isspace.c \
				ft_isdigit.c \
				ft_isdigit_base.c \
				ft_isnumber.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_malloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_safe_free.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c
SRCS_DIR	=	./sources
SRCS		=	$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/,$(SRCS_FILES:.c=.o))
OBJ_DIR		=	./objects

RED			=	"\033[31m"
GREEN		=	"\033[32m"
YELLOW		=	"\033[33m"
RESET		=	"\033[0m"

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo $(YELLOW)"@@@@@ libft.a created @@@@@"$(RESET)

## オブジェクトファイルの主力先を変えている
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo $(GREEN)"Creating: $@"$(RESET)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./includes/ -c -o $@ $<

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@echo $(RED)"REMOVE LIBFT OBJECT FILES"$(RESET)

fclean:	clean
	@$(RM) $(NAME)
	@echo $(RED)"REMOVE $(NAME)"$(RESET)

re:	fclean all