/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_toupper.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jlarrieu <jlarrieu@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/09/27 10:17:44 by jlarrieu		  #+#	#+#			 */
/*   Updated: 2022/09/30 14:05:37 by jlarrieu		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}