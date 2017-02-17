/*
** mini.h for mino in /home/augier_j/rendu/PSU_2015_minishell1
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Tue Jan 13 11:54:32 2015 Jordan Augier
** Last update Sun May 24 16:42:36 2015 Antoine Bayard
*/

#ifndef MINI_H_
# define MINI_H_

#include <stdlib.h>

# define AC_ERROR "\033[31mBad number of arguments\n\033[0m"
# define SUCC_EXIT "\033[31mYou left the program\n\033[0m"
# define MALL_ERR "\033[31mMalloc failed\n\033[0m"
# define NOT_FOUND "\033[31mBinary not found\n\033[0m"
# define FORK_ERR "\033[31mFork failed\n\033[0m"
# define OPEN_ERR "\033[31mOpen error\n\033[0m"
# define PIPE_ERR "\033[31mPipe error\n\033[0m"

typedef struct s_var
{
  int		a;
  int		b;
  int		i;
}		t_var;

char	**my_str_to_wordtab(char *, char);

#endif
