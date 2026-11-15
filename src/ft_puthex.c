/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:01:44 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/29 12:49:25 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_puthex(unsigned int nbr, char symbol)
{
	if (symbol == 'x')
		return (case_base(nbr, "0123456789abcdef"));
	else
		return (case_base(nbr, "0123456789ABCDEF"));
}
