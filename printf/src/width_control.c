/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:50:18 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 19:44:32 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_control(char *str, t_list *form)
{
	int		count;
	long	number;

	count = 0;
	if (form->wid == 0)
	{
		form->wid = ft_atoi(str);
		number = ft_atoi(str);
		if (number == 0)
			return (1);
		while (number > 0)
		{
			number /= 10;
			count++;
		}
	}
	return (count);
}
