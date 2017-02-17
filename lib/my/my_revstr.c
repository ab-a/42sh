/*
** my_revstr.c for revstr in /home/augier_j/rendu/Piscine_C_J06/ex_03
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Mon Oct  6 18:54:44 2014 Jordan Augier
** Last update Tue Oct  7 21:21:22 2014 Jordan Augier
*/

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      count = count + 1;
    }
  return (count);
}

int	my_char_swap(char *b, char *e)
{
  char	temp;

  temp = *b;
  *b = *e;
  *e = temp;
  return (0);
}

char	*my_revstr(char *str)
{
  int	start;
  int	end;
  char	*b;
  char	*e;

  start = 0;
  end = my_strlen(str);
  end = end - 1;
  while (start <= end)
    {
      b = &str[start];
      e = &str[end];
      my_char_swap(b, e);
      start = start + 1;
      end = end - 1;
    }
  return (str);
}
