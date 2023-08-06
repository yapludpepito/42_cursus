/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:28:31 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/10/05 17:04:05 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putlstr(char *s);
int		ft_check_symbol(const char *s, va_list arg);
int		ft_check_symbol2(const char *s, va_list arg);
int		ft_printf(const char *s, ...);
int		ft_count_base(int nb, int len_base);
void	ft_make_nbr(int nb, int len_base, char *base);
int		ft_putlnbr_base(int nbr, char *base);
int		ft_putchar(char c);
int		ft_ucount(unsigned int nb);
int		ft_putunbr(unsigned int n);
int		ft_countul_base(unsigned long nb, int len_base);
void	ft_makeul_nbr(unsigned long nbr, int len_base, char *base);
int		ft_putulnbr_base(unsigned long nbr, char *base);
int		ft_strlen(char *str);
int		ft_countll_base(long long int nb, int len_base);
void	ft_makell_nbr(long long int nb, int len_base, char *base);
int		ft_putllnbr_base(long long int nbr, char *base);
int		ft_countu_base(unsigned int nbr, int len_base);
void	ft_makeu_nbr(unsigned int nbr, int len_base, char *base);
int		ft_putunbr_base(unsigned int nbr, char *base);
int		ft_check(const char *s, va_list arg);
int		ft_checkp(unsigned long nbr);

#endif
