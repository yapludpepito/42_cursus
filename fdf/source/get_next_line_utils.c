/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:33:26 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 13:03:40 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_end(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	dest = ft_calloc(sizeof(char), i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s && s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	int				nb;

	nb = (nmemb * size);
	if (nmemb != 0 && nb / nmemb != size)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		mem = malloc(sizeof(char) * 1);
		mem[0] = '\0';
		return (mem);
	}
	mem = malloc(nb);
	if (mem == NULL)
		return (NULL);
	while (nb != 0)
	{
		mem[nb - 1] = '\0';
		nb--;
	}
	return ((void *)mem);
}
