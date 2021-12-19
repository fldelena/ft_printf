/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 05:00:50 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/02 22:27:30 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_x_minus_b(t_list *form, size_t x_digit, int len_x_digit)
{
	int	count;

	count = 0;
	if (form->min_a)
	{
		puthex(x_digit, form);
		count += write_symbol((form->wid - len_x_digit), ' ');
	}
	else
	{
		if (form->zero)
			count += write_symbol((form->wid - len_x_digit), '0');
		else
			count += write_symbol((form->wid - len_x_digit), ' ');
		puthex(x_digit, form);
	}
	return (count);
}

int		with_x_minus_a(t_list *form, size_t x_digit, int len_x_digit)
{
	int	count;

	count = 0;
	form->prec = len_x_digit >= form->prec ? len_x_digit : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->prec - len_x_digit), '0');
	puthex(x_digit, form);
	count += write_symbol((form->wid - form->prec), ' ');
	return (count);
}

int		with_x_zero(t_list *form, size_t x_digit, int len_x_digit)
{
	int	count;

	count = 0;
	form->wid = len_x_digit >= form->wid ? len_x_digit : form->wid;
	count += write_symbol((form->wid - len_x_digit), '0');
	puthex(x_digit, form);
	return (count);
}

int		without_x_anythin(t_list *form, size_t x_digit, int len_x_digit)
{
	int	count;

	count = 0;
	form->prec = len_x_digit >= form->prec ? len_x_digit : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->wid - form->prec), ' ');
	count += write_symbol((form->prec - len_x_digit), '0');
	puthex(x_digit, form);
	return (count);
}

int		type_x(t_list *form, va_list *arg)
{
	int				count;
	unsigned int	x_digit;
	int				len_x_digit;

	count = 0;
	x_digit = va_arg(*arg, unsigned int);
	if (x_digit == 0)
		len_x_digit = 1;
	else
		len_x_digit = count_num_hex(x_digit);
	if (form->prec == 0 && x_digit == 0 && form->dot == 1)
		count += empty_line(form, x_digit);
	else if (form->min_b)
		count += with_x_minus_b(form, x_digit, len_x_digit);
	else if (form->min_a && !(form->min_b))
		count += with_x_minus_a(form, x_digit, len_x_digit);
	else if (form->zero && !(form->dot))
		count += with_x_zero(form, x_digit, len_x_digit);
	else
		count += without_x_anythin(form, x_digit, len_x_digit);
	return (count + len_x_digit);
}
