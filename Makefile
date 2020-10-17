# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:43:37 by isel-jao          #+#    #+#              #
#    Updated: 2020/10/17 19:39:07 by isel-jao         ###   ########.fr        #
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
	$(MAKE) clean -C minilibx_macos/





























# $(NAME): $(OBJS)
# 	@$(AR) $(NAME) $^
# 	@echo "$(YELLOW)ALL$(NC)"
# %.o : %.c
# 	@$(CC) $(FLAGS) -c $<

# clean:
# 	@rm -f $(OBJS)
# 	@echo "$(YELLOW)cleen$(NC)"
	
# fclean: clean
# 	@rm -f $(NAME)
# 	@echo "$(YELLOW)fcleen$(NC)"
# re: fclean all
# 	@rm -f $(OBJS)
# 	@echo "$(GREEN)ALL DONE$(NC)"
# mac: 
# 	@gcc -I /usr/local/include.c $(SRCS) ./libft/libft.a ./printf/libftprintf.a -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit -o cube3D
# macos: 
# 	@gcc -Wall -Werror -Wextra -I /usr/local/include.c $(SRCS) ./libft/libft.a ./printf/libftprintf.a -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit -o cube3D
# main: 
# 	@ gcc $(SRCS) ./libft/libft.a ./printf/libftprintf.a \
# 	-L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd