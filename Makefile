FDF			=	fdf
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG_FLAGS	=	-Wall -Wextra -Werror

INC_DIR		=	./
SRCS_DIR	=	sources/
OBJ_DIR		=	objects/
LIB_DIR		=	libft/
MLX_DIR		=	minilibx_macos/

HEADERS		=	$(INC_DIR)includes/ $(LIB_DIR)includes/ $(MLX_DIR)
LIBFT		=	$(LIB_DIR)libft.a
LIBMLX		=	$(MLX_DIR)libmlx.a
INCLUDES	=	$(addprefix -I, $(HEADERS))
LXFLAGS		=	-framework OpenGL -framework AppKit
RM			=	rm -f
RM_DIR		=	rm -rf

SRCS_FILES	=	main2.c\
				draw.c\
				control.c\
				math_utils.c\
				init_utils.c\
				read_map.c\
				terminate.c\
				utils.c

OBJ_FILES	=	$(SRCS_FILES:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

.PHONY: all clean fclean re db

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

$(LIBMLX):
	@make -C $(MLX_DIR)
	@echo $(YELLOW)"@@@@@ libmlx.a created @@@@@"$(RESET)

## オブジェクトファイルの主力先を変えている
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c includes/fdf.h
	@echo $(GREEN)"Creating: $@"$(RESET)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo $(RED)"REMOVE OBJECT FILES"$(RESET)

fclean:	clean
	@$(RM) $(LIBFT)
	@echo $(RED)"REMOVE $(LIBFT)"$(RESET)
	@$(RM) $(FDF)
	@echo $(RED)"REMOVE $(FDF)"$(RESET)

re:	fclean all

db: $(LIBFT) $(OBJS) $(LIBMLX)
	@$(CC) $(DEBUG_FLAGS) -o $(FDF) $(OBJS) $(LIBFT) $(LIBMLX) $(LXFLAGS)
	@echo $(YELLOW)"@@@@@ fdf compiling done @@@@@"$(RESET)