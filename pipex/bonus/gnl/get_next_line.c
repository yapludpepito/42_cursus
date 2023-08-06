/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:42:51 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/28 14:07:46 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	if (i < BUFFER_SIZE)
		return (0);
	return (1);
}

char	*ft_read(int fd, char *line_tmp)
{
	int		check;
	char	*buf;
	int		r;

	check = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (check == 1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[r] = '\0';
		check = ft_check(buf);
		line_tmp = ft_strjoin_gnl(line_tmp, buf);
	}
	free(buf);
	buf = NULL;
	return (line_tmp);
}

char	*get_start_line(char *line_tmp)
{
	int		i;
	char	*str;

	i = 0;
	if (!line_tmp)
		return (NULL);
	str = ft_calloc_gnl(sizeof(char), ft_strlen_end(line_tmp) + 2);
	if (!str)
		return (NULL);
	while (line_tmp[i] != '\n' && line_tmp[i] != '\0')
	{
		str[i] = line_tmp[i];
		i++;
	}
	if (line_tmp[i] == '\n')
	{
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	return (str);
}

char	*get_end_line(char *line_tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!line_tmp)
		return (NULL);
	while (line_tmp[i] != '\n' && line_tmp[i] != '\0')
		i++;
	if (line_tmp[i] == '\n')
		i++;
	while (line_tmp[i + j] != '\0')
		j++;
	str = ft_calloc_gnl(sizeof(char), (j + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (line_tmp[i + j] != '\0')
	{
		str[j] = line_tmp[i + j];
		j++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line_tmp;
	char		*line;

	line_tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_tmp = ft_read(fd, line_tmp);
	if (line_tmp == NULL || line_tmp[0] == '\0')
	{
		free(line_tmp);
		return (NULL);
	}
	line = get_start_line(line_tmp);
	free(line_tmp);
	return (line);
}
