# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:18:19 by nsouza-o          #+#    #+#              #
#    Updated: 2024/04/10 18:21:18 by nsouza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
#NAME_BONUS = checker
SRCS_PATH = ./srcs

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
#BONUS_SRCS_PATH = ./bonus_srcs

#BONUS_SRCS = $(BONUS_SRCS_PATH)/checker.c \
			$(SRCS_PATH)/check_index.c \
			$(SRCS_PATH)/check_parameters.c \
			$(SRCS_PATH)/get_elements.c \
			$(SRCS_PATH)/operations_p.c \
			$(SRCS_PATH)/operations_r.c \
			$(SRCS_PATH)/operations_s.c \
			$(SRCS_PATH)/operations_rr.c \
			$(SRCS_PATH)/stack.c \
			$(SRCS_PATH)/utils.c \
			$(SRCS_PATH)/utils_2.c

SRCS = $(SRCS_PATH)/main.c	

OBJS = $(SRCS:.c=.o)
#BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
HEADER = pipex.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

#bonus: $(NAME_BONUS)

#$(NAME_BONUS): $(BONUS_OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)
clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) 

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) 

re: fclean $(NAME)

.PHONY: all clean fclean libft bonus re