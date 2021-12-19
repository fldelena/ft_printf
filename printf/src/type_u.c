/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:28:55 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/03 14:38:17 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_u_minus_b(t_list *form, size_t digit, int digit_len)
{
	int	count;

	count = 0;
	form->prec *= form->prec < 0 ? -1 : 1;
	if (form->min_a)
	{
		count += parse_u_int(digit);
		count += write_symbol((form->wid - digit_len), ' ');
	}
	else
	{
		if (form->zero)
			count += write_symbol((form->wid - digit_len), '0');
		else
			count += write_symbol((form->wid - digit_len), ' ');
		count += parse_u_int(digit);
	}
	return (count);
}

int		with_u_minus_a(t_list *form, size_t digit, int digit_len)
{
	int	count;

	count = 0;
	form->prec = digit_len >= form->prec ? digit_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->prec - digit_len), '0');
	count += parse_u_int(digit);
	count += write_symbol((form->wid - form->prec), ' ');
	return (count);
}

int		with_u_zero(t_list *form, size_t digit, int digit_len)
{
	int	count;

	count = 0;
	form->wid = digit_len >= form->wid ? digit_len : form->wid;
	count += write_symbol((form->wid - digit_len), '0');
	count += parse_u_int(digit);
	return (count);
}

int		without_u_anythin(t_list *form, size_t digit, int digit_len)
{
	int	count;

	count = 0;
	form->prec = digit_len >= form->prec ? digit_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->wid - form->prec), ' ');
	count += write_symbol((form->prec - digit_len), '0');
	count += parse_u_int(digit);
	return (count);
}

int		type_u(t_list *form, va_list *arg)
{
	int				count;
	unsigned int	digit;
	int				digit_len;

	count = 0;
	digit = va_arg(*arg, unsigned int);
	digit_len = len_of_u_digit(digit);
	if ((form->dot && (digit == 0)) && (form->prec == 0))
		count--;
	if (form->prec == 0 && digit == 0 && form->dot == 1)
		count += (empty_line(form, digit) + 2);
	else if (form->min_b)
		count += with_u_minus_b(form, digit, digit_len);
	else if (form->min_a && !(form->min_b))
		count += with_u_minus_a(form, digit, digit_len);
	else if (form->zero && !(form->dot))
		count += with_u_zero(form, digit, digit_len);
	else
		count += without_u_anythin(form, digit, digit_len);
	if (digit < 10 && digit >= 0)
		return (count + digit_len - 1);
	return (count + digit_len - 2);
}
