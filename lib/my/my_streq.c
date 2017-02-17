/*
** my_streq.c for  in /home/antoin_l/Travail/PSU_2014_42sh/lib/my
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Thu May 21 17:55:20 2015 root
** Last update Thu May 21 17:56:22 2015 root
*/

int	my_streq(char *s1, char *s2)
{
  int	i;

  i = -1;
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[++i])
    if (s1[i] != s2[i])
      return (-1);
  return (0);
}
