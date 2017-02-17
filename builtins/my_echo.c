/*
** my_echo.c for  in /home/antoin_l/Travail/PSU_2014_42sh/builtins
** 
** Made by Léo Antoine
** Login   <antoin_l@epitech.net>
** 
** Started on  Thu Jun  4 11:29:51 2015 Léo Antoine
** Last update Thu Jun  4 14:06:20 2015 Léo Antoine
*/

#include "include.h"

char	*kick_dolls(char *s)
{
  int	i;

  i = -1;
  while (s[++i])
    s[i] = s[i + 1];
  return (s);
}

int	print_envarg(char **env, char *s)
{
  int	i;
  int	j;

  i = -1;
  s = kick_dolls(s);
  while (env[++i])
    {
      if (match(s, env[i], my_strlen(s)) == 0)
	{
	  j = 0;
	  while (env[i][j] != '=')
	    j++;
	  while (env[i][++j])
	    my_putchar(env[i][j]);
	  return (0);
	}
    }
  my_putstr(s);
  return (int_error(": Undefined variable.\n", ERROR));
}

int	my_echo(char **env, char *s)
{
  char	**tab;
  int	i;

  i = 0;
  if (!(tab = str_to_wtab(tab, s)))
    return (int_error("Malloc error\n", ERROR));
  while (tab[++i])
    {
      if (tab[i][0] == '$')
	print_envarg(env, tab[i]);
      else
	my_putstr(tab[i]);
      my_putchar(' ');
    }
  my_putchar('\n');
  return (SUCCESS);
}
