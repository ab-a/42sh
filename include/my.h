/*
** include.h for includes in /home/augier_j/rendu/ju/PSU_2014_minishell2/includes
** 
** Made by Jordan Augier
** Login   <augier_j@epitech.net>
** 
** Started on  Tue May  5 14:57:02 2015 Jordan Augier
** Last update Thu Jun  4 12:38:49 2015 Antoine Bayard
*/

#ifndef __MY_H__
# define __MY_H__

typedef struct	s_exec
{
  char		*bin;
  char		**arg;
}		t_exec;

typedef struct s_main
{
  char		**path;
  char		*buffer;
  char		*link;
  t_exec	*exec;
  int		f;
  int		fpipe;
  int		pipefd[2];
  int		status;
  int		sotab;
  int		fd;
  char		**env;
}		t_main;

typedef struct	s_dir
{
  char		*new_pwd;
  char		*old_pwd;
  int		ret;
}		t_dir;

char		*my_get_pwd(char **env, char *working_dir);
void		my_exec_pipe_fork(t_main main, int *j, int *i);
char		*my_strcpy(char *str);
char		*my_strcpy_bis(char *str);
char		**get_path_tab_init_buf(char **env, char **buffer);
char		*get_coma_pipe(char *buffer);
t_exec		*get_bin_arg(char *buffer);
char		*my_read();
char		*my_strcat2(char *, char *);
void		my_exec_search(t_main main, int j);
int		my_double_pipe(char *buffer, t_main main);
char		*final_path(char *path, char *func);
char		*my_getenv(char **env, char *str);
char		*cat_home(char *home, char *arg);
t_dir		my_single_cd(char **env, t_dir s);
t_dir		my_minus_cd(char **env, t_dir s);
t_dir		my_cd(char **env, char **arg, t_dir s);
t_dir		my_tilde_cd(char **env, char *arg, t_dir s);
t_dir		cd_up_dir(t_dir s);
t_dir		init_pwd(char **, t_dir s, char *);
t_dir		switch_pwd(t_dir s, char *arg);
char		*clear_str(char *s);
char		**str_to_wtab(char **, char *);
char		*add_space_double_right(char *, int);
char		*add_space_double_left(char *, int);
char		*add_space_simple_right(char *, int);
char		*add_space_simple_left(char *, int);
char		*add_space_redir1(char *);
char		*add_space_redir2(char *);
char		*add_space_redir3(char *);
char		*add_space_redir4(char *);
char		*add_space_pipe(char *, int);
char		*add_space_comma(char *, int);
char		*my_buffer(char *);

#endif /* !__MY_H__ */
