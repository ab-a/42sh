/*
** env_parsing.c for env in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:05:18 2015 Jordan Augier
** Last update Sat May 23 11:36:30 2015 Antoine Bayard
*/

#include "include.h"

char	*final_path(char *path, char *func)
{
  char	*out;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (FUNCA || FUNCB || FUNCC || FUNCD)
    return (func);
  out = malloc((my_strlen(path) + my_strlen(func) + 2) * sizeof(char));
  while (path[i] != '\0')
    out[j++] = path[i++];
  out[j++] = '/';
  i = 0;
  while (func[i] != '\0')
    out[j++] = func[i++];
  out[j] = '\0';
  return (out);
}

char	*pars_it(char *str, int *i)
{
  char	*out;
  int	j;
  int	k;

  k = 0;
  j = (*i);
  while (str[j] != ':' && str[j] != '\0')
    j = j + 1;
  out = malloc((j - (*i) + 1) * sizeof(char));
  while ((*i) < j)
    out[k++] = str[(*i)++];
  out[k] == '\0';
  return (out);
}

int	howmany_ddots(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ':')
	j = j + 1;
      i = i + 1;
    }
  return (j);
}

char	*look_for_path(char **env)
{
  int	i;

  i = my_get_env_line(env, "PATH");
  return (env[i]);
}

char	**get_path_tab_init_buf(char **env, char **buffer)
{
  char	*path;
  char	**out;
  int	i;
  int	j;

  j = 0;
  i = 5;
  if (((*buffer) = malloc(1025 * sizeof(char))) == NULL)
    return (NULL);
  (*buffer)[0] = '\0';
  if ((path = look_for_path(env)) == NULL)
    return (NULL);
  if (!(out = malloc((howmany_ddots(path) + 1) * sizeof(char *))))
    return (out);
  while (j < (howmany_ddots(path) + 1))
    {
      out[j++] = pars_it(path, &i);
      i = i + 1;
    }
  out[j] = 0;
  return (out);
}
