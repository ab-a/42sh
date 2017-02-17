/*
** flag_functions.c for flag in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:50:13 2014 Jordan Augier
** Last update Sat May 23 17:33:02 2015 
*/

#include <stdlib.h>
#include "include/my.h"

#define BINARY_BASE "01"
#define POINTER_BASE "0123456789abcdef"
#define HEXA_BASE "0123456789abcdef"
#define HEXA_BASE2 "0123456789ABCDEF"
#define OCTAL_BASE "01234567"

void	flag_d(int nb)
{
  my_put_nbr(nb);
}

void	flag_s(char *str)
{
  if (str)
    my_putstr(str);
}

void	flag_c(int nb)
{
  my_putchar(nb);
}

void	flag_b(int nb)
{
  my_putnbr_base(nb, BINARY_BASE);
}

void	flag_p(int nb)
{
  my_putstr("0x");
  my_putnbr_base(nb, POINTER_BASE);
}
