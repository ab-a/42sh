/*
** my_strcmp.c for my_strcmp in /home/augier_j/rendu/work
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Jan 21 14:03:52 2015 Jordan Augier
** Last update Fri Jan 23 21:00:58 2015 Jordan Augier
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      else
	return (0);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  else
    return (0);
}
