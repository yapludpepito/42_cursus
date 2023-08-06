/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_isalnum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:06 by pdubacqu          #+#    #+#             */
/*   Updated: 2023/01/16 14:19:31 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_free(char *alo)
{
	free(alo);
	return (0);
}

int	ft_check_alnum_export(char *alo, int i, int cnt)
{
	return ((!ft_isalpha(alo[i]) && alo[i] != '_' && \
				alo[i] != '=' && alo[i] != '+' && !ft_isdigit(alo[i])) \
				&& ((cnt == 0 && alo[i] == ':') \
				|| (cnt == 0 && alo[i] == '/')));
}

int	ft_export_isalnum(const char *s)
{
	int		i;
	int		cnt;
	char	*alo;

	i = -1;
	cnt = 0;
	alo = ft_strtrim(s, "\"");
	if (ft_isdigit(s[0]))
		return (check_free(alo));
	while (++i < (int)ft_strlen(alo))
	{
		if (alo[i] == '=')
			cnt++;
		if (cnt > 1)
			return (check_free(alo));
		if (ft_check_alnum_export(alo, i, cnt))
			return (check_free(alo));
		if (alo[i] == '+' && alo[i + 1] != '=')
			return (check_free(alo));
		if (alo[i] == '+' && alo[i + 1] == '=' && !alo[i + 2])
			return (check_free(alo));
	}
	free(alo);
	return (1);
}
