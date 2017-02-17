/*
** my_put_nbr.c for my_put_nbr in /home/augier_j/rendu/Piscine_C_J03
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Fri Oct  3 12:09:05 2014 Jordan Augier
** Last update Tue Oct 21 14:41:40 2014 Jordan Augier
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if ((nb <= 9) && (nb >= 0))
    {
      my_putchar(nb + 48);
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  return (0);
}
