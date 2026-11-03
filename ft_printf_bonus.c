/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:23:52 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 17:44:49 by adorofei         ###   ########.fr       */
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

static int	check_conversion_bonus(char symbol, char extra, va_list *arg)
{
	if ((extra == '+' || extra == ' ') && ((symbol == 'd' || symbol == 'i')))
		return (ft_putnbr_bonus(va_arg(*arg, int), extra));
	else if (extra == '#' && (symbol == 'x' || symbol == 'X'))
		return (ft_puthex_bonus(va_arg(*arg, unsigned int), symbol, extra));
	return (check_conversion(symbol, arg));
}

static int	process_format(const char *format, size_t *i, va_list *arg)
{
	int		tmp;
	char	extra;

	if (format[*i] == '%' && !format[*i + 1])
		return (-2);
	if (format[*i] == '%')
	{
		(*i)++;
		extra = 0;
		if (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
		{
			extra = format[*i];
			(*i)++;
		}
		if (extra)
			tmp = check_conversion_bonus(format[*i], extra, arg);
		else
			tmp = check_conversion(format[*i], arg);
		return (tmp);
	}
	return (check_write(format[*i]));
}

int	ft_printf_bonus(const char *format, ...)
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
