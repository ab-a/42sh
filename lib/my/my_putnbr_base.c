/*
** my_putnbr_base.c for putnbrbase in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:51:10 2014 Jordan Augier
** Last update Wed Nov 12 14:51:11 2014 Jordan Augier
*/

void	my_putnbr_base(int nb, char *base)
{
  int	result;
  int	diviseur;
  int	size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb / diviseur) % size_base;
      my_putchar(base[result]);
      diviseur = diviseur / size_base;
    }
}
