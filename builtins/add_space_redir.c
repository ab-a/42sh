/*
** add_space_redir.c for manage redir in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Thu Jun  4 11:53:10 2015 Antoine Bayard
** Last update Thu Jun  4 12:26:12 2015 Antoine Bayard
*/

#include "include.h"

char    *add_space_redir1(char *buffer)
{
  char  *ret;
  int   y;
  int   i;

  i = 0;
  y = 0;
  if (!(ret = malloc(sizeof(char) * 4096)))
    return (ERR);
  while (buffer[i])
    {
      if (buffer[i] == '<' && buffer[i - 1] != ' ' && buffer[i + 1] != ' ' 
	  && i != 0 && buffer[i + 1] != '<' && buffer[i - 1] != '<')
        {
          ret = add_space_simple_left(ret, y);
          y = y + 3;
          i++;
        }
      ret[y++] = buffer[i++];
    }
  return (ret);
}

char    *add_space_redir2(char *buffer)
{
  char  *ret;
  int   y;
  int   i;

  i = 0;
  y = 0;
  if (!(ret = malloc(sizeof(char) * 4096)))
    return (ERR);
  while (buffer[i])
    {
      if (buffer[i] == '>' && buffer[i - 1] != ' ' && buffer[i + 1] != ' ' 
	  && i != 0 && buffer[i + 1] != '>' && buffer[i - 1] != '>')
        {
          ret = add_space_simple_right(ret, y);
          y = y + 3;
          i++;
        }
      ret[y++] = buffer[i++];
    }
  return (ret);
}

char    *add_space_redir3(char *buffer)
{
  char  *ret;
  int   y;
  int   i;

  i = 0;
  y = 0;
  if (!(ret = malloc(sizeof(char) * 4096)))
    return (ERR);
  while (buffer[i])
    {
      if (buffer[i] == '<' && buffer[i - 1] != ' ' && buffer[i + 1] != ' ' 
	  && i != 0 && buffer[i + 1] == '<' && buffer[i - 1] != '<')
        {
          ret = add_space_double_left(ret, y);
          y = y + 4;
          i = i + 2;
        }
      ret[y++] = buffer[i++];
    }
  return (ret);
}

char    *add_space_redir4(char *buffer)
{
  char  *ret;
  int   y;
  int   i;

  i = 0;
  y = 0;
  if (!(ret = malloc(sizeof(char) * 4096)))
    return (ERR);
  while (buffer[i])
    {
      if (buffer[i] == '>' && buffer[i - 1] != ' ' && buffer[i + 1] != ' ' 
	  && i != 0 && buffer[i + 1] == '>' && buffer[i - 1] != '>')
        {
          ret = add_space_double_right(ret, y);
          y = y + 4;
          i = i + 2;
        }
      ret[y++] = buffer[i++];
    }
  return (ret);
}
