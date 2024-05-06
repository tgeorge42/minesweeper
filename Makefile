NAME = demineur
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD
HEADERS = -I ./include
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = main.c \
		draw/draw.c \
		init/get_pics1.c init/init_defined_map.c init/init.c \
		utils/utils.c utils/keyboard_mouse.c utils/free_utils.c


SRC_PATH = srcs/
MY_SOURCES := $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(MY_SOURCES:.c=.o)
MY_OBJECTS := $(addprefix build/, $(OBJ))
RM = rm -rf
DEPS := $(MY_OBJECTS:.o=.d)
MLX_PATH = mlx_linux/
MLX_LIB = $(MLX_PATH)libmlx.a

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		@make -sC $(MLX_PATH) all
		@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LFLAGS) -o $(NAME)

clean:
		@make -C $(MLX_PATH) clean
		rm -rf build/srcs
		rm -rf build
		@$(RM) $(MY_OBJECTS)
		@$(RM) $(DEPS)

fclean: clean
		@$(RM) $(NAME)

re: fclean $(NAME)

build:
	mkdir build
	mkdir build/srcs
	mkdir build/srcs/draw
	mkdir build/srcs/init
	mkdir build/srcs/utils

build/%.o: %.c | build
	@$(CC) $(CFLAGS) $(HEADERS) -I/usr/include -Imlx_linux -c $< -o $@

.PHONY : all clean fclean re libft

-include $(DEPS)
