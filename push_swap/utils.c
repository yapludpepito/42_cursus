/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:58:09 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/23 09:32:01 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoll(char *nptr)
{
	long long int	nbr;
	int				neg;
	int				i;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (nbr * neg);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		str[n - 1] = '\0';
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	int				nb;

	nb = (nmemb * size);
	if (nmemb != 0 && nb / nmemb != size)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		mem = (unsigned char *)malloc(sizeof(char) * 1);
		mem[0] = '\0';
		return (mem);
	}
	mem = malloc(nb);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, (size_t)nb);
	return ((void *)mem);
}

t_list_a	*ft_lstnew_a(int content)
{
	t_list_a	*a;

	a = ft_calloc(sizeof(t_list_a), 1);
	if (!a)
		return (NULL);
	a->value = content;
	a->next = NULL;
	a->modified = 0;
	return (a);
}

void	ft_lstadd_back(t_list_a **lst, t_list_a *new)
{
	t_list_a	*cur;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}
