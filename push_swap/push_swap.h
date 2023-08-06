/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:09:48 by pdubacqu          #+#    #+#             */
/*   Updated: 2022/11/12 11:16:48 by pdubacqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_b
{
	void	*next;
	int		value;
}	t_list_b;

typedef struct s_list_a
{
	void	*next;
	int		value;
	int		modified;
}	t_list_a;

long long int	ft_atoll(char *nptr);

/*----------------------------------------------------------------------------*/

t_list_a		*ft_lstnew_a(int content);
t_list_a		*ft_swap_a(t_list_a *lst, int ss);
t_list_a		*ft_rra(t_list_a *lst);
t_list_a		*ft_make_three(t_list_a	*lst_a);
t_list_a		*ft_ra(t_list_a *lst);
t_list_a		*ft_make_3_next(t_list_a *fvalue, t_list_a *svalue,
					t_list_a *lst_a);

/*----------------------------------------------------------------------------*/

t_list_a		*ft_pa(t_list_a *lst_a, t_list_b **lst_b);
t_list_a		*ft_make_five(t_list_a *lst_a);
t_list_a		*ft_make_five_four(t_list_a *lst_a);
t_list_a		*ft_endfive(t_list_a *lst_a);
t_list_a		*ft_endfive_next(t_list_a *lst_a);
t_list_a		*ft_third_bigger(t_list_a *lst_a);
t_list_a		*swap_value(t_list_a *lst);
t_list_a		*ft_assign_value(t_list_a *lst, int i);
t_list_a		*ft_make_big_list(t_list_a *lst, int len);
t_list_a		*ft_make_lst(int argc, char **argv);
t_list_b		*ft_pb(t_list_a **lst_a, t_list_b *lst_b);
t_list_b		*ft_lstnew_b(int content);
t_list_b		*ft_rrb(t_list_b *lst);
t_list_b		*ft_swap_b(t_list_b *lst, int ss);
t_list_b		*ft_first_pb(t_list_a **lst_a);
t_list_b		*ft_rb(t_list_b *lst);

/*----------------------------------------------------------------------------*/

int				ft_check_list(t_list_a *lst);
int				ft_check_swap_value(t_list_a *lst);
int				ft_lstlen(t_list_a *lst);
int				ft_check_arg(char **argv, int argc);
int				find_min_value(t_list_a *lst_a);
int				ft_is_sorted(t_list_a *lst);

/*----------------------------------------------------------------------------*/

void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_lstadd_back(t_list_a **lst, t_list_a *new);
void			ft_rrr(t_list_a **a, t_list_b **b);
void			ft_ss(t_list_a **a, t_list_b **b);
void			ft_free_lst(t_list_a *lst);
void			ft_check_str(char **str);
void			ft_check_node(char *str, t_list_a *lst);
void			ft_check_node_first(char *str);
void			ft_check_str_next(char **str);

/*----------------------------------------------------------------------------*/

char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

/*----------------------------------------------------------------------------*/

size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *s);

#endif
