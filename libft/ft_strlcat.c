/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:25:26 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/09/29 12:24:28 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	len2;

	i = 0;
	if (!(dest) && size == 0)
		return (0);
	len = ft_strlen(dest);
	len2 = ft_strlen(src);
	if (len >= size)
		return (len2 + size);
	while (len + i < size - 1 && src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + len2);
}
