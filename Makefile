# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/10/16 15:43:17 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= fdf

CC 				= cc
FLAGS 			= -Wall -Wextra -Werror
DEBUG			= -fsanitize=address -g

INC_DIR			= ./includes

MLX_DIR 		= ./minilibx
MLX_LIB 		= libmlx.dylib

LIBFT_DIR 		= ./libft
LIBFT_LIB 		= libft.a

LIB_FLAGS 		= -lmlx -L. -framework OpenGL -framework Appkit

SRCS_DIR		= ./sources
SRCS 			= adjust_center.c \
	   			bresenham.c \
	   			error.c \
	   			main.c \
	   			parsing.c \
	   			projection.c \
	   			put_lines.c \
	   			show_image.c \
	   			validation.c \
				free.c

OBJS 			= $(SRCS:%.c=$(SRCS_DIR)/%.o)


%.o :	%.c
	$(CC) $(FLAGS) -c $^ -I $(INC_DIR) -o $@

$(NAME)	:	$(OBJS)
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX_LIB) .
	@make bonus -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) $(LIBFT_DIR)/$(LIBFT_LIB) $(LIB_FLAGS) $(MLX_LIB) $^ -o $@

all	:	$(NAME)

clean	:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean	:	clean
	@rm -f $(LIBFT_DIR)/$(LIBFT_LIB)
	@rm -f $(MLX_LIB)
	rm -f $(NAME)

re	:	fclean all
