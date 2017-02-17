/*
** get_pwd.c for getpwd in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Thu May 14 09:52:39 2015 Antoine Bayard
** Last update Sat May 23 11:51:11 2015 Antoine Bayard
*/

#include "include.h"

char		*my_get_pwd(char **env, char *working_dir)
{
  static int	z = 0;

  if (z == 0)
    return (my_getenv(env, "PWD"));
  if (z > 0)
    z++;
  return (working_dir);
}
