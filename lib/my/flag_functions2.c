/*
** flag_functions2.c for flag2 in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:49:18 2014 Jordan Augier
** Last update Wed Nov 12 15:05:56 2014 Jordan Augier
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"

#define BINARY_BASE "01"
#define POINTER_BASE "0123456789abcdef"
#define HEXA_BASE "0123456789abcdef"
#define HEXA_BASE2 "0123456789ABCDEF"
#define OCTAL_BASE "01234567"

void	flag_x(int nb)
{
  my_putnbr_hexa(nb, HEXA_BASE);
}

void	flag_m(char *str)
{
  my_putstr("Success");
}

void	flag_S(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 32 || str [i] >= 127)
	{
	  my_putstr("\\00");
	  my_putnbr_base(str[i], OCTAL_BASE);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

void	flag_X(int nb)
{
  my_putnbr_hexa(nb, HEXA_BASE2);
}

void	flag_o(int nb)
{
  my_putnbr_base(nb, OCTAL_BASE);
}
