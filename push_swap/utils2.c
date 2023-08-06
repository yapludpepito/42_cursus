/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:46:46 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/27 15:54:14 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*ft_lstnew_b(int content)
{
	t_list_b	*b;

	b = ft_calloc(sizeof(t_list_b), 1);
	if (!b)
		return (NULL);
	b->value = content;
	b->next = NULL;
	return (b);
}

void	ft_free_lst(t_list_a *lst)
{
	t_list_a	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	**ft_make_split(char const *s, char c, char **dest, int n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			i++;
			if (s[i] == c || (s[i] == '\0' && n < ft_count_word(s, c)))
			{
				dest[n] = ft_calloc(sizeof(char), len + 1);
				ft_strlcpy(dest[n], &s[i - len], len + 1);
				len = 0;
				n++;
			}
		}
	}
	dest[n] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		count_word;

	if (!(s))
		return (NULL);
	count_word = ft_count_word(s, c);
	dest = ft_calloc(sizeof(char *), count_word + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_make_split(s, c, dest, 0);
	return (dest);
}
