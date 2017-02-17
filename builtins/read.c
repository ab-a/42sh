/*
** read.c for read in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Thu Jun  4 11:15:56 2015 Antoine Bayard
** Last update Thu Jun  4 12:27:23 2015 Antoine Bayard
*/

#include "include.h"

char	*del_tab(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\t')
	buffer[i] = ' ';
      i++;
    }
  return (buffer);
}

char	*add_space_multi(char *buffer)
{
  char	*ret;
  int	y;
  int	i;

  i = 0;
  y = 0;
  if (!(ret = malloc(sizeof(char) * 4096)))
    return (ERR);
  while (buffer[i])
    {
      if (buffer[i] == '|' && buffer[i - 1] != ' ' && buffer[i - 1] != ' ' && i != 0)
	{
	  ret = add_space_pipe(ret, y);
	  y = y + 3;
	  i++;
	}
      if (buffer[i] == ';' && buffer[i] - 1 != ' ' && buffer[i - 1] != ' '&& i != 0)
	{
	  ret = add_space_comma(ret, y);
	  y = y + 3;
	  i++;
	}
      ret[y++] = buffer[i++];
    }
  return (ret);
}

char	*my_buffer(char *buffer)
{
  char	*ret;
  int	i;

  i = 0;
  if (!(ret = malloc(sizeof(char) * 4096)))
    return (ERR);
  else
    {
      ret = del_tab(buffer);
      ret = add_space_multi(ret);
      ret = add_space_redir1(ret);
      ret = add_space_redir2(ret);
      ret = add_space_redir3(ret);
      ret = add_space_redir4(ret);
      if (my_strcmp(buffer, ERR) == 0)
	return (ERR);
    }
  return (ret);
}
