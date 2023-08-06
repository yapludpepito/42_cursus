/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:29:15 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 13:03:16 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_check(char *str);
char	*ft_read(int fd, char *line_tmp);
char	*get_start_line(char *line_tmp);
char	*get_end_line(char *line_tmp);
char	*get_next_line(int fd);
int		ft_strlen_end(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *str);

#endif
