# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:43:37 by isel-jao          #+#    #+#              #
#    Updated: 2020/10/22 16:13:23 by isel-jao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS_DIR	=	./srcs/
OBJ_DIR		=	./objs/
INC_DIR		=	./includes/

SRCS	= 	main.c 
SRCS	+=	render_walls.c 
SRCS	+=	tools.c 
SRCS	+=	parse_map.c 
SRCS	+=	parse.c 
SRCS	+=	table_utils.c 
SRCS	+=	parse_utils1.c 
SRCS	+=	sprite.c 
SRCS	+=	bmp.c 
SRCS	+=	check_utils.c 
SRCS	+=	check.c 
SRCS	+=	ft_error.c 
SRCS	+=	key_handle.c 
SRCS	+=	init.c 
SRCS	+=	wallcast.c 
SRCS	+=	minimap_tools.c 
SRCS	+=	minimap.c 


OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC			=	$(addprefix -I,$(INC_DIR))

libft		=	libft/libft.a

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(INC_DIR)*.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


all:
	mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME) --no-print-directory

make_libft:
	make -C libft/

make_printf:
	make -C printf/

$(NAME): $(OBJ) $(INC_DIR) make_libft make_printf
	$(CC) $(CFLAGS) $(OBJ) -I /usr/local/include.c ./libft/libft.a ./printf/libftprintf.a -lmlx -framework OpenGL -framework AppKit -I  $(INC) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C libft/
	$(MAKE) clean -C printf/