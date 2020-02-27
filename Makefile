# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:43:37 by isel-jao          #+#    #+#              #
#    Updated: 2020/02/26 16:05:58 by isel-jao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC	= gcc -Wall -Wextra -Werror
AR		= ar rcs

BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
GRAY	= \033[0;37m
NC		= \033[0m

NAME = 		cube3d
HEAD	=	cub3d.h
SRCS	= 	./srcs/main.c \
			./srcs/tools.c \
			./srcs/tools1.c \
			./srcs/tools.2c \
	
			
			

OBJS    = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@echo "$(YELLOW)ALL$(NC)"
%.o : %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)cleen$(NC)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)fcleen$(NC)"
re: fclean all
	@rm -f $(OBJS)
	@echo "$(GREEN)ALL DONE$(NC)"
main: 
	# @rm -rf a.out
	# @$(CC) -g main.c libftprintf.a
	# @gcc -g main.c libftprintf.a
	# @clear && cc -I /usr/local/include ./srcs/main.c ./srcs/tools1.c ./srcs/tools2.c ./srcs/tools3.c  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit && ./a.out
	# @clear && cc -I /usr/local/include ./srcs/main.c  ./srcs/table_utils.c ./srcs/map.c  ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit && ./a.out
	# @clear && cc -I /usr/local/include ./srcs/main.c ./srcs/tools1.c ./srcs/tools2.c ./srcs/tools3.c ./srcs/table_utils.c ./srcs/map.c ./srcs/textures.c ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit && ./a.out
	@ cc -I /usr/local/include  ./srcs/*.c ./libft/libft.a ./printf/libftprintf.a \
	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit