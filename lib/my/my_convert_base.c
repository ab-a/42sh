/*
** my_convert_base.c for convert in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:50:43 2014 Jordan Augier
** Last update Wed Nov 12 14:50:43 2014 Jordan Augier
*/

#include <stdlib.h>
#include "include/my.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	i;
  int	nb;
  char	*res;

  i = 0;
  res = malloc(sizeof(char) * 300);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      res[i] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      i++;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
