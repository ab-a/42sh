/*
** error.c for error in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:05:08 2015 Jordan Augier
** Last update Sun May 24 17:13:56 2015 Antoine Bayard
*/

#include "include.h"

int	pipe_error()
{
  my_puterror("Pipe Error\n");
  return (ERROR);
}

int	malloc_error()
{
  my_puterror("Malloc Error\n");
  return (ERROR);
}

int	chdir_error()
{
  my_puterror("cd failled\n\n");
  return (ERROR);
}

int	read_error()
{
  my_puterror("Read Error\n");
  return (ERROR);
}

int	int_error(char *s, int nb)
{
  my_puterror(s);
  return (nb);
}
