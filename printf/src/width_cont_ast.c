/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_cont_ast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:36:16 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 14:34:24 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_cont_ast(t_list *form, va_list *arg)
{
	if (form->wid == 0)
	{
		form->wid = va_arg(*arg, int);
		if (form->wid < 0)
		{
			form->wid *= -1;
			form->min_a = 1;
		}
	}
	return (1);
}
