/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:37:17 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/09/30 21:49:17 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_make_split(char const *s, char c, char **dest, int n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			i++;
			if (s[i] == c || (s[i] == '\0' && n < ft_count_word(s, c)))
			{
				dest[n] = ft_calloc(sizeof(char), len + 1);
				ft_strlcpy(dest[n], &s[i - len], len + 1);
				len = 0;
				n++;
			}
		}
	}
	dest[n] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		count_word;

	if (!(s))
		return (NULL);
	count_word = ft_count_word(s, c);
	dest = ft_calloc(sizeof(char *), count_word + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_make_split(s, c, dest, 0);
	return (dest);
}
