/*
** my_putnbr_hexa.c for hexa in /home/augier_j/rendu/PSU_2014_my_printf
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:51:34 2014 Jordan Augier
** Last update Wed Nov 12 14:51:35 2014 Jordan Augier
*/

#define HEXA_MIN "0123456789abcdef"
#define HEXA_CAP "0123456789ABCDEF"

void	my_putnbr_hexa(unsigned int nb, char *base)
{
  unsigned int	beg;
  unsigned int	end;

  end = nb % 16;
  beg = (nb - end) / 16;
  if (beg != '\0')
    {
      my_putnbr_hexa(beg, base);
    }
  my_putchar(base[end]);
}
