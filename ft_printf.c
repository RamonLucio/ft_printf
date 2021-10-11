/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/08 23:04:30 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//  NÃO ESQUEÇA DE REMOVER, FILA DA PUTA!
#include <stdio.h>

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
		{
			ft_putchar_fd(*format, 1);
			format++;
			continue;
		}
		switch (*++format)
		{
			case 'd':
				ival = va_arg(arg_ptr, int);
				printf("%d", ival);
				format++;
				break;
			case 'f':
				dval = va_arg(arg_ptr, double);
				printf("%f", dval);
				format++;
				break;
			case 's':
				for (sval = va_arg(arg_ptr, char *); *sval; sval++)
					ft_putchar_fd(*sval, 1);
				format++;
				break;
			default:
				ft_putchar_fd(*format, 1);
				format++;
				break;
		}
	}
	va_end(arg_ptr); /* clean up when done */
	return (0);
}

int main(void)
{
	char	*name = "Ramon";
	char	*pilpil = "Formiga pilpil";

	ft_printf("Me chamo %s e moro com %s\n", name, pilpil);
	return (0);
}
