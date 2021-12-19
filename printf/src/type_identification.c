/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_identification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:20:57 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/01 09:51:22 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_identification(char *str, t_list *form)
{
	if (*str == 'c')
		form->type = 'c';
	else if (*str == 's')
		form->type = 's';
	else if (*str == 'p')
		form->type = 'p';
	else if (*str == 'd')
		form->type = 'd';
	else if (*str == 'i')
		form->type = 'i';
	else if (*str == 'u')
		form->type = 'u';
	else if (*str == 'x')
		form->type = 'x';
	else if (*str == 'X')
		form->type = 'X';
	else if (*str == '%')
		form->type = '%';
	return (1);
}
