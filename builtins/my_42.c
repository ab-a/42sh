/*
** main.c for main in /home/augier_j/rendu/PSU_2014_42sh/builtins
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Thu May 14 17:24:27 2015 Jordan Augier
** Last update Thu Jun  4 13:45:10 2015 Léo Antoine
*/

#include "include.h"

int	env_error()
{
  my_printf("Acces to environnement variable failled\n");
  return (ERROR);
}

int	fork_error()
{
  my_printf("Error when trying to open the new process\n");
  return (ERROR);
}

void	gere_signal(int SIG)
{
  my_printf("\n42sh$> ");
}

void	my_fork(t_main main)
{
  int	status;

  if ((FORK = fork()) < 0)
    fork_error();
  if (FORK == 0)
    {
      my_exec(main);
      exit(0);
    }
  if (FORK > 0)
    waitpid(FORK, &status, 0);
  if (WIFSIGNALED(status))
    my_printf("Segmentation fault (core dumped)\n");
}

int	my_42sh(t_main main, char **env)
{
  signal(SIGINT, gere_signal);
  if ((PATH = get_path_tab_init_buf(env, &main.buffer)) == NULL)
    return (env_error());
  main.env = env;
  while (42)
    {
      my_printf("42sh$> ");
      BUFFER = my_read();
      if (my_strcmp(BUFFER, EXIT) == 0)
	return (0);
      if (my_exit(BUFFER) == SUCCESS || my_exit(BUFFER) == -2)
	return (0);
      else
	{
	  check_special(BUFFER, env, main);
	  EXEC = get_bin_arg(BUFFER);
	  main.link = get_coma_pipe(BUFFER);
	  if ((CMPCD || CMPSET || CMPUNSET || CMPENV || CMPEC) && main.link[0] == '\0')
	    my_gere_built_ins(env, main, BUFFER);
	  else
	    my_fork(main);
	}
    }
  return (0);
}
