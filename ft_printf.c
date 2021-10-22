/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/22 16:15:02 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** 			print_arg receives an argument pointer from ft_printf and
** 			calls va_arg on that argument to retrieve a value. Furthermore,
** 			print_arg print the value according to the conversion specifiers
** 			and counts characters printed.
*/

static void	print_arg(char specifier, va_list ap, int *chars_printed)
{
	char	*str;

	if (specifier == 'c')
		*chars_printed += print_char_fd(va_arg(ap, int), 1);
	else if (specifier == 's')
		*chars_printed += print_str_fd(va_arg(ap, char *), 1);
	else if (specifier == 'd' || specifier == 'i')
		*chars_printed += print_nbr_fd(va_arg(ap, int), 1);
	else if (specifier == 'p')
	{
		str = itoa_base((unsigned long) va_arg(ap, void *), 16, specifier);
		*chars_printed += print_str_fd("0x", 1) + print_str_fd(str, 1);
		free(str);
	}
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X')
	{
		if (specifier == 'u')
			str = itoa_base((unsigned int) va_arg(ap, int), 10, specifier);
		else
			str = itoa_base((unsigned int) va_arg(ap, int), 16, specifier);
		*chars_printed += print_str_fd(str, 1);
		free(str);
	}
	else
		*chars_printed += print_char_fd(specifier, 1);
}

/*
** DESCRIPTION
** 			ft_printf mimic some functionality of the real printf,
** 			which writes the output under the control of a format string
** 			that specifies how arguments accessed via the variable-length
** 			argument facilities of stdarg(3)) are converted for output.
** RETURN VALUES
** 			ft_printf returns the number of characters printed
** 			(not including the trailing `\0' used to end output to strings).
*/

int	ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	int			chars_printed;

	va_start(arg_ptr, format);
	chars_printed = 0;
	while (*format)
	{
		if (*format != '%')
			chars_printed += print_char_fd(*format, 1);
		else
			print_arg(*++format, arg_ptr, &chars_printed);
		format++;
	}
	va_end(arg_ptr);
	return (chars_printed);
}
