/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:49:00 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/30 14:06:49 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_add(char *str, t_list *form)
{
	int	count;

	count = 0;
	while (*str == '0')
	{
		str++;
		count++;
	}
	form->zero = 1;
	return (count);
}
