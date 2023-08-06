/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:29:15 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 17:28:16 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../../mandatory/libft/libft.h"

int		ft_check(char *str);
char	*ft_read(int fd, char *line_tmp);
char	*get_start_line(char *line_tmp);
char	*get_end_line(char *line_tmp);
char	*get_next_line(int fd);
int		ft_strlen_end(char *str);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(char *s);
void	*ft_calloc_gnl(size_t nmemb, size_t size);

#endif
