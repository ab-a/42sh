##
## Makefile for makefile in /home/augier_j/rendu/PSU_2014_42sh
## 
## Made by Jordan Augier
## Login   <augier_j@epitech.net>
## 
## Started on  Tue May  5 15:50:29 2015 Jordan Augier
## Last update Thu Jun  4 12:33:09 2015 Antoine Bayard
##

NAME	= 42sh

SRC 	= main.c			\
	  builtins/my_42.c		\
	  builtins/main_bis.c		\
	  builtins/built_ins.c		\
	  builtins/error.c		\
	  builtins/tools.c		\
	  builtins/tools_2.c		\
	  builtins/my_exit.c		\
	  builtins/get_pwd.c		\
	  builtins/my_getenv.c		\
	  builtins/setenv.c		\
	  builtins/unsetenv.c		\
	  builtins/my_cd.c		\
	  builtins/my_cd_utils.c	\
	  builtins/my_echo.c		\
	  builtins/read.c		\
	  builtins/read2.c		\
	  builtins/read3.c		\
	  builtins/add_space_redir.c	\
	  exec/exec_2.c			\
	  exec/exec.c			\
	  exec/exec_3.c			\
	  parsing/env_parsing.c		\
	  parsing/arg_parsing.c		\
	  parsing/file_manager.c	\
	  parsing/get_next_line.c	\
	  parsing/gnl.c			\
	  redirect/redirect_checker.c	\
	  redirect/redirect_right.c	\

OBJ 	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Iinclude

CLIB	= -L./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	cd ./lib/my; make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CLIB)
	@echo " "
	@echo "42sh is ready"

clean:
	cd ./lib/my; make clean
	$(RM) $(OBJ)

fclean:	clean
	cd ./lib/my; make fclean
	$(RM) $(NAME)

re:	fclean all
	cd ./lib/my; make re

.PHONY: all clean fclean re
