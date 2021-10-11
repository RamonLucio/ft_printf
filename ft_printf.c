/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/11 13:39:48 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// Don't forget to remove below
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
// Don't forget to remove above

int	ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*sval;
	int			ival;
	double		dval;

	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format++, 1);
		else
		{
			format++;
			if (*format == 'd')
			{
				ival = va_arg(arg_ptr, int);
				printf("%d", ival);
				format++;
				continue ;
			}
			else if (*format == 'f')
			{
				dval = va_arg(arg_ptr, double);
				printf("%f", dval);
				format++;
				continue ;
			}
			else if (*format == 's')
			{
				sval = va_arg(arg_ptr, char *);
				ft_putstr_fd(sval, 1);
				format++;
				continue ;
			}
			else
			{
				ft_putchar_fd(*format, 1);
				format++;
				continue ;
			}
		}
	}
	va_end(arg_ptr);
	return (0);
}

int	main(void)
{
	char	*name;
	char	*pilpil;

	name = "Ramon";
	pilpil = "Formiga pilpil";
	ft_printf("Me chamo %s e moro com %s\n", name, pilpil);
	return (0);
}
