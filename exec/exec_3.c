/*
** exec_3.c for exec_ in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:04:48 2015 Jordan Augier
** Last update Sun May 24 17:34:29 2015 Antoine Bayard
*/

#include "include.h"

void	error_or_not(t_main main)
{
  if (WCOREDUMP(main.status) == true)
    exit(my_putstr("SeGv\n"));
  if (WIFEXITED(main.status == true))
    {
      if (WEXITSTATUS(main.status) == 42)
	exit(my_puterror("Unknown binary\n"));
    }
}

void	child(t_main *main, int j)
{
  if (WCOREDUMP(main->status) == true)
    exit(0);
  dup2(main->pipefd[1], 1);
  my_exec_search((*main), j);
}

void	father(t_main *main, int *j, int *i)
{
  dup2(main->pipefd[0], 0);
  error_or_not((*main));
  (*j) = (*j) + 1;
  if (main->link[(*i) + 1] == '|')
    {
      (*i) = (*i) + 1;
      my_exec_pipe_fork((*main), j , i);
      exit(0);
    }
  else
    my_exec_search((*main), (*j));
}

void	my_exec_pipe_fork(t_main main, int *j, int *i)
{
  (pipe(main.pipefd) == -1) ? pipe_error() : 1;
  ((main.fpipe = fork()) < 0) ? fork_error() : 1;
  if (main.fpipe == 0)
    {
      close(main.pipefd[0]);
      child(&main, (*j));
    }
  else if (main.fpipe > 0)
    {
      close(main.pipefd[1]);
      father(&main, j, i);
    }
}
