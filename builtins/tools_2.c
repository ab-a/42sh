/*
** tools_2.c for tool_2 in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:03:11 2015 Jordan Augier
** Last update Sun May 24 17:45:32 2015 Antoine Bayard
*/

#include "include.h"

int	my_strcmp_ter(char *src, char *cmp)
{
  int	i;

  i = 0;
  while (cmp[i] != '\0')
    {
      if (src[i] != cmp[i])
	return (ERROR);
      i = i + 1;
    }
  if (src[i] != '\0')
    return (ERROR);
  return (NEUTRAL);
}

char	*my_strcpy_bis(char *str)
{
  char	*temp;
  int	i;

  i = 0;
  if ((temp = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    malloc_error();
  while (str[i] != '\0')
    {
      temp[i] = str[i];
      i = i + 1;
    }
  temp[i++] = '\n';
  temp[i] = '\0';
  return (temp);
}

char	*my_strcat2(char *str1, char *str2)
{
  char	*ret;
  int	i;
  int	x;

  i = 0;
  x = 0;
  if (!(ret = malloc(sizeof(char) * my_strlen(str1) + my_strlen(str2))))
    {
      my_puterror(MALLOC_ERR);
      return (MALLOC_ERR);
    }
  while (str1[i])
    ret[i] = str1[i++];
  while (str2[x])
    ret[i++] = str2[x++];
  return (ret);
}

char	*clear_str(char *s)
{
  int	i;
  int	j;

  i = my_strlen(s) - 1;
  while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
    {
      if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	s[i] = '\0';
      i--;
    }
  s[++i] = '\0';
  return (s);
}
