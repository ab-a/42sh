/*
** read3.c for read3 in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Thu Jun  4 11:48:27 2015 Antoine Bayard
** Last update Thu Jun  4 12:07:22 2015 Antoine Bayard
*/

#include "include.h"

char	*add_space_simple_left(char *buffer, int i)
{
  buffer[i] = ' ';
  buffer[i + 1] = '<';
  buffer[i + 2] = ' ';
  return (buffer);
}

char	*add_space_simple_right(char *buffer, int i)
{
  buffer[i] = ' ';
  buffer[i + 1] = '>';
  buffer[i + 2] = ' ';
  return (buffer);
}

char	*add_space_double_left(char *buffer, int i)
{
  buffer[i] = ' ';
  buffer[i + 1] = '<';
  buffer[i + 2] = '<';
  buffer[i + 3] = ' ';
  return (buffer);
}

char	*add_space_double_right(char *buffer, int i)
{
  buffer[i] = ' ';
  buffer[i + 1] = '>';
  buffer[i + 2] = '>';
  buffer[i + 3] = ' ';
  return (buffer);
}
