/*
** my_getnbr.c for getnbr in /home/augier_j/rendu/Piscine_C_J11/lib/my
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Tue Oct 21 14:36:40 2014 Jordan Augier
** Last update Tue Oct 21 14:36:43 2014 Jordan Augier
*/

int	my_getnbr(char *str)
{
  int	nbr;
  int	x;

  nbr = 0;
  x = 1;
  while (*str)
    {
      if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
	x = -1;
      if (*str >= '0' && *str <= '9')
	{
	  while (*str >= '0' && *str <= '9')
	    {
	      nbr = (nbr * 10) + (*str - '0');
	      str = str + 1;
	    }
	  if (nbr >= -2147483648 &&  nbr <= 2147483647)
	    return (nbr * x);
	}
      else if (*str != '-' && *str != '+')
	return (0);
      str = str + 1;
    }
  return (0);
}
