/*
** 42sh.h for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 13:26:46 2016 escorn_t
** Last update Thu May 12 11:14:57 2016 escorn_t
*/

#ifndef _42SH_H_
# define _42SH_H_

typedef struct  s_tree
{
  char		*cmd;
  struct s_tree	*next;
}		t_tree;

typedef	struct	s_env
{
  int		size;
  char		**tab;
}		t_env;

void	my_putchar(char c);
void	free_tab(char **tab);
void	my_putstr(char *str);
void	my_put_err(char *str);
void	my_putchar_err(char c);
int	create_tree(t_tree *, char **);
int	error_malloc();
char	*epurstr(char *str);
char	*get_next_line(int fd);
char	**create_env(char **ae, int i);
char	**my_str_to_wordtab(char *str, char opt);

#endif /* !_42SH_H_ */
