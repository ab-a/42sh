/*
** arg_parsing.c for pars in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Tue May  5 16:52:56 2015 Jordan Augier
** Last update Sun May 24 16:36:09 2015 Antoine Bayard
*/

#include "include.h"

int	size_of_bin(char *buffer, int i)
{
  int	j;

  while (buffer[i] == ' ' || buffer[i] == '\t')
    i = i + 1;
  if (buffer[i] == '\0' )
    return (-1);
  j = i;
  while (BUF[j] != ' ' && BUF[j] != 0 && BUF[j] != '|' && BUF[j] != ';'
	 && BUF[j] != 9)
    j = j + 1;
  return (j - i);
}

char	*get_bin(char *buffer, int *i)
{
  int	j;
  char	*out;

  j = 0;
  out = malloc((size_of_bin(buffer, (*i)) + 1) * sizeof(char));
  while (buffer[(*i)] == ' ')
    (*i) = (*i) + 1;
  while (buffer[(*i)] != ' ' && buffer[(*i)] != '\0')
    out[j++] = buffer[(*i)++];
  out[j] = '\0';
  return (out);
}

int	how_many_words(char *buffer, int i)
{
  int	counter;

  counter = 0;
  while (buffer[i] != '\0' && buffer[i] != '|' && buffer[i] != ';')
    {
      while (buffer[i] == ' ' || buffer[i] == '\t')
	i = i + 1;
      if (BUF[i] != '\0' && BUF[i] != ' ' && BUF[i] != '|' && BUF[i] != ';')
	counter = counter + 1;
      while (BUF[i] != ' ' && BUF[i] != '\0' && BUF[i] != '|' && BUF[i] != ';')
	i = i + 1;
    }
  return (counter);
}

t_exec		*get_bin_arg(char *buffer)
{
  int		i;
  int		j;
  int		o;
  int		k;
  t_exec	*out;

  o = 0;
  i = 0;
  if ((out = malloc((how_many_commands(buffer) + 1) * sizeof(t_exec))) == NULL)
    malloc_error();
  while (o < how_many_commands(buffer))
    {
      j = 1;
      k = i;
      out[o].bin = get_bin(buffer, &i);
      if ((out[o].arg = malloc((WORDS + 1) * sizeof(char *))) == NULL)
	malloc_error();
      out[o].arg[0] = my_strcpy(out[o].bin);
      while (j < (how_many_words(buffer, k)))
	out[o].arg[j++] = get_bin(buffer, &i);
      out[o++].arg[j] = NULL;
      move_after_coma(buffer, &i);
    }
  out[o].bin = NULL;
  return (out);
}

char	*get_coma_pipe(char *buffer)
{
  int	i;
  int	j;
  char	*out;

  i = 0;
  j = 0;
  if ((out = malloc(how_many_commands(buffer) * sizeof(char))) == NULL)
    return (ERR);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ';' || buffer[i] == '|')
	out[j++] = buffer[i];
      i = i + 1;
    }
  out[j] = '\0';
  return (out);
}
