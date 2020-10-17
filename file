NAME		=	cub3d

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
LFLAGS		=	
MEMFLAGS	=	-ggdb -fsanitize=address 

SRCS_DIR	=	./sources/
OBJ_DIR		=	./objects/
INC_DIR		=	./includes/

SRCS		=	cub_main.c
SRCS		+=	cub_gnl.c
SRCS		+=	cub_error.c
SRCS		+=	cub_init.c
SRCS		+=	cub_free.c
SRCS		+=	map_fill.c
SRCS		+=	map_color.c
SRCS		+=	map_draw.c
SRCS		+=	map_dir.c
SRCS		+=	map_leak.c
SRCS		+=	key_init.c
SRCS		+=	ray_init.c
SRCS		+=	ray_shift.c
SRCS		+=	tex_init.c
SRCS		+=	tex_floor.c
SRCS		+=	spr_calc.c
SRCS		+=	spr_utils.c
SRCS		+=	img_init.c

OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC			=	$(addprefix -I,$(INC_DIR))

libft_cub		=	libft_cub/libft_cub.a

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf


$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(INC_DIR)*.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:
	mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME) --no-print-directory

make_libft_cub:
	make -C libft_cub/

make_mlx:
	make -C minilibx_macos/

$(NAME): $(OBJ) $(INC_DIR) make_libft_cub make_mlx
	$(CC) $(CFLAGS) $(OBJ) -I ./minilibx_macos/mlx.h ./minilibx_macos/libmlx.a ./libft_cub/libft_cub.a -framework OpenGL -framework AppKit -I ./libft_cub/includes $(INC) -o $(NAME)
	
clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C libft_cub/
	$(MAKE) clean -C minilibx_macos/

fclean: clean
	$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM
	$(MAKE) fclean -C libft_cub/

fclean_wolf: clean
	$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM

re:
	$(MAKE) fclean --no-print-directory
	$(MAKE) all --no-print-directory

bin: re clean


.SILENT: make_mlx
#.PRECIOUS:
.PHONY: all clean fclean re bin make_libft_cub