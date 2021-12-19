/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:19:38 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 20:03:31 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		with_minus_b(t_list *form, size_t pointer, int pointer_len)
{
	int	count;

	count = 0;
	form->prec *= form->prec < 0 ? -1 : 1;
	form->wid = (form->prec == 0) ? form->wid : form->prec;
	ft_putstr_fd("0x", 1);
	putpointer(pointer);
	count += write_symbol((form->wid - pointer_len), ' ');
	return (count);
}

int		with_minus_a(t_list *form, size_t pointer, int pointer_len)
{
	int	count;
	int	diff;

	count = 0;
	diff = (form->prec - pointer_len + 2) == 1 ? 1 : 2;
	diff = (form->prec - pointer_len + 2) <= 0 ? 0 : diff;
	form->prec = pointer_len >= form->prec ? pointer_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	ft_putstr_fd("0x", 1);
	count += write_symbol((form->prec - pointer_len + diff), '0');
	putpointer(pointer);
	count += write_symbol((form->wid - form->prec - diff), ' ');
	return (count);
}

int		with_zero(t_list *form, size_t pointer, int pointer_len)
{
	int	count;

	count = 0;
	form->wid = pointer_len >= form->wid ? pointer_len : form->wid;
	ft_putstr_fd("0x", 1);
	count += write_symbol((form->wid - pointer_len), '0');
	putpointer(pointer);
	return (count);
}

int		without_anythin(t_list *form, size_t pointer, int pointer_len)
{
	int	count;
	int	diff;

	count = 0;
	diff = (form->prec - pointer_len + 2) == 1 ? 1 : 2;
	diff = (form->prec - pointer_len + 2) <= 0 ? 0 : diff;
	form->prec = pointer_len >= form->prec ? pointer_len : form->prec;
	form->wid = form->prec >= form->wid ? form->prec : form->wid;
	count += write_symbol((form->wid - form->prec - diff), ' ');
	ft_putstr_fd("0x", 1);
	count += write_symbol((form->prec - pointer_len + diff), '0');
	putpointer(pointer);
	return (count);
}

int		type_p(t_list *form, va_list *arg)
{
	int				count;
	int				pointer_len;
	size_t			pointer;

	count = 0;
	pointer = va_arg(*arg, unsigned long long);
	pointer_len = count_num_ptr(pointer, form);
	if (form->min_a || form->min_b)
		form->zero = 0;
	if (form->min_b)
		count += with_minus_b(form, pointer, pointer_len);
	else if (form->min_a && !(form->min_b))
		count += with_minus_a(form, pointer, pointer_len);
	else if (form->zero && !(form->dot))
		count += with_zero(form, pointer, pointer_len);
	else
		count += without_anythin(form, pointer, pointer_len);
	return (count + pointer_len);
}
