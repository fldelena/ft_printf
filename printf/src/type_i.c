/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:36:32 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 20:21:02 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_i_minus_b(t_list *form, size_t digit, int digit_len, int sign)
{
	int	count;

	count = 0;
	if (!form->min_a)
	{
		form->wid -= sign < 0 ? 1 : 0;
		count += write_symbol(form->wid - digit_len, ' ');
	}
	if (sign < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		form->wid--;
	}
	ft_putnbr_fd(digit, 1);
	if (form->min_a)
	{
		if (form->wid > form->prec)
			count += write_symbol(form->wid - digit_len, ' ');
		if (form->wid == form->prec)
			count += write_symbol(form->wid - digit_len, ' ');
	}
	return (count);
}

int		with_i_minus_a(t_list *form, size_t digit, int digit_len, int sign)
{
	int	count;

	count = 0;
	form->prec = digit_len >= form->prec ? digit_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	if (sign < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		form->wid--;
	}
	count += write_symbol((form->prec - digit_len), '0');
	ft_putnbr_fd(digit, 1);
	count += write_symbol((form->wid - form->prec), ' ');
	return (count);
}

int		with_i_zero(t_list *form, size_t digit, int digit_len, int sign)
{
	int	count;

	count = 0;
	form->wid = digit_len >= form->wid ? digit_len : form->wid;
	if (sign < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		form->wid--;
	}
	count += write_symbol((form->wid - digit_len), '0');
	ft_putnbr_fd(digit, 1);
	return (count);
}

int		without_i_anythin(t_list *form, size_t digit, int digit_len, int sign)
{
	int	count;

	count = 0;
	if (form->prec < 0)
	{
		count += write_symbol((form->wid - digit_len), '0');
		ft_putnbr_fd(digit, 1);
	}
	else if (form->prec >= 0)
	{
		form->prec = digit_len >= form->prec ? digit_len : form->prec;
		form->wid = form->prec >= form->wid ? form->prec : form->wid;
		if (sign < 0)
		{
			count++;
			form->wid--;
		}
		count += write_symbol((form->wid - form->prec), ' ');
		if (sign < 0)
			ft_putchar_fd('-', 1);
		count += write_symbol((form->prec - digit_len), '0');
		ft_putnbr_fd(digit, 1);
	}
	return (count);
}

int		type_i(t_list *form, va_list *arg)
{
	int			count;
	int			sign;
	long long	digit;
	int			digit_len;

	count = 0;
	digit = va_arg(*arg, int);
	digit_len = len_of_digit(digit);
	sign = (digit >= 0) ? 1 : -1;
	digit *= (digit >= 0) ? 1 : -1;
	if (form->prec == 0 && digit == 0 && form->dot == 1)
		count += empty_line(form, digit);
	else if (form->min_b && !form->zero)
		count += with_i_minus_b(form, digit, digit_len, sign);
	else if (form->min_a && !(form->min_b))
		count += with_i_minus_a(form, digit, digit_len, sign);
	else if (form->zero && !(form->dot))
		count += with_i_zero(form, digit, digit_len, sign);
	else if (form->zero && form->min_b)
		count += zero_minus(form, digit, digit_len, sign);
	else
		count += without_i_anythin(form, digit, digit_len, sign);
	return (count + digit_len);
}
