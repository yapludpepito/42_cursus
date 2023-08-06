/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:52:20 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/12 10:52:24 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*ft_swap_value_next(t_list_a *lst, int value, int i)
{
	while (lst != NULL)
	{
		if (lst->value == value && lst->modified == 0)
			lst = ft_assign_value(lst, i);
		lst = lst->next;
	}
	return (lst);
}

t_list_a	*swap_value(t_list_a *lst)
{
	t_list_a	*save;
	int			value;
	int			i;

	save = lst;
	i = 0;
	while (ft_check_swap_value(save) == 0)
	{
		value = 2147483647;
		lst = save;
		while (lst != NULL)
		{
			if (lst->value <= value && lst->modified == 0)
				value = lst->value;
			lst = lst->next;
		}
		lst = save;
		lst = ft_swap_value_next(lst, value, i);
		i++;
	}
	return (save);
}

int	ft_check_swap_value(t_list_a *lst)
{
	while (lst != NULL)
	{
		if (lst->modified == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list_a	*ft_assign_value(t_list_a *lst, int i)
{
	lst->value = i;
	lst->modified = 1;
	return (lst);
}
