NAME		=	fdf
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror

INC_DIR		=	./
SRCS_DIR	=	sources/
OBJ_DIR		=	objects/
LIB_DIR		=	libft/

HEADERS		=	$(INC_DIR)includes/ $(LIB_DIR)includes/ $(MLX_DIR)
LIBFT		=	$(LIB_DIR)libft.a
INCLUDES	=	$(addprefix -I, $(HEADERS))
ifeq ($(shell uname), Darwin)
	MLX_DIR		=	minilibx_macos/
	LIBMLX		=	$(MLX_DIR)libmlx.a
	LXFLAGS		=	-framework OpenGL -framework AppKit
else
	MLX_DIR		=	minilibx-linux/
	LIBMLX		=	$(MLX_DIR)libmlx_Linux.a
	LXFLAGS		=	-lXext -lX11 -lm
endif
RM			=	rm -f
RM_DIR		=	rm -rf

SRCS_FILES	=	check_utils.c \
				color_utils.c \
				control_utils.c \
				control.c \
				draw_utils.c \
				draw.c \
				init_utils.c \
				init.c \
				main.c \
				math_utils.c \
				move_utils.c \
				new_data.c \
				projection.c \
				random_utils.c \
				read_map.c

OBJ_FILES	=	$(SRCS_FILES:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

RED			=	"\033[31m"
GREEN		=	"\033[32m"
YELLOW		=	"\033[33m"
RESET		=	"\033[0m"

$(NAME): $(LIBFT) $(OBJS) $(LIBMLX)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(LIBMLX) $(LXFLAGS)
	@echo $(YELLOW)"@@@@@ fdf compiling done @@@@@"$(RESET)

$(LIBFT):
	@make -C $(LIB_DIR)

$(LIBMLX):
	@make -C $(MLX_DIR)
	@echo $(YELLOW)"@@@@@ libmlx.a created @@@@@"$(RESET)

## オブジェクトファイルの主力先を変えている
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@echo $(GREEN)"Creating: $@"$(RESET)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(INCLUDES) -c $< -o $@

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo $(RED)"REMOVE OBJECT FILES"$(RESET)

fclean:	clean
	@$(RM) $(LIBFT)
	@echo $(RED)"REMOVE $(LIBFT)"$(RESET)
	@$(RM) $(NAME)
	@echo $(RED)"REMOVE $(NAME)"$(RESET)

re:	fclean all

bonus: all

.PHONY: all clean fclean re bonus