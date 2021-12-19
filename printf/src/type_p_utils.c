/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:02:50 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 20:04:41 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putpointer(unsigned long long arg)
{
	unsigned long long	mod;
	unsigned long long	dif;
	char				chr;
	int					x;

	x = 'a';
	chr = '0';
	dif = 0;
	mod = 0;
	mod = arg % 16;
	dif = arg / 16;
	if (dif != 0)
		putpointer(dif);
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

int		count_num_ptr(size_t pointer, t_list *form)
{
	int	i;

	i = 0;
	if (form->prec == 0 && form->dot == 1 && pointer == 0)
		return (2);
	else if (pointer == 0)
		return (3);
	while (pointer > 0)
	{
		pointer /= 16;
		i++;
	}
	return (i + 2);
}
