/*
** my_str_to_wordtab2.c for  in /home/antoin_l/Travail/PSU_2014_42sh/lib/my
** 
** Made by Leo Antoine
** Login   <antoin_l@epitech.net>
** 
** Started on  Thu May 21 17:19:35 2015 Leo Antoine
** Last update Sat May 23 18:37:59 2015 
*/

#include <stdlib.h>

int	cpt_space(char *s)
{
  int	i;
  int	cpt;

  i = -1;
  cpt = 1;
  while (s[++i])
    if (s[i] == ' ')
      cpt++;
  return (cpt);
}

char	**malloc_tab(char **tab, char *s)
{
  if (!(tab = malloc(sizeof(char *) * cpt_space(s))))
    return (NULL);
  if (!(tab[0] = malloc(sizeof(char) * my_strlen(s))))
    return (NULL);
  return (tab);
}

char	**str_to_wtab(char **tab, char *s)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = -1;
  if (!(tab = malloc_tab(tab, s)))
    return (NULL);
  while (s[++k])
    {
      while ((s[k] == ' ' || s[k] == '\t')
	     && (s[k + 1] == ' ' || s[k + 1] == '\t'))
	k++;
      if (s[k] == ' ' || s[k] == '\t')
	{
	  j = 0;
	  if (!(tab[++i] = malloc(sizeof(char) * my_strlen(s))))
	    return (NULL);
	}
      else
	tab[i][j++] = s[k];
    }
  tab[++i] = NULL;
  return (tab);
}
