/*
** main_bis.c for main_bis in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:04:08 2015 Jordan Augier
** Last update Thu Jun  4 12:46:47 2015 Jordan Augier
*/

#include "include.h"

int	my_malloc_error(void)
{
  my_puterror(MALLOC_ERR);
  return (ERROR);
}

int	my_double_pipe(char *buffer, t_main main)
{
  int	i;
  int	y;
  char	*str;
  char	*str2;

  i = 0;
  y = 0;
  return (0);
  if (!(str = malloc(sizeof(char) * 1024)))
    return (my_malloc_error());
  if (!(str2 = malloc(sizeof(char) * 1024)))
    return (my_malloc_error());
  while (buffer[i] != '|')
    str[y++] = buffer[i++];
  i = i + 2;
  y = 0;
  while (buffer[i])
    str2[y++] = buffer[i++];
  i = 0;
  while (PATH[i] != NULL && execve(FINALPATH, EXEC[0].arg, main.env) == -1)
    i++;
  return (NEUTRAL);
}

int	my_double_com(char *buffer, char **env, t_main main)
{
  return (NEUTRAL);
}

int	check_special(char *buffer, char **env, t_main main)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '|' && buffer[i + 1] == '|')
	my_double_pipe(buffer, main);
      else if (buffer[i] == '|' && buffer[i + 1] != '|')
	return (NEUTRAL);
      if (buffer[i] == '&' && buffer[i + 1] == '&')
	my_double_com(buffer, env, main);
      i++;
    }
  return (SUCCESS);
}

char	*my_read()
{
  int	r;
  char	*buffer;

  if ((buffer = malloc(1025 * sizeof(char))) == NULL)
    {
      my_puterror(READ_ERR);
      return (ERR);
    }
  else if ((r = read(0, buffer, 1024)) < 0)
    {
      my_puterror(READ_ERR);
      return (ERR);
    }
  else if (buffer[0] == '\0')
    return (EXIT);
  buffer[r - 1] = '\0';
  if (r == 0)
    return (ERR);
  buffer = my_buffer(buffer);
  if (my_strcmp(buffer, ERR) == 0)
    return (ERR);
  else
    return (buffer);
}
