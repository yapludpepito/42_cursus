/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:03:08 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/05 16:53:47 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_count_base(int nb, int len_base)
{
	int				count;
	long long int	nbr;

	nbr = (long long int)nb;
	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr != 0)
	{
		nbr = nbr / len_base;
		count++;
	}
	return (count);
}

void	ft_make_nbr(int nb, int len_base, char *base)
{
	long long int	nbr;

	nbr = (long long int)nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
	}
	if (nbr == 0)
		return ;
	if (nbr >= len_base)
		ft_make_nbr(nbr / len_base, len_base, base);
	ft_putchar(base[nbr % len_base]);
}

int	ft_putlnbr_base(int nbr, char *base)
{
	int	len_base;
	int	len;

	len_base = (int)ft_strlen(base);
	len = ft_count_base(nbr, len_base);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_make_nbr(nbr, len_base, base);
	return (len);
}
