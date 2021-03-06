/*
** find_type_cmd.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Fri May 13 17:15:58 2016 Lucas Villeneuve
** Last update Sat Jun  4 15:54:32 2016 Lucas Villeneuve
*/

#include <glob.h>
#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	check_builtin(char **cmd, t_all *all)
{
  int	(*tab[4])(char **cmd, t_all *all);
  char	*string;
  int	i;

  if ((string = calloc(5, sizeof(char))) == NULL)
    error_malloc();
  strcpy(string, "cesu");
  i = 0;
  tab[0] = &my_cd_builtin;
  tab[1] = &my_exit_env_echo;
  tab[2] = &my_setenv_builtin;
  tab[3] = &my_unsetenv_builtin;
  while (i < 4)
    {
      if (cmd[0][0] == string[i])
	{
	  free(string);
	  return (tab[i](cmd, all));
	}
      i++;
    }
  free(string);
  return (0);
}

int	parse_for_pipe(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == '|' || tab[i][j] == '<' || tab[i][j] == '>')
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

char	**find_type_cmd(char **tab, t_all *all)
{
  int	i;

  if (tab == NULL)
    return (NULL);
  if (strlen(tab[0]) == 0)
    return (tab);
  i = 0;
  while (tab[i])
    {
      if (check_for_star(tab[i]) == 1)
	if ((tab = my_glob(tab[i], tab, i)) == NULL)
	  return (NULL);
      i++;
    }
  if (parse_for_pipe(tab) == 1)
    my_pipe(tab, all);
  else
    if (check_builtin(tab, all) != 1)
      my_simple_exec(all, tab, all->path, &all->env);
  return (tab);
}
