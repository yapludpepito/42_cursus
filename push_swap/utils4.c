/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:00:10 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 12:01:07 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	del;

	del = 0;
	i = 0;
	j = 0;
	while (del == 0)
	{
		del = 1;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				del = 0;
			}
			j++;
		}
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set, int s1_len)
{
	int	j;
	int	del;

	del = 0;
	j = 0;
	while (del == 0)
	{
		del = 1;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[s1_len] == set[j])
			{
				s1_len -= 1;
				del = 0;
			}
			j++;
		}
	}
	return (s1_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		write;

	if (!(s1) || !(set))
		return (NULL);
	write = 0;
	i = ft_start(s1, set);
	j = ft_end(s1, set, ft_strlen(s1) - 1);
	if (s1[i] == '\0')
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	str = ft_calloc(sizeof(char), j - i + 2);
	if (!(str))
		return (NULL);
	while (i <= j)
	{
		str[write] = s1[i];
		i++;
		write++;
	}
	return (str);
}

void	ft_check_str_next(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j] == ' ')
			j++;
		if (str[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

int	find_min_value(t_list_a *lst_a)
{
	t_list_a	*fvalue;
	int			min_value;
	int			i;

	i = 0;
	min_value = lst_a->value;
	fvalue = lst_a;
	while (lst_a != NULL)
	{
		if (lst_a->value < min_value)
			min_value = lst_a->value;
		lst_a = lst_a->next;
	}
	while (fvalue->value != min_value)
	{
		i++;
		fvalue = fvalue->next;
	}
	return (i);
}
