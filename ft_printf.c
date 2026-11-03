/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:26:31 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 15:37:46 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_write(char c)
{
	int	count;

	count = 0;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++count);
}

static int	check_conversion(char symbol, va_list *arg)
{
	int	printed;

	printed = 0;
	if (symbol == '%')
	{
		printed = check_write('%');
		if (printed == -1)
			return (-1);
	}
	else if (symbol == 'd' || symbol == 'i')
		printed = ft_putnbr(va_arg(*arg, int));
	else if (symbol == 's')
		printed = ft_putstr(va_arg(*arg, char *));
	else if (symbol == 'p')
		printed = ft_putptr(va_arg(*arg, void *));
	else if (symbol == 'u')
		printed = ft_put_un_int(va_arg(*arg, unsigned int));
	else if (symbol == 'x' || symbol == 'X')
		printed = ft_puthex(va_arg(*arg, unsigned int), symbol);
	else if (symbol == 'c')
		printed = check_write(va_arg(*arg, int));
	return (printed);
}

static int	process_format(const char *format, size_t *i, va_list *arg)
{
	int	tmp;

	if (format[*i] == '%' && !format[*i + 1])
		return (-2);
	if (format[*i] == '%')
	{
		tmp = check_conversion(format[*i + 1], arg);
		(*i)++;
		return (tmp);
	}
	return (check_write(format[*i]));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		tmp = process_format(format, &i, &arg);
		if (tmp == -2)
			break ;
		if (tmp == -1)
		{
			va_end(arg);
			return (-1);
		}
		count += tmp;
		i++;
	}
	va_end(arg);
	return (count);
}
