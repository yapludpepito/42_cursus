/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:57:01 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/30 09:55:27 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((nbr * neg) <= -2147483648)
			return (0);
		if (nbr >= 2147483647)
			return (-1);
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * neg);
}

void	ft_color_all(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			ft_put_pixel(x, y, 0, vars);
			x++;
		}
		y++;
	}
}

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
