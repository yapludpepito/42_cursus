/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:05 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/09/28 19:10:35 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	i = 0;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (src < dest)
	{
		while (n != 0)
		{
			dest1[n - 1] = src1[n - 1];
			n--;
		}
	}
	else if (dest < src)
	{
		while (i != n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
