/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:51 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 13:56:55 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	empty_line(t_list *form, int digit)
{
	int count;

	count = 0;
	if (form->prec == 0 && digit == 0 && form->dot == 1)
	{
		count += write_symbol(form->wid, ' ');
		count--;
	}
	return (count);
}
