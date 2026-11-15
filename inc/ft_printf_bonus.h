/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:23:31 by adorofei          #+#    #+#             */
/*   Updated: 2026/08/31 17:45:41 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int	ft_printf_bonus(const char *format, ...);

/* HELPER FUNCTIONS */
int	ft_putnbr_bonus(int nbr, char extra);
int	ft_puthex_bonus(unsigned int nbr, char symbol, char extra);

#endif
