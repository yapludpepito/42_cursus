/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:20:04 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/27 15:29:06 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list_a *lst)
{
	t_list_a	*next;

	next = lst->next;
	while (next != NULL)
	{
		if (lst->value > next->value)
			return (0);
		lst = next;
		next = lst->next;
	}
	return (1);
}
