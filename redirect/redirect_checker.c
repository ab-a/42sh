/*
** redirect_checker.c for redirect_checker in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:03:24 2015 Jordan Augier
** Last update Thu Jun  4 13:25:12 2015 Jordan Augier
*/

#include "include.h"

int	size_of_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int	special_redir(char ***tab, int sotab)
{
  int	fd;

  (*tab)[sotab - 1] = "ls";
  (*tab)[sotab - 2] = NULL;
  (*tab)[sotab - 3] = "test";
  fd = open_file_simple((*tab)[sotab - 3]);
  if (fd == ERROR)
    return (ERROR);
  dup2(fd, 1);
  return (SUCCESS);
  //  simple_right(tab);
  return (0);
}

int	check_redirect(char *str, char ***tab, int sotab)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '>' || str[i] == '<')
	if (special_redir(tab, sotab) == -2)
	  return (-1);
      i++;
    }
  return (0);
}

int	arg_checker(char ***tab)
{
  int	sotab;
  int	i;

  i = 0;
  sotab = size_of_tab((*tab));
  while (i <= (sotab - 3))
    {
      if (check_redirect((*tab)[i], tab, sotab) == -1)
	my_puterror("Wrong redirection\n");
      i++;
    }
  if (my_strcmp(">", (*tab)[i]) == 0)
    simple_right(tab);
  else if (my_strcmp(">>", (*tab)[i]) == 0)
    double_right(tab);
  else if (my_strcmp("<", (*tab)[i]) == 0)
    simple_left(tab);
  else if (my_strcmp("<<", (*tab)[i]) == 0)
   double_left(tab);
  else
   return (0);
  return (0);
}
