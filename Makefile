# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamatya <pamatya@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 14:30:19 by pamatya           #+#    #+#              #
#    Updated: 2024/07/02 18:56:37 by pamatya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
# CC		=	cc -g -fsanitize=address

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

NAME	=	pipex
PIP_LIB	=	pipex.a
DIR		=	lib
LIB		=	libft.a

EXE_PATH=	.
# EXE_PATH=	./bin

# INFILE	=	./io_files/deepthought.txt
INFILE	=	./io_files/infile.txt
OUTFILE	=	./io_files/outfile.txt

# CMD1	=	cat
# CMD2	=	"grep exe"

CMD1	=	/bin/cat
CMD2	=	"/usr/bin/grep exe"

# CMD1	=	who
# C2_ARG	=	'\''$$2 == "console" {print $$3 " " $$4 " " $$5}'\''
# CMD2	=	'awk $(C2_ARG)'
# CMD2	=	'awk '\''$$2 == "console" {print $$3 " " $$4 " " $$5}'\'''

TEST	=	./src/ft_parse.c

SRCS	=	./src/pipex_main.c ./src/binaries.c ./src/parsing.c ./src/children.c ./src/utilities.c

OBJS	=	$(SRCS:.c=.o)

# DEBUG	=	$(TEST)
DEBUG	=	$(SRCS)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	cp ./$(DIR)/$(LIB) ./$(PIP_LIB)
	ar rcs $(PIP_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(PIP_LIB) -o $(EXE_PATH)/$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -sC $(DIR) all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PIP_LIB)
	$(RM) $(EXE_PATH)/$(NAME)
	$(RM) $(EXE_PATH)/$(NAME)2
	$(RM) ./bin/test
	$(RM) -r ./bin/test.dSYM
	$(RM) ./bin/bug
	$(RM) -r ./bin/bug.dSYM

re: fcleanx
	$(MAKE) fclean
	$(MAKE) all

cleanx:
	$(RM) $(OBJS)
	$(MAKE) -sC $(DIR) clean

fcleanx: cleanx
	$(RM) $(PIP_LIB)
	$(RM) $(EXE_PATH)/$(NAME)
	$(MAKE) -sC $(DIR) fclean

exe:
	$(EXE_PATH)/$(NAME) $(INFILE) $(CMD1) $(CMD2) $(OUTFILE)

exe2:
	$(CC) $(CFLAGS) ./src/pipex2.c -o ./bin/pipex2
	$(EXE_PATH)/$(NAME)2
	
bug:
	$(CC) -g $(CFLAGS) ./lib/libft.a $(DEBUG) -o ./bin/bug

test:
	$(CC) $(CFLAGS) ./lib/libft.a $(TEST) -o ./bin/test
	./bin/test
	

.PHONY: all clean fclean re cleanx fcleanx
