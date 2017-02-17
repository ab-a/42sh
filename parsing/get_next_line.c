/*
** get_next_line.c for gnl in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:04:18 2015 Jordan Augier
** Last update Sat May 23 11:58:51 2015 Antoine Bayard
*/

#include "include.h"

char	*my_strncpy(char *src, int nb)
{
  int	z;
  char	*str;

  str = malloc((nb + 1) * sizeof(char));
  z = 0;
  while (src[z] != '\0')
    {
      str[z] = src[z];
      z = z + 1;
    }
  str[z] = '\0';
  return (str);
}

char	*init_gnl(int *k, int *r, int *j, char **ret)
{
  (*k) = 0;
  (*r) = 1;
  (*j) = 0;
  (*ret) = malloc(((4096 * 2) + 1) * sizeof(char));
  return (malloc((TOREAD + 1) * sizeof(char)));
}

void	ifbn(char c, int *k, int *i, char **stock)
{
  if (c == '\n')
    {
      (*k) = -1;
      (*i) = (*i) + 1;
    }
  else if (c == '\0' && (*i) > 0)
    {
      (*k) = -1;
      if ((*stock) != NULL)
	{
	  free((*stock));
	  (*stock) = NULL;
	}
    }
}

void	initnull(int *i, char *buffer, int r, char **stock)
{
  (*i) = 0;
  buffer[r] = '\0';
  (*stock) = my_strncpy(buffer, r);
}

char	*my_get_next_line(const int fd, int j, int k, int r)
{
  char		*buffer;
  static char	*stock = NULL;
  char		*ret;
  static int	i;

  buffer = init_gnl(&k, &r, &j, &ret);
  while (k >= 0)
    {
      if (stock == NULL)
	{
	  if ((r = read(fd, buffer, TOREAD)) < 0)
	    return (0);
	  initnull(&i, buffer, r, &stock);
	}
      while (stock[i] != '\n' && stock[i] != '\0')
	ret[j++] = stock[i++];
      ifbn(stock[i], &k, &i, &stock);
      if (r == 0 && stock[i] == '\0' && i == 0)
	return (NULL);
    }
  ret[j] = '\0';
  free(buffer);
  return (ret);
}
