/*
** redirect_right.c for redirect_right in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:03:37 2015 Jordan Augier
** Last update Thu Jun  4 13:26:17 2015 Jordan Augier
*/

#include "include.h"

int	simple_right(char ***tab)
{
  int	sotab;
  int	fd;
  int	i;

  i = 0;
  sotab = size_of_tab((*tab));
  (*tab)[sotab - 2] = NULL;
  fd = open_file_simple((*tab)[sotab - 1]);
  if (fd == ERROR)
    return (ERROR);
  dup2(fd, 1);
  return (SUCCESS);
}

int	double_right(char ***tab)
{
  int	sotab;
  int	fd;

  sotab = size_of_tab((*tab));
  (*tab)[sotab - 2] = NULL;
  fd = open_file_double((*tab)[sotab - 1]);
  if (fd == ERROR)
    return (ERROR);
  dup2(fd, 1);
  return (SUCCESS);
}

int	simple_left(char ***tab)
{
  int	sotab;
  int	fd;

  sotab = size_of_tab((*tab));
  (*tab)[sotab - 2] = NULL;
  fd = open_file_if_exist((*tab)[sotab - 1]);
  if (fd == ERROR)
    return (ERROR);
  dup2(fd, 0);
  return (SUCCESS);
}

int	double_left(char ***tab)
{
  char	*buffer;
  int	sotab;
  int	pipefd[2];
  int	c;

  c = 10;
  pipe(pipefd);
  sotab = size_of_tab((*tab));
  (*tab)[sotab - 2] = NULL;
  buffer = get_next_line(0);
  while (my_strcmp_ter((*tab)[sotab - 1], buffer) == -1)
    {
      if (my_strlen(buffer) == 0)
	write(pipefd[1], &c, 1);
      write(pipefd[1], buffer, my_strlen(buffer));
      buffer = get_next_line(0);
    }
  close(pipefd[1]);
  dup2(pipefd[0], 0);
  return (SUCCESS);
}
