/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:59:37 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 20:00:26 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_of_digit(long digit)
{
	int	count;

	count = 0;
	if (digit == 0)
		return (1);
	else if (digit < 0)
		digit *= -1;
	while (digit > 0)
	{
		digit /= 10;
		count++;
	}
	return (count);
}
