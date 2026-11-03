/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:37:10 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 16:03:43 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	case_base(unsigned int nbr, char *base)
{
	int		tmp;
	int		count;

	count = 0;
	if (nbr >= 16)
	{
		tmp = case_base(nbr / 16, base);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &base[nbr % 16], 1) == -1)
		return (-1);
	return (++count);
}

int	ft_puthex_bonus(unsigned int nbr, char symbol, char extra)
{
	int	tmp;
	int	count;

	count = 0;
	if (extra == '#' && nbr != 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		count++;
		if (write(1, &symbol, 1) == -1)
			return (-1);
		count++;
	}
	if (symbol == 'x')
		tmp = (case_base(nbr, "0123456789abcdef"));
	else
		tmp = (case_base(nbr, "0123456789ABCDEF"));
	if (tmp == -1)
		return (-1);
	return (count + tmp);
}
