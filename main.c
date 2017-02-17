/*
** main.c for main in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Fri May 22 18:21:38 2015 Antoine Bayard
** Last update Sun May 24 17:12:53 2015 Antoine Bayard
*/

#include "include.h"

void	print_features(void)
{
  my_printf("%s\n%s\n%s\n%s\n%s\n%s\n", FT1, FT2, FT3, FT4, FT5, FT6);
  my_printf("%s\n%s\n%s\n%s\n%s\n%s\n", FT7, FT8, FT9, FT10, FT11, FT12);
}

void	print_splash(void)
{
  my_printf("%s\n%s\n%s\n%s\n", SP0, SP1, SP2, SP3);
  my_printf("%s\n%s\n%s\n%s\n", SP4, SP5, SP6, SP7);
  my_printf("%s\n%s\n%s\n%s\n", SP8, SP9, SP10, SP11);
  my_printf("%s\n%s\n%s\n\n", SP12, SP13, SP14);
}

int	check_env(char **env)
{
  if (env[0] == NULL)
    return (ERROR);
  else
    return (NEUTRAL);
}

int		main(int argc, char **argv, char **env)
{
  t_main	main;

  print_splash();
  if (check_env(env) == ERROR)
    {
      my_puterror(NO_ENV);
      return (ERROR);
    }
  if (argc == 2 && my_strcmp(argv[1], FEAT) == 0)
    print_features();
  else if (argc == 1)
    {
      my_printf("%s\n", ARG_SEE);
      my_42sh(main, env);
    }
  else
    my_puterror(USAGE);
  my_printf("\n%s\n", SP15);
  return (NEUTRAL);
}
