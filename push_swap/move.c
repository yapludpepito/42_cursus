/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:19:22 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 11:08:10 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*ft_swap_a(t_list_a *lst, int ss)
{
	void		*tmp;
	t_list_a	*a;

	tmp = lst;
	a = lst->next;
	lst->next = a->next;
	a->next = tmp;
	if (ss != 1)
		write(1, "sa\n", 3);
	return (a);
}

t_list_b	*ft_swap_b(t_list_b *lst, int ss)
{
	t_list_b	*svalue;
	t_list_b	*tvalue;

	svalue = lst->next;
	tvalue = svalue->next;
	svalue->next = lst;
	lst->next = tvalue;
	if (ss != 1)
		write(1, "sb\n", 3);
	return (svalue);
}

void	ft_ss(t_list_a **a, t_list_b **b)
{
	*a = ft_swap_a(*a, 1);
	*b = ft_swap_b(*b, 1);
	write(1, "ss\n", 3);
}

t_list_a	*ft_rra(t_list_a *lst)
{
	t_list_a	*a;
	int			i;

	a = lst;
	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	lst->next = a;
	while (i > 1)
	{
		a = a->next;
		i--;
	}
	a->next = NULL;
	write(1, "rra\n", 4);
	return (lst);
}

t_list_b	*ft_rrb(t_list_b *lst)
{
	t_list_b	*b;
	int			i;

	b = lst;
	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	lst->next = b;
	while (i > 1)
	{
		b = b->next;
		i--;
	}
	b->next = NULL;
	write(1, "rrb\n", 4);
	return (lst);
}
