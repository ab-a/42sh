/*
** my_setenv.c for set_env_unset_env in /home/augier_j/rendu/PSU_2014_42sh/builtins
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Fri May 15 12:05:53 2015 Jordan Augier
** Last update Thu Jun  4 12:28:12 2015 Léo Antoine
*/

#include "include.h"

int	check_name(char **tab)
{
  int	i;

  i = -1;
  if (tab[1])
    {
      if ((tab[1][0] < 'a' || tab[1][0] > 'z')
	  && (tab[1][0] < 'A' || tab[1][0] > 'Z'))
	return (int_error("setenv: Name must begin with a letter.\n", -1));
      while (tab[1][++i])
	if ((tab[1][i] < 'a' || tab[1][i] > 'z')
	    && (tab[1][i] < '0' || tab[1][i] > '9')
	    && (tab[1][i] < 'A' || tab[1][i] > 'Z'))
	  return (int_error("setenv: Name must contain alphanum chars.\n", -1));
    }
  return (SUCCESS);
}

int	match(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (s1[i] && i < nb)
    {
      if (s1[i] == s2[i])
	i++;
      else
	return (-1);
    }
  return (0);
}

int	cpt_arg(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int	my_env(t_main main, char **env, char *s1, char *s2)
{
  int	i;

  i = -1;
  s1[my_strlen(s1)] = '=';
  while (env[++i])
    {
      if (match(s1, env[i], my_strlen(s1)) == 0)
	{
	  if (s2)
	    s1 = my_strcat2(s1, s2);
	  if (!(env[i] = realloc(s1, sizeof(char) * my_strlen(s1))))
	    return (int_error("Malloc error\n", ERROR));
	  return (0);
	}
    }
  if (s2)
    s1 = my_strcat2(s1, s2);
  if (!(env[++i] = realloc(s1, sizeof(char) * my_strlen(s1))))
    return (int_error("Malloc error\n", ERROR));
  env[i - 1] = s1;
  env[i] = NULL;
  return (0);
}

int	my_set_env(char **env, t_main main, char *buffer)
{
  char	**tab;
  int	nb;

  buffer = clear_str(buffer);
  if (!(tab = str_to_wtab(tab, buffer)))
    return (int_error("Malloc error\n", ERROR));
  if (check_name(tab) == ERROR)
    return (0);
  if ((nb = cpt_arg(tab)) == 4)
    return (int_error("Too many arguments\n", 0));
  else if (nb == 1)
    return (my_print_wordtab(env));
  if (my_env(main, env, tab[1], tab[2]) == ERROR)
    return (ERROR);
  return (0);
}
