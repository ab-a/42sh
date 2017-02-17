/*
** macro.h for macro in /home/bayard_a/PSU_2014_42sh
** 
** Made by Antoine Bayard
** Login   <bayard_a@epitech.net>
** 
** Started on  Sun May 24 16:51:25 2015 Antoine Bayard
** Last update Thu Jun  4 13:45:08 2015 Léo Antoine
*/

#ifndef __MACRO_H__
# define __MACRO_H__

# define BUFFER         main.buffer
# define PATH           main.path
# define EXEC           main.exec
# define FORK           main.f
# define BUF            buffer
# define FINALPATH      (final_path(PATH[i], EXEC[0].bin))
# define FINALPATHS     (final_path(PATH[i], EXEC[j].bin))
# define CMPCD          (my_strcmp_bis("cd", EXEC[0].bin) == 0)
# define CMPSET         (my_strcmp_bis("setenv", EXEC[0].bin) == 0)
# define CMPUNSET       (my_strcmp_bis("unsetenv", EXEC[0].bin) == 0)
# define CMPENV         (my_strcmp_bis("env", EXEC[0].bin) == 0)
# define CMPEC		(my_strcmp_bis("echo", EXEC[0].bin) == 0)
# define FUNCA          (func[0] < 48)
# define FUNCB          (func[0] > 57 && func[0] < 65)
# define FUNCC          (func[0] > 90 && func[0] < 97)
# define FUNCD          (func[0] > 122)
# define WORDS          (how_many_words(buffer, k))
# define NEUTRAL	0
# define SUCCESS        1
# define ERROR          -1
# define MALLOC_ERROR   -5
# define REALLOC_ERROR  -5
# define EXIT           "EXIT"
# define ERR            "ERROR"
# define EXIT_NO_VALUE  "Exit 42sh with no return value\n"
# define EXIT_VALUE     "Exit 42sh with return value : "
# define NO_ENV		"No env set : operation aborted, the shell will quit\n"
# define FEAT		"--features"
# define USAGE		"Usage : ./42sh or ./42sh --features\n"
# define MALLOC_ERR	"Memory allocation failure\n"
# define READ_ERR	"Read error\n"
# define OPEN_ERR	"Error while opening file\n"
# define UNKNOWN	"Unknown binary\n"

#endif /* !__MACRO_H__ */
