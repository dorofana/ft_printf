/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:03:06 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/29 14:56:23 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long long nbr)
{
	int		tmp;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		tmp = ft_putptr_hex(nbr / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &base[nbr % 16], 1) == -1)
		return (-1);
	return (++count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	p;
	int					count;
	int					tmp;

	p = (unsigned long long)ptr;
	count = 2;
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		tmp = ft_putptr_hex(p);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	return (count);
}
