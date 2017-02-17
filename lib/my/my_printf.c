/*
** main.c for main in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:50:21 2014 Jordan Augier
** Last update Sun May 24 16:34:50 2015 Antoine Bayard
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"

int	dispatch_base(char flag)
{
  int	j;
  char	tab[] = "dicbpxoX";
  char	tab_char[] = "smS%";

  j = 0;
  while (tab[j])
    {
      if (tab[j] == flag)
	return (-1);
      if (flag == 'u')
	return (-3);
      else
	j++;
    }
  j = 0;
  while (tab[j])
    {
      if (tab_char[j] == flag)
	return (-2);
      else
	j++;
    }
  return (0);
}

int	my_printf(char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  if (dispatch_base(format[i + 1]) == -1)
	    dispatch_int(format[i + 1], va_arg(ap,  int));
	  if (dispatch_base(format[i + 1]) == -2)
	    dispatch_char(format[i + 1], va_arg(ap, char*));
	  if (dispatch_base(format[i + 1]) == -3)
	    dispatch_unsigned_int(format[i + 1], va_arg(ap, unsigned int));
	  i = i + 2;
	}
      else
	{
	  my_putchar(format[i]);
	  i++;
	}
    }
  va_end(ap);
  return (0);
}
