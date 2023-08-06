/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:12:41 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 12:33:19 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-')
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		if (str[i] == ' ')
			j++;
		while (str[i] == ' ')
			i++;
	}
	if (str[i - 1] == ' ')
		return (j - 1);
	return (j);
}

t_list_a	*ft_make_split_for_lst_next(int first, char **str, int j,
	t_list_a *lst)
{
	t_list_a	*node;

	if (ft_atoll(str[j]) > 2147483647 || ft_atoll(str[j]) < -2147483648)
	{
		free(str[j]);
		if (str[j + 1])
			free(str[j + 1]);
		free(str);
		if (first != 0)
			ft_free_lst(lst);
		write(2, "Error\n", 6);
		exit(0);
	}
	if (first == 0)
	{
		ft_check_str(str);
		lst = ft_lstnew_a(ft_atoll(str[j]));
	}
	else
	{
		node = ft_lstnew_a(ft_atoll(str[j]));
		ft_lstadd_back(&lst, node);
	}
	return (lst);
}

t_list_a	*ft_make_split_for_lst(char **argv, t_list_a *lst, int i, int first)
{
	int			nbr_space;
	char		**str;
	int			j;

	j = -1;
	argv[i] = ft_strtrim(argv[i], " ");
	nbr_space = ft_check_space(argv[i]);
	str = ft_split(argv[i], ' ');
	free(argv[i]);
	while (nbr_space >= ++j && str[j] != NULL)
	{
		if (str[j] == NULL)
		{
			free(str);
			write(2, "Error\n", 6);
			exit(0);
		}
		lst = ft_make_split_for_lst_next(first, str, j, lst);
		free(str[j]);
		first = 2;
	}
	free(str);
	return (lst);
}

t_list_a	*ft_add_node(int first, t_list_a *lst, char **argv, int i)
{
	t_list_a	*node;

	if (ft_atoll(argv[i]) > 2147483647 || ft_atoll(argv[i]) < -2147483648)
	{
		if (first != 0)
			ft_free_lst(lst);
		write(2, "Error\n", 6);
		exit(0);
	}
	if (first == 0)
	{
		lst = ft_lstnew_a(ft_atoll(argv[i]));
		first = 1;
	}
	else
	{
		node = ft_lstnew_a(ft_atoll(argv[i]));
		ft_lstadd_back(&lst, node);
	}
	return (lst);
}

t_list_a	*ft_make_lst(int argc, char **argv)
{
	t_list_a	*lst;
	int			i;
	int			first;

	first = 0;
	i = 0;
	while (++i < argc)
	{
		if (first == 0)
			ft_check_node_first(argv[i]);
		else
			ft_check_node(argv[i], lst);
		if (ft_check_space(argv[i]) > 0)
		{
			lst = ft_make_split_for_lst(argv, lst, i, first);
			first = 1;
		}
		else
		{
			lst = ft_add_node(first, lst, argv, i);
			first = 1;
		}
	}
	return (lst);
}
