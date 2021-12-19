/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:01:19 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 20:01:45 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex(unsigned int x_digit, t_list *form)
{
	int		dif;
	int		mod;
	int		x;
	int		chr;

	chr = '0';
	dif = 0;
	mod = 0;
	x = 'a';
	mod = x_digit % 16;
	dif = x_digit / 16;
	if (form->type == 'X')
		x = 'A';
	if (dif != 0)
		puthex(dif, form);
	if (mod >= 10)
	{
		chr = mod + x - 10;
		write(1, &chr, 1);
	}
	else
	{
		chr += mod;
		write(1, &chr, 1);
	}
}

int		count_num_hex(unsigned int x_digit)
{
	int		count;

	count = 0;
	while (x_digit > 0)
	{
		x_digit /= 16;
		count++;
	}
	return (count);
}
