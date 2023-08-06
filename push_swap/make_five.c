/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:53:08 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 12:31:26 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*ft_make_five(t_list_a *lst_a)
{
	t_list_b	*lst_b;

	while (find_min_value(lst_a) != 0)
	{
		if (find_min_value(lst_a) >= 4)
			lst_a = ft_rra(lst_a);
		else
			lst_a = ft_ra(lst_a);
	}
	lst_b = ft_first_pb(&lst_a);
	while (find_min_value(lst_a) != 0)
	{
		if (find_min_value(lst_a) >= 3)
			lst_a = ft_rra(lst_a);
		else
			lst_a = ft_ra(lst_a);
	}
	lst_b = ft_pb(&lst_a, lst_b);
	lst_a = ft_make_three(lst_a);
	lst_a = ft_pa(lst_a, &lst_b);
	lst_a = ft_pa(lst_a, &lst_b);
	return (lst_a);
}

t_list_a	*ft_third_bigger(t_list_a *lst_a)
{
	t_list_b	*lst_b;

	lst_a = ft_swap_a(lst_a, 0);
	lst_b = ft_first_pb(&lst_a);
	lst_a = ft_swap_a(lst_a, 0);
	lst_a = ft_pa(lst_a, &lst_b);
	return (lst_a);
}
