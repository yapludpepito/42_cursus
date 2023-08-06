/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:03:58 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 10:51:52 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*ft_loop(t_list_a *lst, t_list_b **lst_b, int i, int len)
{
	int	first;
	int	j;

	first = 0;
	j = 0;
	while (j < len)
	{
		if (((lst->value >> i) & 1) == 1)
			lst = ft_ra(lst);
		else
		{
			if (first == 0)
			{
				*lst_b = ft_first_pb(&lst);
				first = 1;
			}
			else
				*lst_b = ft_pb(&lst, *lst_b);
		}
		j++;
	}
	return (lst);
}

t_list_a	*ft_make_big_list(t_list_a *lst, int len)
{
	int			max_number;
	int			nb_bits;
	int			i;
	t_list_b	*lst_b;

	max_number = len - 1;
	nb_bits = 0;
	i = 0;
	while ((max_number >> nb_bits) != 0)
		nb_bits++;
	while (i < nb_bits)
	{
		lst = ft_loop(lst, &lst_b, i, len);
		i++;
		while (lst_b)
			lst = ft_pa(lst, &lst_b);
	}
	return (lst);
}
