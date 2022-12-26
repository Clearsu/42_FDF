# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 11:08:32 by jincpark          #+#    #+#              #
#    Updated: 2022/10/06 16:08:44 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

CC						= gcc

FLAGS					= -Wall -Wextra -Werror -I.

SRCS					= ft_atoi.c ft_bzero.c ft_calloc.c \
					  ft_isalnum.c ft_isalpha.c ft_isascii.c \
					  ft_isdigit.c ft_isprint.c ft_itoa.c \
					  ft_memchr.c ft_memcmp.c ft_memcpy.c \
					  ft_memmove.c ft_memset.c ft_putchar_fd.c \
					  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
					  ft_split.c ft_strchr.c ft_strdup.c \
					  ft_striteri.c ft_strjoin.c ft_strlcat.c \
					  ft_strlcpy.c ft_strlen.c ft_strmapi.c \
					  ft_strncmp.c ft_strnstr.c ft_strrchr.c \
					  ft_strtrim.c ft_substr.c ft_tolower.c \
					  ft_toupper.c get_next_line_bonus.c \
					  get_next_line_utils_bonus.c

BNS_SRCS				= ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
					  ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					  ft_lstmap.c ft_lstnew.c

%.o	:	%.c
	$(CC) $(FLAGS) -c $^

MAN_OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

ifdef IF_BONUS
	OBJS = $(MAN_OBJS) $(BNS_OBJS)
else
	OBJS = $(MAN_OBJS)
endif

$(NAME)		:	$(OBJS)
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:
		make IF_BONUS=1 all

clean	:
		rm -f $(MAN_OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re bonus
