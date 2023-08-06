/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:09:31 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/27 15:38:07 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char **argv, int argc)
{
	int	i;

	i = 0;
	while (argc > 1)
	{
		while (argv[argc - 1][i] != '\0')
		{
			if ((argv[argc - 1][i] < '0' || argv[argc - 1][i] > '9')
					&& argv[argc - 1][i] != '-')
			{
				write(2, "Error\n", 6);
				return (0);
			}
			i++;
		}
		if (ft_atoll(argv[argc - 1]) > 2147483647
			|| ft_atoll(argv[argc - 1]) < (-2147483648))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		argc--;
	}
	return (1);
}

int	ft_check_list(t_list_a *lst)
{
	t_list_a	*tmp;
	t_list_a	*current;

	tmp = lst;
	current = lst;
	if (lst->next == NULL)
		return (1);
	while (lst != NULL)
	{
		current = current->next;
		lst = current;
		while (lst != NULL)
		{
			if (tmp->value == lst->value)
				return (0);
			lst = lst->next;
		}
		tmp = current;
		lst = current->next;
	}
	return (1);
}

int	ft_lstlen(t_list_a *lst)
{
	int	i;

	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i + 1);
}

t_list_a	*ft_make(t_list_a *lst)
{
	int			length;
	t_list_a	*svalue;

	svalue = lst->next;
	length = ft_lstlen(lst);
	if (ft_is_sorted(lst) == 1)
		return (lst);
	if (length == 2)
	{
		if (svalue->value < lst->value)
			ft_swap_a(lst, 0);
		free(lst);
		free(svalue);
		exit(0);
	}
	else if (length == 3)
		lst = ft_make_three(lst);
	else if (length == 5)
		lst = ft_make_five(lst);
	else
	{
		lst = swap_value(lst);
		lst = ft_make_big_list(lst, ft_lstlen(lst));
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	t_list_a	*a;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a = ft_make_lst(argc, argv);
	if (ft_lstlen(a) < 1)
	{
		ft_free_lst(a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_check_list(a) == 0)
	{
		ft_free_lst(a);
		write(2, "Error\n", 6);
		return (0);
	}
	a = ft_make(a);
	ft_free_lst(a);
	return (0);
}
