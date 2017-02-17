/*
** gnl.c for gnl in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Fri May 22 19:34:55 2015 Antoine Bayard
** Last update Fri May 22 19:36:32 2015 Antoine Bayard
*/

#include "get_next_line.h"

char	*get_next_line(const int fd)
{
  char	*ret;
  int	j;
  int	k;
  int	r;

  ret = my_get_next_line(fd, j, k, r);
  return (ret);
}
