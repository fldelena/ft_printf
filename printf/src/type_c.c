/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:19:18 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 10:35:27 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		until_type_c(t_list *form, char *c, va_list *arg)
{
	int count;

	count = 0;
	if (form->type == 'c')
		*c = va_arg(*arg, int);
	else
		*c = '%';
	if (form->min_a || form->min_b)
		form->zero = 0;
	if (form->zero)
	{
		count += write_symbol((form->wid) - 1, '0');
		ft_putchar_fd(*c, 1);
	}
	return (count);
}

int		type_c(t_list *form, va_list *arg)
{
	int		count;
	char	c;

	count = 1;
	count += until_type_c(form, &c, arg);
	if (form->min_b)
	{
		form->prec *= form->prec < 0 ? -1 : 1;
		ft_putchar_fd(c, 1);
		count += write_symbol((form->prec) - 1, ' ');
	}
	else if ((form->min_a) && !(form->min_b))
	{
		ft_putchar_fd(c, 1);
		count += write_symbol((form->wid) - 1, ' ');
	}
	else if (!form->zero)
	{
		count += write_symbol((form->wid) - 1, ' ');
		ft_putchar_fd(c, 1);
	}
	return (count);
}
