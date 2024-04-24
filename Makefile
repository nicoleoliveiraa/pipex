# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:18:19 by nsouza-o          #+#    #+#              #
#    Updated: 2024/04/24 16:27:02 by nsouza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS_PATH = ./srcs
SRCS_BONUS_PATH = ./srcs_bonus

SRCS = $(SRCS_PATH)/main.c \
		$(SRCS_PATH)/command_checks.c \
		$(SRCS_PATH)/command_utils.c \
		$(SRCS_PATH)/execute.c \
		$(SRCS_PATH)/utils.c

SRCS_BONUS = $(SRCS_BONUS_PATH)/main_bonus.c \
			$(SRCS_BONUS_PATH)/command_checks.c \
			$(SRCS_BONUS_PATH)/command_utils.c \
			$(SRCS_BONUS_PATH)/execute.c \
			$(SRCS_BONUS_PATH)/utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS: c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
HEADER = pipex.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

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