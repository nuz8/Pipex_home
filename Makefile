# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/05/27 21:38:35 by pamatya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

NAME	=	pipex
FT		=	libft.a
PRNT	= 	libftprintf.a
FTDIR	=	Libft
PRNTDIR	=	ft_printf
UTIL	=	./Utils_ft_printf

SRCS	=	ft_printf.c	$(UTIL)/ft_putdec.c $(UTIL)/ft_puthex.c \
			$(UTIL)/ft_putptr.c $(UTIL)/ft_putstr.c $(UTIL)/ft_utils.c \
			$(UTIL)/ft_lengths.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT)
	cp ./$(FTDIR)/$(FT) ./$(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT):
	$(MAKE) -C $(FTDIR) all

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(FTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(FTDIR) fclean

re: fclean all

.PHONY: all clean fclean re