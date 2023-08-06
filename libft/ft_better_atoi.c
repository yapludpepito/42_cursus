/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:46:10 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/02 15:34:48 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this atoi is made to atoi and check overflow
// to check the over/underflow we will return a number of the opposite sign of ur number
// like that u could easily know if u have over/underflow or not
// u just have to look the sign of ur number

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}


int ft_check_int_overflow(const char *nptr)
{
    int check = 0;
    int len = ft_strlen(nptr);

    for (int i = 0; nptr[i] != '\0'; i++)
    {
        if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '-')
            return (0);
    }
    if (len < 10)
        return (0);
    if (len > 11)
        return (1);
    if (len == 10 && nptr[0] != '-')
        if (ft_strncmp("2147483647", nptr, 10) < 0)
            return (1);
    if (len == 11)
        if (ft_strncmp("-2147483648", nptr, 11) < 0)
            return (1);
    return (0);
}


int	ft_better_atoi(const char *nptr)
{
	int	nbr;
	int	neg;
	int	i;
    int check;
    int overflow;

	i = 0;
	neg = 1;
	nbr = 0;
    overflow = ft_check_int_overflow(nptr);
    if (overflow == 1 && nptr[0] == '-')
        return (1);
    else if (overflow == 1)
        return (-1);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			neg *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nbr >= 2147483647)
			return (-1);
		nbr = nbr * 10 + (nptr[i++] - 48);
	}
	return (nbr * neg);
}