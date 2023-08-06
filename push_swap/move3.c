/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:29:10 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/12 10:55:10 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*ft_first_pb(t_list_a **lst_a)
{
	t_list_b	*node;
	t_list_a	*tmp;

	tmp = *lst_a;
	node = ft_lstnew_b((*lst_a)->value);
	*lst_a = (*lst_a)->next;
	tmp->next = NULL;
	free(tmp);
	write(1, "pb\n", 3);
	return (node);
}
