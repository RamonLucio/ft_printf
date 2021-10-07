/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/06 16:22:51 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	char		*p;
	char		*sval;
	int			ival;
	double		dval;

	va_start(arg_ptr, format);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival = va_arg(arg_ptr, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(arg_ptr, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(arg_ptr, char *); *sval; sval++)
				putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(arg_ptr); /* clean up when done */
}
