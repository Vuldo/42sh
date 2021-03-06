/*
** builtins.c for  in /home/jeanj/Rendu/PSU_2015/42sh/src
**
** Made by Jean Jonathan
** Login   <jeanj@epitech.net>
**
** Started on  Mon May 30 16:35:16 2016 Jean Jonathan
** Last update Fri Jun  3 12:14:40 2016 Jean Jonathan
*/

#include "sh.h"

int     init_fp(t_sh *sh)
{
  if ((sh->builtins_ptr = malloc(sizeof(b_ptr *) * 11)) == NULL)
    return (-1);
  sh->builtins_ptr[0] = &builtins_env;
  sh->builtins_ptr[1] = &builtins_setenv;
  sh->builtins_ptr[2] = &builtins_unsetenv;
  sh->builtins_ptr[3] = &builtins_cd;
  sh->builtins_ptr[4] = &builtins_alias;
  sh->builtins_ptr[5] = &builtins_setalias;
  sh->builtins_ptr[6] = &builtins_unsetalias;
  sh->builtins_ptr[7] = &builtins_reload;
  sh->builtins_ptr[8] = &builtins_echo;
  sh->builtins_ptr[9] = &read_history;
  sh->builtins_ptr[10] = &clear_history;
  return (0);
}

int     init_builtins(t_sh *sh)
{
  if ((sh->builtins = malloc(sizeof(char *) * 11)) == NULL)
    return (-1);
  sh->builtins[0] = my_strdup("env");
  sh->builtins[1] = my_strdup("setenv");
  sh->builtins[2] = my_strdup("unsetenv");
  sh->builtins[3] = my_strdup("cd");
  sh->builtins[4] = my_strdup("alias");
  sh->builtins[5] = my_strdup("setalias");
  sh->builtins[6] = my_strdup("unsetalias");
  sh->builtins[7] = my_strdup("reload");
  sh->builtins[8] = my_strdup("echo");
  sh->builtins[9] = my_strdup("history");
  sh->builtins[10] = my_strdup("clear-history");
  init_fp(sh);
  return (0);
}

int     check_builtins(t_sh *sh, char *name)
{
  int   i;
  char	**tab;

  i = 0;
  if ((tab = my_cut_in_tab(name, ' ')) == NULL)
    return (-1);
  while (i < 11)
    {
      if (strcmp(sh->builtins[i], tab[0]) == 0)
        {
          sh->builtins_ptr[i](sh);
          return (0);
        }
      i++;
    }
  free_tab(tab);
  return (1);
}
