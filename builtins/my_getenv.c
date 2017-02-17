/*
** my_getenv.c for getenv in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Thu May 14 15:58:19 2015 Antoine Bayard
** Last update Sun May 24 22:13:59 2015 Léo Antoine
*/

#include "include.h"

char	*cut_line(char *str, int i)
{
  char	*ret;
  int	x;

  x = 0;
  if (!(ret = malloc(sizeof(char) * my_strlen(str) - i)))
    return (ERR);
  else
    {
      while (str[i])
	ret[x++] = str[i++];
    }
  return (ret);
}

int	my_get_env_line(char **env, char *str)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[x])
    {
      if (str[x] == env[i][x])
	{
	  while (str[x] != '=' && str[x] == env[i][x])
	    x++;
	  if (x == (my_strlen(str)))
	    return (i);
	}
      i++;
      x = 0;
    }
  return (ERROR);
}

char	*my_getenv(char **env, char *str)
{
  char	*ret;
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[x])
    {
      if (str[x] == env[i][x])
	{
	  while (str[x] != '=' && str[x] == env[i][x])
	    x++;
	  if (x == (my_strlen(str)))
	    {
	      ret = cut_line(env[i], my_strlen(str) + 1);
	      return (ret);
	    }
	}
      i++;
      x = 0;
    }
  return (ERR);
}
