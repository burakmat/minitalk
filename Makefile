# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmat <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 19:15:42 by bmat              #+#    #+#              #
#    Updated: 2022/07/05 17:44:53 by bmat             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = ft_server.c

CLIENT = ft_client.c

SERVER_NAME = server

CLIENT_NAME = client

LIBFT_H = libft/libft.a

LIBFTPRINTF_H = ft_printf/libftprintf.a

SERVER_OBJS = $(SERVER:.c=.o)

CLIENT_OBJS = $(CLIENT:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): lib $(SERVER_NAME) $(CLIENT_NAME)

lib:
	cd libft && make
	cd ft_printf && make

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_OBJS) $(LIBFT_H) $(LIBFTPRINTF_H) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_OBJS) $(LIBFT_H) $(LIBFTPRINTF_H) -o $(CLIENT_NAME)

clean:
	cd libft && make clean
	cd ft_printf && make clean
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re lib $(NAME) 
