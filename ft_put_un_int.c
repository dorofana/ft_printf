/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:00:54 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 18:07:59 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_un_int(unsigned int nbr)
{
	char	c;
	int		count;
	int		tmp;

	count = 0;
	if (nbr >= 10)
	{
		tmp = ft_put_un_int(nbr / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++count);
}
