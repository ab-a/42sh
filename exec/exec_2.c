/*
** exec_2.c for exec_2 in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:04:59 2015 Jordan Augier
** Last update Fri May 22 15:23:48 2015 Antoine Bayard
*/

#include "include.h"

int	how_many_dotloop(char *str, int i)
{
  int	out;

  out = 0;
  while (str[i] == ';')
    {
      out = out + 1;
      i = i + 1;
    }
  if (str[i] == '\0')
    out = out + 1;
  return (out);
}

void	my_exec_dot_fork(t_main main, int *j, int *i)
{
  int	f;
  int	g;

  g = how_many_dotloop(main.link, (*i));
  while (g > 0)
    {
      if ((f = fork()) == -1)
	fork_error();
      else if (f > 0)
	wait(&f);
      else if (f == 0)
	{
	  my_exec_search(main, (*j));
	}
      (*j) = (*j) + 1;
      (*i) = (*i) + 1;
      g = g - 1;
    }
}
