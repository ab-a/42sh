/*
** my_strlen.c for my_strlen in /home/augier_j/rendu/Piscine_C_J04
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Thu Oct  2 15:33:04 2014 Jordan Augier
** Last update Sun Nov  2 18:12:49 2014 Jordan Augier
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

