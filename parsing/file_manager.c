/*
** file_manager.c for file_manager in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:04:28 2015 Jordan Augier
** Last update Sun May 24 17:42:26 2015 Antoine Bayard
*/

#include "include.h"

char	*check_my_path(char *str)
{
  int	len;
  char	*out;

  len = my_strlen(str);
  if (str[0] == '"' && str[len - 1] == '"')
    {
      out = malloc((len - 1) * sizeof(char));
      len = 0;
      while (str[len + 1] != '"')
	{
	  out[len] = str[len + 1];
	  len = len + 1;
	}
      out[len] = '\0';
      return (out);
    }
  else
    return (str);
}

int	open_file_simple(char *path)
{
  int	fd;

  path = check_my_path(path);
  if ((fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
    {
      my_puterror(OPEN_ERR);
      return (ERROR);
    }
  return (fd);
}

int	open_file_double(char *path)
{
  int	fd;

  path = check_my_path(path);
  if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR)) < 0)
    {
      my_puterror(OPEN_ERR);
      return (ERROR);
    }
  return (fd);
}

int	open_file_if_exist(char *path)
{
  int	fd;

  path = check_my_path(path);
  if ((fd = open(path, O_RDONLY)) < 0)
    {
      my_puterror(OPEN_ERR);
      return (ERROR);
    }
  return (fd);
}
