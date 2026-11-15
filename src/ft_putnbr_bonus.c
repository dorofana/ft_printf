/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:49:06 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 17:45:38 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_write(char c)
{
	int	count;

	count = 0;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++count);
}

int	ft_putnbr_bonus(int nbr, char extra)
{
	int		count;
	int		tmp;

	count = 0;
	if (nbr >= 0)
	{
		if (extra == '+' || extra == ' ')
		{
			tmp = check_write(extra);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
	}
	tmp = ft_putnbr(nbr);
	if (tmp == -1)
		return (-1);
	return (count + tmp);
}
