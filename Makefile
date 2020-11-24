# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnavone <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 08:44:42 by cnavone           #+#    #+#              #
#    Updated: 2020/11/24 09:05:40 by cnavone          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= 	ft_atoi.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memset.c		\
			ft_strlen.c		\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_strncmp.c	\
			ft_strdup.c		\
			ft_strlcpy.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_calloc.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strchr.c		\
			ft_strlcat.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c
			
OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

HEADER	=	libft.h

HFLAG	=	-I $(HEADER)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) $(HFLAG) -o $@ -c $<

$(NAME):	$(OBJS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

all:	$(NAME)

clean:	
		$(RM) $(OBJS)
		$(RM) $(NAME) 

fclean:	clean

re:		fclean all

.PHONY:	all clean fclean re
