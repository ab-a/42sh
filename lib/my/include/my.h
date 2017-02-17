/*
** my.h for my.h in /home/augier_j/rendu/PSU_2014_my_printf/include
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Wed Nov 12 14:52:18 2014 Jordan Augier
** Last update Wed Nov 12 18:16:40 2014 Jordan Augier
*/

#ifndef MY_H_
# define MY_H_

void	flag_percent(char*);
int	dispatch_base(char flag);
int	scan_parameters(char *format, ...);
int	dispatch_int(char flag, int nb);
int	dispatch_char(char flag, char *str);
int	dispatch_unsigned_int(char flag, unsigned int nb);
int	unsignednb(unsigned int nb);
void	flag_u(unsigned int);
void	flag_X(int);
void	flag_S(char*);
void	flag_o(int);
void	flag_m(char*);
void	flag_d(int);
void	flag_s(char*);
void	flag_c(int);
void	flag_b(int);
void	flag_p(int);
void	flag_x(int);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
void	my_putnbr_base(int nb, char *base);
int	my_getnbr_base(char *str, char *base);
void	my_putnbr_hexa(unsigned int nb, char *base);
int	my_printf(char *format, ...);

#endif
