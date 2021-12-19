/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:43:02 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 19:40:42 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*out_options(char *str, t_list *form, va_list *arg)
{
	init_of_flags(form);
	str++;
	if (*str == '0')
		str += zero_add(str, form);
	if (*str == '-')
		str += left_side_up(str, form);
	if (ft_isdigit(*str))
		str += width_control(str, form);
	else if (*str == '*')
		str += width_cont_ast(form, arg);
	if (*str == '.')
		str += accuracy_control(str, form, arg);
	str += type_identification(str, form);
	return (str);
}
