/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:18:27 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 09:49:26 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_conversion(t_list *form, va_list *arg)
{
	int	i;

	i = 0;
	if (form->type == 'c' || form->type == '%')
		i = type_c(form, arg);
	else if (form->type == 's')
		i = type_s(form, arg);
	else if (form->type == 'p')
		i = type_p(form, arg);
	else if (form->type == 'd' || form->type == 'i')
		i = type_i(form, arg);
	else if (form->type == 'u')
		i = type_u(form, arg);
	else if (form->type == 'x' || form->type == 'X')
		i = type_x(form, arg);
	return (i);
}
