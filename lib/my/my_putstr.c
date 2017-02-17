/*
** my_putstr.c for my_putstr in /home/augier_j/rendu/Piscine_C_J04
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Thu Oct  2 13:54:04 2014 Jordan Augier
** Last update Sun May 24 16:50:36 2015 Antoine Bayard
*/

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
