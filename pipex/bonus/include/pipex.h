/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:51 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 17:27:11 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../mandatory/libft/libft.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data {
	int		input_file;
	int		output_file;
	int		index_cmd;
	int		nb_cmd;
	int		pipe[2];
	int		pipe2[2];
	char	*good_path;
	char	**path;
	char	***cmd;
	pid_t	pid;
}				t_data;

/********************************pipex.c***************************************/

void	ft_save_data(int argc, char **argv, char **envp, t_data *data);
void	ft_close(t_data *data);
void	ft_free(t_data *data);
int		ft_check_empty(char *str);

/*******************************fork.c*****************************************/

void	ft_fork(t_data *data, char **envp);
void	ft_no_execve(t_data *data);
void	ft_parents(t_data *data);
void	ft_check_arg(t_data *data);
void	ft_execve(t_data *data, char **envp);

/*****************************multipipe.c**************************************/

void	ft_make_pipe(t_data *data);
void	ft_dup(t_data *data);

/*****************************make_first_pipe.c********************************/

void	make_first_pipe(t_data *data);

/*****************************make_here_doc.c**********************************/

void	ft_make_here_doc(t_data *data, char **envp, char **argv);
void	ft_make_pipe_here_doc(t_data *data);
void	ft_dup_here_doc(t_data *data);
void	ft_dup_next_here_doc(t_data *data);

#endif
