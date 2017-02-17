/*
** built_ins.c for builtins in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:05:28 2015 Jordan Augier
** Last update Thu Jun  4 13:21:28 2015 Léo Antoine
*/

#include "include.h"

int	my_print_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    my_printf("%s\n", tab[i++]);
  return (NEUTRAL);
}

int		my_gere_built_ins(char **env, t_main main, char *buffer)
{
  static char	*new_pwd;
  static char	*old_pwd;
  t_dir		s;

  s.new_pwd = new_pwd;
  s.old_pwd = old_pwd;
  if (my_strcmp_bis("cd", EXEC[0].bin) == 0)
    {
      s = my_cd(env, main.exec[0].arg, s);
      new_pwd = s.new_pwd;
      old_pwd = s.old_pwd;
    }
  if (my_strcmp_bis("setenv", EXEC[0].bin) == 0)
    my_set_env(env, main, buffer);
  if (my_strcmp_bis("unsetenv", EXEC[0].bin) == 0)
    my_unset_env(env, main, buffer);
  else if (my_strcmp_bis("env", EXEC[0].bin) == 0)
    my_print_wordtab(env);
  else if (my_strcmp_bis("echo", EXEC[0].bin) == 0)
    my_echo(env, buffer);
  return (SUCCESS);
}
