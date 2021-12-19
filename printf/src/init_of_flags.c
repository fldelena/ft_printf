/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_of_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:09:08 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/31 19:42:51 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_of_flags(t_list *form)
{
	form->type = 0;
	form->wid = 0;
	form->min_a = 0;
	form->min_b = 0;
	form->zero = 0;
	form->prec = 0;
	form->dot = 0;
}
