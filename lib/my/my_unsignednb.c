/*
** my_unsignednb.c for unsigned in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:51:48 2014 Jordan Augier
** Last update Wed Nov 12 14:51:49 2014 Jordan Augier
*/

int	my_unsignednb(unsigned int nb)
{
  if (nb <= 9 && nb >= 0)
    {
      my_putchar(nb + 48);
    }
  if (nb > 9)
    {
      my_unsignednb(nb / 10);
      my_unsignednb(nb % 10);
    }
  return (0);
}
