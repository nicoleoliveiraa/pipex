# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:18:19 by nsouza-o          #+#    #+#              #
#    Updated: 2024/04/23 20:17:33 by nsouza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS_PATH = ./srcs

SRCS = $(SRCS_PATH)/main.c \
		$(SRCS_PATH)/command_checks.c \
		$(SRCS_PATH)/command_utils.c \
		$(SRCS_PATH)/execute.c \
		$(SRCS_PATH)/utils.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
HEADER = pipex.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean: 
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) 

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus re