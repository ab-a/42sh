/*
** my_exit.c for my_exit in /home/augier_j/rendu/PSU_2014_42sh/builtins
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Tue May 12 11:25:40 2015 Jordan Augier
** Last update Fri May 22 15:20:31 2015 Antoine Bayard
*/

#include "include.h"

int	cmp_exit(char *str)
{
  char	*ex;
  int	i;

  i = 0;
  if (!(ex = malloc(sizeof(char) * 6)))
    return (MALLOC_ERROR);
  ex = "exit ";
  while (i < 5)
    {
      if (ex[i] != str[i])
	return (ERROR);
      else
	i++;
    }
  return (SUCCESS);
}

char	*check_ret(char *str)
{
  int	y;
  int	i;
  char	*tmp;

  if (!(tmp = malloc(sizeof(char) * my_strlen(str) - 5)))
    return (ERR);
  y = 0;
  i = 5;
  while (y < my_strlen(str) - 5)
    {
      tmp[y] = str[i];
      if (str[i] < 48 || str[i] > 57)
	return (ERR);
      y++;
      i++;
    }
  return (tmp);
}

int	my_exit(char *buff)
{
  int	i;

  if (cmp_exit(buff) == SUCCESS)
    {
      if (my_strcmp(ERR, check_ret(buff)) == 0)
	{
	  my_putstr("Error on the output value, no value referred back\n");
	  return (SUCCESS);
	}
      else
	{
	  i = my_getnbr(check_ret(buff));
	  my_printf("%s%d\n", EXIT_VALUE, i);
	  return (SUCCESS);
	}
    }
  else if (my_strcmp("exit", buff) == 0)
    {
      my_printf("%s", EXIT_NO_VALUE);
      return (SUCCESS);
    }
  else
    return (ERROR);
}
