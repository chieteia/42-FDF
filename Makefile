FDF			=	fdf
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	$(addprefix -I, $(HEADERS))
HEADERS		=	$(INC_DIR)includes/ $(LIB_DIR)includes/
LIBFT		=	$(LIB_DIR)libft.a

RM			=	rm -f
RM_DIR		=	rm -rf

SRCS_FILES	=	main.c\
				init_master.c\
				read_map.c\
				terminate.c\
				utils.c

OBJ_FILES	=	$(SRCS_FILES:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC_DIR		=	./
SRCS_DIR	=	sources/
OBJ_DIR		=	objects/
LIB_DIR		=	libft/

.PHONY: all clean fclean re debug

all: $(FDF)

RED			=	"\033[31m"
GREEN		=	"\033[32m"
YELLOW		=	"\033[33m"
RESET		=	"\033[0m"

$(FDF): $(LIBFT) $(OBJS)
	@$(CC) -o $(FDF) $(OBJS) -L$(LIB_DIR) -lft
	@echo $(YELLOW)"@@@@@ fdf compiling done @@@@@"$(RESET)

$(LIBFT):
	@make -C $(LIB_DIR)

## オブジェクトファイルの主力先を変えている
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@echo $(GREEN)"Creating: $@"$(RESET)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo $(RED)"REMOVE OBJECT FILES"$(RESET)

fclean:	clean
	@$(RM) $(LIBFT)
	@echo $(RED)"REMOVE $(LIBFT)"$(RESET)
	@$(RM) $(FDF)
	@echo $(RED)"REMOVE $(FDF)"$(RESET)

re:	fclean all

debug: fclean $(LIBFT) $(OBJS)
	@$(CC) -g -o $(FDF) $(OBJS) -L$(LIB_DIR) -lft
	@echo $(YELLOW)"@@@@@ fdf compiling done @@@@@"$(RESET)