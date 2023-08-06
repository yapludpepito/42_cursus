/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:00:34 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/05 16:28:11 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkp(unsigned long nbr)
{
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_putulnbr_base(nbr, "0123456789abcdef") + 2);
	}
}

int	ft_countul_base(unsigned long nbr, int len_base)
{
	int			count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / len_base;
		count++;
	}
	return (count);
}

void	ft_makeul_nbr(unsigned long nbr, int len_base, char *base)
{
	if (nbr >= (unsigned long)len_base)
		ft_makeul_nbr(nbr / len_base, len_base, base);
	ft_putchar(base[nbr % len_base]);
}

int	ft_putulnbr_base(unsigned long nbr, char *base)
{
	int	len_base;
	int	len;

	len_base = (int)ft_strlen(base);
	len = ft_countul_base(nbr, len_base);
	ft_makeul_nbr(nbr, len_base, base);
	return (len);
}
