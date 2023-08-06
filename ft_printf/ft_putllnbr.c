/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:06 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/05 11:59:15 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countll_base(long long int nbr, int len_base)
{
	int			count;

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

void	ft_makell_nbr(long long int nbr, int len_base, char *base)
{
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
	}
	if (nbr == 0)
		return ;
	if (nbr >= len_base)
		ft_makell_nbr(nbr / len_base, len_base, base);
	ft_putchar(base[nbr % len_base]);
}

int	ft_putllnbr_base(long long int nbr, char *base)
{
	int	len_base;
	int	i;
	int	n;
	int	len;

	len_base = (int)ft_strlen(base);
	len = ft_countll_base(nbr, len_base);
	i = 0;
	if (len_base < 2)
		return (0);
	while (base[i] != '\0')
	{
		n = i + 1;
		while (base[n] != '\0')
		{
			if (base[n] == base[i])
			{
				return (0);
			}
			n++;
		}
		i++;
	}
	ft_makell_nbr(nbr, len_base, base);
	return (len);
}
