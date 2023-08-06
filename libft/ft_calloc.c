/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:00:09 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/02 16:02:17 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	int				nb;

	nb = (nmemb * size);
	if (nmemb != 0 && nb / nmemb != size)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		mem = malloc(sizeof(char) * 1);
		mem[0] = '\0';
		return (mem);
	}
	mem = malloc(nb);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, (size_t)nb);
	return ((void *)mem);
}
