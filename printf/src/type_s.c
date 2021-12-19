/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:34:29 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/02 20:15:20 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_the_minus_b(t_list *form, char *str, int str_len)
{
	int		count;

	count = 0;
	if (form->min_a)
	{
		count += write(1, str, str_len);
		count += write_symbol((form->wid - str_len), ' ');
	}
	else
	{
		count += write_symbol((form->wid - str_len), ' ');
		count += write(1, str, str_len);
	}
	return (count);
}

int		with_the_minus_a(t_list *form, char *str, int str_len)
{
	int		count;

	count = 0;
	if (!form->dot || form->prec > str_len)
		form->prec = str_len;
	count += write(1, str, form->prec);
	count += write_symbol((form->wid - form->prec), ' ');
	return (count);
}

int		with_the_zero(t_list *form, char *str, int str_len)
{
	int		count;

	count = 0;
	if (!form->dot)
		form->prec = str_len;
	form->prec = form->prec >= str_len ? str_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->wid - form->prec), '0');
	count += write(1, str, form->prec);
	return (count);
}

int		without_anything(t_list *form, char *str, int str_len)
{
	int		count;

	count = 0;
	if (!form->dot)
		form->prec = str_len;
	form->prec = form->prec >= str_len ? str_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->wid - form->prec), ' ');
	count += write(1, str, form->prec);
	return (count);
}

int		type_s(t_list *form, va_list *arg)
{
	int		count;
	int		str_len;
	char	*str;

	str = va_arg(*arg, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	count = 0;
	if (form->min_b)
		count += with_the_minus_b(form, str, str_len);
	else if (form->min_a && !(form->min_b))
		count += with_the_minus_a(form, str, str_len);
	else if (form->zero)
		count += with_the_zero(form, str, str_len);
	else
		count += without_anything(form, str, str_len);
	return (count);
}
