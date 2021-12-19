/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:45:26 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/30 14:06:45 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_symbol(int count, char c)
{
	int	n;

	n = 0;
	if (count <= 0)
		return (n);
	while (count > n)
	{
		n += write(1, &c, 1);
	}
	return (n);
}
