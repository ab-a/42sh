/*
** read2.c for read2 in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Thu Jun  4 11:31:59 2015 Antoine Bayard
** Last update Thu Jun  4 11:46:08 2015 Antoine Bayard
*/

#include "include.h"

char	*add_space_pipe(char *buffer, int i)
{
  buffer[i] = ' ';
  buffer[i + 1] = '|';
  buffer[i + 2] = ' ';
  return (buffer);
}

char	*add_space_comma(char *buffer, int i)
{
  buffer[i] = ' ';
  buffer[i + 1] = ';';
  buffer[i + 2] = ' ';
  return (buffer);
}
