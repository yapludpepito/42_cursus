/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:36:26 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/01 13:08:01 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!(s))
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	i = 0;
	if (start + len > ft_strlen(s) - start)
		str = ft_calloc(sizeof(char), ft_strlen(s) - start + 1);
	else
		str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (s[start + i] != '\0' && (size_t)i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
