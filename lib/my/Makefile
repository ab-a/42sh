##
## Makefile for Makefile in /home/augier_j/rendu/Piscine_C_J11/lib/my
## 
## Made by Jordan Augier
## Login   <augier_j@epitech.net>
## 
## Started on  Tue Oct 21 14:14:58 2014 Jordan Augier
## Last update Thu May 21 17:57:01 2015 root
##

NAME	= libmy.a

HEADER	= my.h

SRCS	= dispatch.c \
	  flag_functions2.c \
	  flag_functions.c \
	  flag_functions3.c \
	  my_printf.c \
	  my_convert_base.c \
	  my_getnbr_base.c \
	  my_getnbr.c \
	  my_putchar.c \
	  my_putnbr_base.c \
	  my_put_nbr.c \
	  my_putnbr_hexa.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_strlen.c \
	  my_unsignednb.c \
	  my_strcmp.c \
	  my_str_to_wordtab.c \
	  my_str_to_wordtab2.c \
	  my_streq.c \
	  my_strcat.c

CCO	= ar rc

CCL	= cc -c

RM	= rm -f

RL	= ranlib

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME):
	 $(CCL) $(SRCS)
	 $(CCO) $(NAME) $(OBJS)
	 $(RL) $(NAME)

clean:
	 $(RM) $(OBJS)

fclean: clean
	 $(RM) libmy.a

re: fclean all

.PHONY: all clean fclean re
