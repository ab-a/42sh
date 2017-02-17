/*
** exec.c for exec in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:04:38 2015 Jordan Augier
** Last update Sun May 24 17:44:32 2015 Antoine Bayard
*/

#include "include.h"

void	my_exec_simple(t_main main)
{
  int	i;

  i = 0;
  arg_checker(&main.exec[0].arg);
  while (PATH[i] != NULL && execve(FINALPATH, EXEC[0].arg, main.env) == -1)
    i = i + 1;
  if (PATH[i] == NULL)
    exit(my_puterror(UNKNOWN));
}

void	my_exec_search(t_main main, int j)
{
  int	i;

  i = 0;
  arg_checker(&main.exec[j].arg);
  while (PATH[i] != NULL && execve(FINALPATHS, EXEC[j].arg, main.env) == -1)
    i = i + 1;
  if (PATH[i] == NULL)
    my_puterror(UNKNOWN);
  exit(42);
}

void	my_exec_pipe(t_main main, int *j, int *i)
{
  int	f;
  int	pipefd[2];

  if (pipe(pipefd) == -1)
    pipe_error();
  if ((f = fork()) < 0)
    fork_error();
  else
    {
      if (f == 0)
	my_exec_pipe_fork(main, j, i);
      else if (f > 0)
	wait(&f);
    }
}

void	my_exec_special(t_main main)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (main.link[i] != '\0')
    {
      if (main.link[i] == '|')
	{
	  my_exec_pipe(main, &j, &i);
	  while (main.link[i] == '|')
	    {
	      i = i + 1;
	      j = j + 1;
	    }
	  j = j + 1;
	}
      else if (main.link[i] == ';')
	{
	  my_exec_dot_fork(main, &j, &i);
	  while (main.link[i] == ';')
	    i = i + 1;
	}
    }
}

void	my_exec(t_main main)
{
  if (main.link[0] == '\0')
    my_exec_simple(main);
  else
    my_exec_special(main);
}
