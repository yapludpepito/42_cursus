/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:47:21 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/05 16:56:25 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_symbol(const char *s, va_list arg)
{
	int	len;

	len = 0;
	if (s[1] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (s[1] == 's')
	{
		len = ft_putlstr(va_arg(arg, char *));
		if (len == 0)
			return (-1);
	}
	else if (s[1] == 'p')
		return (ft_checkp(va_arg(arg, unsigned long)));
	else if (s[1] == 'd' || s[1] == 'i')
		return (ft_putlnbr_base(va_arg(arg, int), "0123456789"));
	return (len);
}

int	ft_check_symbol2(const char *s, va_list arg)
{
	int	len;

	len = 0;
	if (s[1] == 'u')
		len = ft_putunbr(va_arg(arg, unsigned int));
	else if (s[1] == 'x')
		len = ft_putunbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (s[1] == 'X')
		len = ft_putunbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (s[1] == '%')
		return (write(1, "%", 1));
	return (len);
}

int	ft_check(const char *s, va_list arg)
{
	int	count;

	count = 0;
	count += ft_check_symbol(s, arg);
	count += ft_check_symbol2(s, arg);
	if (count == -1)
		return (0);
	if (count == 0)
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	if (!s)
		return (0);
	va_start(arg, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			count += ft_check(&s[i++], arg);
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
