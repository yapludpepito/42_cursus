/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:12 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/02 15:36:35 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n, int *counter)
{
	while (n != 0)
	{
		n /= 10;
		*counter += 1;
	}
	return (*counter);
}

static int	ft_isminus(int nb, char *str)
{	
	int		minus;

	minus = 0;
	if (nb < 0)
	{
		minus = 1;
		str[0] = '-';
	}
	return (minus);
}

static int	check_nb(long int nb, char **str)
{
	if (nb == 0)
	{
		*str = ft_calloc(sizeof(char), 2);
		*str[0] = '0';
		return (0);
	}
	return (1);
}

static void	ft_make_str(int i, int minus, char *str, long int nb)
{
	while (i >= minus)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int			counter;
	int			i;
	char		*str;
	int			minus;
	long int	nb;

	nb = (long int)n;
	i = 0;
	counter = 0;
	if (nb < 0)
		counter++;
	if (check_nb(nb, &str) == 0)
		return (str);
	str = ft_calloc(sizeof(char), (ft_counter(nb, &counter) + 1));
	if (!(str))
		return (NULL);
	i = counter - 1;
	minus = ft_isminus(n, str);
	if (minus == 1)
		nb *= -1;
	ft_make_str(i, minus, str, nb);
	str[counter] = '\0';
	return (str);
}
