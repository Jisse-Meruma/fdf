### VAR #######################################################
NAME		:=	fdf

DEBUGGING	?=

LIBS		:=	./libft/libft.a
MLX			?=	./MLX42

HEADER		:=	-I libft -I includes -I $(MLX)/includes
MLXLIB		:= $(MLX)/libmlx42.a
HEADERS		:=	libft/libft.h
OBJ_DIR		:=	./obj
SRC_DIR 	:=	./src

### UTILS #####################################################
CFLAGS	:=	-Wall -Wextra -g
RM		:=	rm -rf

SRC 	:=	main.c				\
			map.c				\
			list_manipulation.c	\
			mlxshizzel.c 		\
			draw_line.c 		\
			render_grid.c 		\
			color.c				\
			exit.c

OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

## BON_SRC :=

## BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)

## Regular Colors ##############################################
Color_Off	=	"\033[0m"			# Text Reset
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

### EXEC #######################################################

ifdef DEBUG
	MLXLIB += -fsanitize=address
	DEBUGGING += DEBUG=1
endif

ifdef LINUX
	MLXLIB += -lglfw -ldl -pthread -lm
endif

ifndef LINUX 
	MLXLIB += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
endif

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(MLX) $(DEBUGGING)

$(NAME): $(OBJ)
	@echo $(Yellow) Building.. 🏠$(Color_Off)
	@echo -----------------------
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBS) $(MLXLIB) -o $(NAME) 
	@echo $(Green) Complete ✅ $(Color_Off)
	@echo -----------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo $(Purple) Compiling.. 🧱 $< $(Color_Off)
	@echo -----------------------
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir $@

clean:
	@echo $(Cyan) Sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(MAKE) -C libft clean
	@$(MAKE) -C $(MLX) clean
	@$(RM) $(OBJ) $(BON_OBJ)

fclean:
	@echo $(Red) Thorough sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(MAKE) -C libft fclean
	@$(MAKE) -C $(MLX) fclean
	@$(RM) $(NAME) $(OBJ) $(BON_OBJ)

re: fclean all

.PHONY: clean all fclean re libmlx,