/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:41:40 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/05 12:43:47 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countu_base(unsigned int nbr, int len_base)
{
	int	count;

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

void	ft_makeu_nbr(unsigned int nbr, int len_base, char *base)
{
	if (nbr == 0)
		return ;
	if (nbr >= (unsigned int)len_base)
		ft_makeu_nbr(nbr / len_base, len_base, base);
	ft_putchar(base[nbr % len_base]);
}

int	ft_putunbr_base(unsigned int nbr, char *base)
{
	int	len_base;
	int	i;
	int	n;
	int	len;

	len_base = (int)ft_strlen(base);
	len = ft_countu_base(nbr, len_base);
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
	ft_makeul_nbr(nbr, len_base, base);
	return (len);
}
