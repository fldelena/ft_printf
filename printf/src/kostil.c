/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:03:50 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 22:29:19 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_minus(t_list *form, size_t digit, int digit_len, int sign)
{
	int	count;

	count = 0;
	if (sign < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		form->wid--;
	}
	if (!form->min_a)
		count += write_symbol((form->wid - digit_len), '0');
	ft_putnbr_fd(digit, 1);
	if (form->min_a)
		count += write_symbol((form->wid - digit_len), ' ');
	return (count);
}
