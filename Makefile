NAME =	so_long

INC =	include

SRCS =	srcs/main.c \
	srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/ft_split.c \
	srcs/parsing.c \
	srcs/game.c \
	srcs/ft_itoa.c \
	srcs/check_walls.c \
	srcs/pce.c \
	srcs/mlx_setup.c \
	srcs/keys.c \
	srcs/init_xpm.c \
	srcs/display.c


MLX = mlx_linux

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -g -Werror -Wextra -Wall
FLAGS_MLX=-L/usr/lib -lXext -lX11 -lm

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS) 
	-make -C mlx_linux
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux $(FLAGS_MLX) -Imlx_linux -o $(NAME) 

clean :
	$(RM) $(OBJS)

fclean : clean
	-make clean -C mlx_linux 
	$(RM) $(NAME)

re : fclean all

bonus : all
