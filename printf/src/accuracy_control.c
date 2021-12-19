/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accuracy_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:51:11 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 22:34:30 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_accuracy(char *str, t_list *form)
{
	int	count;
	int number;

	count = 0;
	form->prec = ft_atoi(str);
	number = ft_atoi(str);
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

void	mini_function(t_list *form)
{
	if (form->prec < 0)
	{
		form->prec *= -1;
		form->min_b = 1;
	}
}

int		accuracy_control(char *str, t_list *form, va_list *arg)
{
	int count;

	count = 1;
	str++;
	form->dot = 1;
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			form->min_b = 1;
		str++;
		count++;
	}
	if (!ft_isdigit(*str))
		form->prec = 0;
	if (ft_isdigit(*str))
		count += is_accuracy(str, form);
	else if (*str == '*')
	{
		form->prec = va_arg(*arg, int);
		mini_function(form);
		count++;
	}
	return (count);
}
