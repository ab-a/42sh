/*
** tools.c for tools in /home/augier_j/rendu/PSU_2014_42sh
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed May  6 14:03:02 2015 Jordan Augier
** Last update Wed May  6 14:03:02 2015 Jordan Augier
*/

int	my_strcmp(char *src, char *cmp)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (cmp[j] == ' ')
    j = j + 1;
  while (src[i] != '\0')
    {
      if (src[i] != cmp[j])
	return (-1);
      j = j + 1;
      i = i + 1;
    }
  while (cmp[j] == ' ')
    j = j + 1;
  if (cmp[j] != '\0')
    return (-1);
  return (0);
}

int	my_strcmp_bis(char *src, char *cmp)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (cmp[j] == ' ')
    j = j + 1;
  while (src[i] != '\0')
    {
      if (src[i] != cmp[j])
	return (-1);
      j = j + 1;
      i = i + 1;
    }
  while (cmp[j] == ' ')
    j = j + 1;
  if (cmp[j] != '\0')
    return (-1);
  return (0);
}

int	how_many_commands(char *buffer)
{
  int	i;
  int	counter;

  i = 0;
  counter = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ';' || buffer[i] == '|')
	counter = counter + 1;
      i = i + 1;
    }
  return (counter + 1);
}

void	move_after_coma(char *str, int *i)
{
  while (str[(*i)] == ' ')
    (*i) = (*i) + 1;
  if (str[(*i)] == ';' || str[(*i)] == '|')
    (*i) = (*i) + 1;
}

char	*my_strcpy(char *str)
{
  return (str);
}
