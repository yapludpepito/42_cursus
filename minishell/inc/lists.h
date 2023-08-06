/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:17 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/13 11:25:17 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

void	ft_lstadd_back_cmd(t_cmds **lst, t_cmds *new);
void	lstadd_back_envp(t_envp **lst, t_envp *new);
t_envp	*save_envp(char **envp);
t_envp	*lstnew_envp(char *variable, char *value);
t_envp	*lstlast_envp(t_envp *lst);
int		ft_lst_size_cmd(t_cmds *cmd);
void	ft_lst_free(t_envp *lst);
int		ft_lst_size_env(t_envp *lst_envp);
t_envp	*ch_var_lst_envp(t_envp *lst_envp, char *var, char *value);
char	**rebuild_envp(t_envp *lst_envp);
void	update_cmds_env(t_cmds *cmds);
t_envp	*ft_find_node(char *to_find, t_envp *envp);

#endif