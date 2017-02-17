/*
** my_cd_utils.c for cd_utils in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Fri May 15 12:25:08 2015 Antoine Bayard
** Last update Sun May 24 22:13:08 2015 Léo Antoine
*/

#include "include.h"

char	*cat_home(char *home, char *arg)
{
  char	*ret;
  int	i;
  int	y;

  i = 0;
  y = 1;
  if (!(ret = malloc(sizeof(char) * my_strlen(home) + my_strlen(arg))))
    {
      my_puterror(MALLOC_ERR);
      return (ERR);
    }
  while (home[i])
    ret[i] = home[i++];
  while (arg[y])
    ret[i++] = arg[y++];
  return (ret);
}

char	*up_dir(char *dir)
{
  char	*ret;
  int	i;
  int	x;

  x = 0;
  i = my_strlen(dir);
  if (!(ret = malloc(sizeof(char) * (i + 1))))
    {
      my_puterror(MALLOC_ERR);
      return (ERR);
    }
  while (dir[i] != '/')
    i--;
  while (dir[x] && x < i)
    ret[x] = dir[x++];
  return (ret);
}

t_dir	init_pwd(char **env, t_dir s, char *arg)
{
  s.old_pwd = my_getenv(env, "PWD");
  s.new_pwd = arg;
  return (s);
}

t_dir	switch_pwd(t_dir s, char *arg)
{
  s.old_pwd = s.new_pwd;
  s.new_pwd = arg;
  return (s);
}

t_dir	cd_up_dir(t_dir s)
{
  s.old_pwd = s.new_pwd;
  s.new_pwd = up_dir(s.new_pwd);
  if (chdir(s.new_pwd) > 0)
    s.ret = ERROR;
  return (s);
}
