/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:12:56 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:41 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list_a **a, t_list_b **b)
{
	*a = ft_rra(*a);
	*b = ft_rrb(*b);
}

t_list_b	*ft_pb(t_list_a **lst_a, t_list_b *lst_b)
{
	t_list_b	*node;
	t_list_a	*tmp;

	tmp = *(lst_a);
	node = ft_lstnew_b((*lst_a)->value);
	node->next = lst_b;
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	free(tmp);
	write(1, "pb\n", 3);
	return (node);
}

t_list_a	*ft_pa(t_list_a *lst_a, t_list_b **lst_b)
{
	t_list_a	*node;
	t_list_b	*tmp;

	tmp = *(lst_b);
	node = ft_lstnew_a((*lst_b)->value);
	node->next = lst_a;
	*lst_b = (*lst_b)->next;
	tmp->next = NULL;
	free(tmp);
	write(1, "pa\n", 3);
	return (node);
}

t_list_a	*ft_ra(t_list_a *lst)
{
	t_list_a	*tmp;
	t_list_a	*current;

	current = lst->next;
	tmp = lst;
	while (lst->next != NULL)
		lst = lst->next;
	tmp->next = NULL;
	lst->next = tmp;
	write(1, "ra\n", 3);
	return (current);
}

t_list_b	*ft_rb(t_list_b *lst)
{
	t_list_b	*tmp;
	t_list_b	*current;

	current = lst->next;
	tmp = lst;
	while (lst->next != NULL)
		lst = lst->next;
	tmp->next = NULL;
	lst->next = tmp;
	write(1, "rb\n", 3);
	return (current);
}
