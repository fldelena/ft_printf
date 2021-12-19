/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:57:58 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 19:58:31 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_of_u_digit(long digit)
{
	int	count;

	count = 0;
	if (digit == 0)
		return (1);
	while (digit > 0)
	{
		digit /= 10;
		count++;
	}
	return (count);
}

int		parse_u_int(unsigned int digit)
{
	int mod;
	int dif;
	int count;
	int chr;

	mod = 0;
	dif = 0;
	count = 1;
	chr = '0';
	mod = digit % 10;
	dif = digit / 10;
	if (dif != 0)
	{
		parse_u_int(dif);
		count++;
	}
	chr += mod;
	write(1, &chr, 1);
	return (count);
}
