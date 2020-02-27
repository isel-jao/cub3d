

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
AR      = ar rcs

NAME    = libft.a
HEAD    = libft.h
SRCS    = ft_memmove.c ft_strchr.c ft_strnstr.c \
		  ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c ft_strrchr.c \
		  ft_bzero.c ft_memalloc.c ft_strjoin.c ft_strtrim.c \
		  ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strlcat.c ft_substr.c \
		  ft_isalnum.c ft_memccpy.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c \
		  ft_isalpha.c ft_memchr.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c \
		  ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strmapi.c ft_strcmp.c\
		  ft_isdigit.c ft_memcpy.c ft_split.c ft_strncmp.c get_next_line.c \

OBJS    = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all