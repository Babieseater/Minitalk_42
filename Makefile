# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 14:48:49 by smayrand          #+#    #+#              #
#    Updated: 2022/10/25 21:07:07 by smayrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = '\033[32m'
NONE = '\033[0m'

NAME = minitalk

CC = gcc -g 
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs

RM = rm -f

SRCS_MASTER = ./srcs/server.c
SRCS_SLAVE = ./srcs/client.c

LIBFT_A = ./libft/libft.a
PRINTF_A = ./printf/libftprintf.a


all: aprintf alibft $(NAME)
	@echo " ==============="
	@echo $(GREEN) "FULLY	COMPILED" $(NONE)
	@sleep 1

run: all
	@clear
	@afplay ./libft/th.wav
	@open -n -a /Applications/iTerm.app
	@./server

aprintf:
	@$(MAKE) -C ./printf
	@echo $(GREEN) "PRINTF	COMPILED" $(NONE)
	@(cd ..)

alibft:
	@$(MAKE) -C ./libft
	@echo $(GREEN) "LIBFT	COMPILED" $(NONE)
	@(cd ..)

printfclean:
	@(cd ./printf && make fclean)
	@echo $(GREEN) "PRINTF	CLEANED" $(NONE)
	@(cd ..)

libftclean:
	@(cd ./libft && make fclean)
	@echo $(GREEN) "LIBFT	CLEANED" $(NONE)
	@(cd ..)
	
server:
	@$(CC) $(SRCS_MASTER) $(CFLAGS) ./printf/libftprintf.a ./libft/libft.a -o server

client:
	@$(CC) $(SRCS_SLAVE) $(CFLAGS) ./printf/libftprintf.a ./libft/libft.a -o client

$(NAME):  server client

clean:
	@$(RM) $(OBJS)

fclean: clean printfclean libftclean
	@$(RM) $(NAME) ./server ./client
	@echo $(GREEN) "FULLY	CLEANED" $(NONE)

rick:
	@curl -s -L http://bit.ly/10hA8iC | bash
	
re: fclean all