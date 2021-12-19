/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:38:47 by fldelena          #+#    #+#             */
/*   Updated: 2021/02/03 17:22:01 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_list
{
	char		type;
	int			wid;
	int			min_a;
	int			min_b;
	int			zero;
	int			prec;
	int			dot;
}				t_list;

int				ft_printf(const char *str, ...);
int				accuracy_control(char *str, t_list *form, va_list *arg);
int				ft_atoi(const char *str);
int				ft_isdigit(int ch);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *array);
void			init_of_flags(t_list *form);
int				left_side_up(char *str, t_list *form);
char			*out_options(char *str, t_list *form, va_list *arg);
int				type_c(t_list *form, va_list *arg);
int				type_conversion(t_list *form, va_list *arg);
int				type_i(t_list *form, va_list *arg);
int				type_identification(char *str, t_list *form);
int				type_p(t_list *form, va_list *arg);
int				type_s(t_list *form, va_list *arg);
int				type_u(t_list *form, va_list *arg);
int				type_x(t_list *form, va_list *arg);
int				width_cont_ast(t_list *form, va_list *arg);
int				width_control(char *str, t_list *form);
int				write_symbol(int count, char c);
int				zero_add(char *str, t_list *form);
int				len_of_digit(long digit);
void			putpointer(unsigned long long arg);
int				count_num_ptr(size_t pointer, t_list *form);
int				len_of_u_digit(long digit);
int				parse_u_int(unsigned int digit);
void			puthex(unsigned int x_digit, t_list *form);
int				count_num_hex(unsigned int x_digit);
int				empty_line(t_list *form, int digit);
int				zero_minus(t_list *form, size_t digit, int digit_len, int sign);
#endif
