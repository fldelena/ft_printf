/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_side_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:09:51 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 19:42:26 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		left_side_up(char *str, t_list *form)
{
	int count;

	count = 0;
	while (*str == '-' || *str == '0')
	{
		str++;
		count++;
	}
	form->min_a = 1;
	return (count);
}
