/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:16:26 by fldelena          #+#    #+#             */
/*   Updated: 2021/01/30 14:04:34 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)(n * -1);
	}
	else
	{
		i = (unsigned int)n;
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((char)(i % 10 + 48), fd);
}
