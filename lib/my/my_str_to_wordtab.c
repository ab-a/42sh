/*
** my_str_to_wordtab.c for str in /home/augier_j/rendu/PSU_2014_minishell1
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Fri Jan 23 16:50:30 2015 Jordan Augier
** Last update Sun May 24 16:42:05 2015 Antoine Bayard
*/

#include "mini.h"

int	my_countword(char *str, char carac)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == carac && str[i + 1] != '\0')
	n++;
      i++;
    }
  return (n);
}
int	my_countch(char *str, char carac)
{
  int	c;

  c = 0;
  while ((str[c] != carac) && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}
void	my_init_var(t_var *v)
{
  v->i = 0;
  v->a = 0;
  v->b = 0;
}
char	**my_str_to_wordtab(char *str, char carac)
{
  char	**tab;
  t_var	v;

  my_init_var(&v);
  tab = malloc(sizeof(*tab) * ((my_countword(str, carac) + 1)));
  if (tab == NULL)
    return (NULL);
  while (str[v.i] != '\n' && str[v.i] != '\0')
    {
      if (str[v.i] == carac || str[v.i] == '\n')
	{
	  while (str[v.i] == carac)
	    v.i++;
	  v.a = v.a + 1;
	  v.b = 0;
	}
      tab[v.a] = malloc(sizeof(**tab) * ((my_countch(str + v.i, carac) + 1)));
      if (tab[v.a] == NULL)
	return (NULL);
      while ((str[v.i] != carac) && (str[v.i] != '\n') && (str[v.i] != '\0'))
	tab[v.a][v.b++] = str[v.i++];
      tab[v.a][v.b] = '\0';
    }
  tab[v.a + 1] = 0;
  return (tab);
}
