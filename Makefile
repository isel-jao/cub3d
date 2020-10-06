# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:43:37 by isel-jao          #+#    #+#              #
#    Updated: 2020/09/19 02:03:50 by isel-jao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC	= gcc -Wall -Wextra -Werror
INCLIB=$(INC)/../lib

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
			./srcs/tools1.c \
			./srcs/tools2.c \
			./srcs/tools3.c \
			./srcs/map.c \
			./srcs/parse.c \
			./srcs/table_utils.c \
			./srcs/parse_utils1.c \
			./srcs/parse_utils2.c \
			./srcs/sprite.c \
			./srcs/bmp.c \
			./srcs/check_touls.c \
			./srcs/ft_error.c \
			./srcs/key_handle.c \
			./srcs/init.c \
			./srcs/wallcast.c \


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
	@ gcc $(SRCS) ./libft/libft.a ./printf/libftprintf.a \
	-L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd