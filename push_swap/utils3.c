/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:50:00 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 10:26:24 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[n] != '\0')
		n++;
	if (size == 0)
		return (n);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (n);
}

void	ft_check_str(char **str)
{
	if (str == NULL)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (str[0] == NULL)
	{
		write(2, "Error\n", 6);
		free(str);
		exit(0);
	}
	ft_check_str_next(str);
}

void	ft_check_node(char *str, t_list_a *lst)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		if (lst)
			ft_free_lst(lst);
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	ft_check_node_first(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
