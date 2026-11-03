/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:18:50 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 15:37:55 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

/* HELPER FUNCTIONS */
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_put_un_int(unsigned int nbr);
int	ft_puthex(unsigned int nbr, char symbol);
int	ft_putptr(void *ptr);

#endif