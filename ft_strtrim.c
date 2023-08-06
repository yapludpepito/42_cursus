/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:09:03 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/01 12:59:47 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	del;

	del = 0;
	i = 0;
	j = 0;
	while (del == 0)
	{
		del = 1;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				del = 0;
			}
			j++;
		}
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set, int s1_len)
{
	int	j;
	int	del;

	del = 0;
	j = 0;
	while (del == 0)
	{
		del = 1;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[s1_len] == set[j])
			{
				s1_len -= 1;
				del = 0;
			}
			j++;
		}
	}
	return (s1_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		write;

	if (!(s1) || !(set))
		return (NULL);
	write = 0;
	i = ft_start(s1, set);
	j = ft_end(s1, set, ft_strlen(s1) - 1);
	if (s1[i] == '\0')
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	str = ft_calloc(sizeof(char), j - i + 2);
	if (!(str))
		return (NULL);
	while (i <= j)
	{
		str[write] = s1[i];
		i++;
		write++;
	}
	return (str);
}
