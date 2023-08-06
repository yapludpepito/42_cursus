/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:31:13 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 11:12:02 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*ft_make_three(t_list_a	*lst_a)
{
	t_list_a	*fvalue;
	t_list_a	*svalue;

	fvalue = lst_a;
	svalue = fvalue->next;
	lst_a = svalue->next;
	if (fvalue->value < svalue->value && svalue->value < lst_a->value)
		return (fvalue);
	else if ((fvalue->value > svalue->value) && (fvalue->value < lst_a->value))
		lst_a = ft_swap_a(fvalue, 0);
	else if (fvalue->value > svalue->value && svalue->value > lst_a->value)
	{
		lst_a = ft_swap_a(fvalue, 0);
		lst_a = ft_rra(lst_a);
	}
	else
		lst_a = ft_make_3_next(fvalue, svalue, lst_a);
	return (lst_a);
}

t_list_a	*ft_make_3_next(t_list_a *fvalue, t_list_a *svalue, t_list_a *lst_a)
{
	if (fvalue->value > svalue->value && svalue->value < lst_a->value)
		lst_a = ft_ra(fvalue);
	else if (fvalue->value < svalue->value && svalue->value > lst_a->value
		&& fvalue->value < lst_a->value)
	{
		lst_a = ft_swap_a(fvalue, 0);
		lst_a = ft_ra(lst_a);
	}
	else
		lst_a = ft_rra(fvalue);
	return (lst_a);
}
