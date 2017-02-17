/*
** unsetenv.c for  in /home/antoin_l/Travail/PSU_2014_42sh/builtins
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 23 14:25:38 2015 Léo Antoine
** Last update Sun May 24 22:13:30 2015 Léo Antoine
*/

#include "include.h"

int	clear_env(char **env, char *s)
{
  int	j;

  j = -1;
  while (env[++j])
    {
      if (match(s, env[j], my_strlen(s)) == 0)
	{
	  while (env[j] && env[j + 1])
	    {
	      env[j] = env[j + 1];
	      j++;
	    }
	  env[j] = NULL;
	  return (SUCCESS);
	}
    }
  return (ERROR);
}

int	my_unset_env(char **env, t_main main, char *buffer)
{
  char	**tab;
  int	i;

  buffer = clear_str(buffer);
  if (!(tab = str_to_wtab(tab, buffer)))
    return (int_error("Malloc error\n", ERROR));
  if (cpt_arg(tab) == 1)
    return (int_error("unsetenv: Too few arguments.\n", ERROR));
  i = 0;
  while (tab[++i])
    clear_env(env, tab[i]);
  return (0);
}
