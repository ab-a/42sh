/*
** my_cd.c for my_cd in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Fri May 15 12:20:20 2015 Antoine Bayard
** Last update Sun May 24 22:13:01 2015 Léo Antoine
*/

#include "include.h"

t_dir	my_single_cd(char **env, t_dir s)
{
  char	*home;

  home = my_getenv(env, "HOME");
  s.old_pwd = s.new_pwd;
  s.new_pwd = home;
  if (chdir(home) > 0)
    s.ret = ERROR;
  return (s);
}

t_dir	my_tilde_cd(char **env, char *arg, t_dir s)
{
  char	*home;
  char	*command;

  home = my_getenv(env, "HOME");
  command = cat_home(home, arg);
  s.old_pwd = s.new_pwd;
  s.new_pwd = command;
  if (chdir(command) == -1)
    s.ret = ERROR;
  return (s);
}

t_dir	my_minus_cd(char **env, t_dir s)
{
  char	*tmp;

  if (!(tmp = malloc(sizeof(char) * my_strlen(s.old_pwd))))
    {
      my_puterror(MALLOC_ERR);
      return (s);
    }
  tmp = s.old_pwd;
  s.old_pwd = s.new_pwd;
  s.new_pwd = tmp;
  my_printf("%s\n", s.new_pwd);
  if (chdir(tmp) > 0)
    s.ret = ERROR;
  return (s);
}

t_dir		my_cd(char **env, char **arg, t_dir s)
{
  static int	i = 0;

  if (i == 0)
    {
      s.old_pwd = my_getenv(env, "PWD");
      s.new_pwd = s.old_pwd;
      i++;
    }
  if (arg[1] == NULL)
    s = my_single_cd(env, s);
  else if (arg[1][0] == '~')
    s = my_tilde_cd(env, arg[1], s);
  else if (arg[1][0] == '-')
    s = my_minus_cd(env, s);
  else if (my_strcmp(arg[1], "..\0") == 0)
    s = cd_up_dir(s);
  else if (arg[1] != NULL)
    {
      s = switch_pwd(s, arg[1]);
      if (chdir(arg[1]) > 0)
	s.ret = ERROR;
    }
  return (s);
}
