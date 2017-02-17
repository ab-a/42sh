/*
** my_strcat.c for strcar in /home/augier_j/rendu/PSU_2014_minishell1
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Jan 28 17:10:35 2015 Jordan Augier
** Last update Sun Feb  1 14:29:38 2015 Jordan Augier
*/

#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str3;

  i = 0;
  j = 0;
  str3 = malloc(sizeof(str3) * (my_strlen(dest) + my_strlen(src) + 1));
  while (dest[i] != '\0')
    {
      str3[i] = dest[i];
      i++;
    }
  str3[i++] = '/';
  while (src[j] != '\0')
    str3[i++] = src[j++];
  str3[i] = '\0';
  return (str3);
}
