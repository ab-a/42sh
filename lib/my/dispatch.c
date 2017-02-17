/*
** dispatch.c for dispatch in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:49:07 2014 Jordan Augier
** Last update Wed Nov 12 18:16:20 2014 Jordan Augier
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"

int	dispatch_int(char flag, int nb)
{
  int	j;
  void	(*ptr_flag_int[8])(int);
  char	tab[] = "dicbpxoX";

  j = 0;
  ptr_flag_int[0] = &flag_d;
  ptr_flag_int[1] = &flag_d;
  ptr_flag_int[2] = &flag_c;
  ptr_flag_int[3] = &flag_b;
  ptr_flag_int[4] = &flag_p;
  ptr_flag_int[5] = &flag_x;
  ptr_flag_int[6] = &flag_o;
  ptr_flag_int[7] = &flag_X;
  while (tab[j] != '\0')
    {
      if (tab[j] == flag)
	{
	  ptr_flag_int[j](nb);
	  return (0);
	}
      else
	j++;
    }
  return (0);
}

int	dispatch_char(char flag, char *str)
{
  int	j;
  void	(*ptr_flag_char[4])(char*);
  char	tab_char[] = "smS%";

  j = 0;
  ptr_flag_char[0] = &flag_s;
  ptr_flag_char[1] = &flag_m;
  ptr_flag_char[2] = &flag_S;
  ptr_flag_char[3] = &flag_percent;
  while (tab_char[j] != '\0')
    {
      if (tab_char[j] == flag)
	{
	  ptr_flag_char[j](str);
	  return (0);
	}
      else
	j++;
    }
  return (0);
}

int	dispatch_unsigned_int(char flag, unsigned int nb)
{
  void	(*ptr_flag_unsigned_int[1])(unsigned int);

  ptr_flag_unsigned_int[0] = &flag_u;
  ptr_flag_unsigned_int[0](nb);
  return (0);
}
