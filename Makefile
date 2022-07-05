# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmat <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 19:15:42 by bmat              #+#    #+#              #
#    Updated: 2022/07/05 19:54:30 by bmat             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = ft_server.c
SERVER_BONUS = ft_server_bonus.c
CLIENT = ft_client.c
CLIENT_BONUS = ft_client_bonus.c

SERVER_NAME = server
SERVER_NAME_BONUS = server_bonus

CLIENT_NAME = client
CLIENT_NAME_BONUS = client_bonus

LIBFT_H = libft/libft.a

LIBFTPRINTF_H = ft_printf/libftprintf.a

SERVER_OBJS = $(SERVER:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS:.c=.o)
CLIENT_OBJS = $(CLIENT:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS:.c=.o)

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

bonus: lib $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS): $(SERVER_BONUS_OBJS)
	$(CC) $(FLAGS) $(SERVER_BONUS_OBJS) $(LIBFT_H) $(LIBFTPRINTF_H) -o $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): $(CLIENT_BONUS_OBJS)
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT_H) $(LIBFTPRINTF_H) -o $(CLIENT_NAME_BONUS)

clean:
	cd libft && make clean
	cd ft_printf && make clean
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	cd libft && make fclean
	cd ft_printf && make fclean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re lib 
