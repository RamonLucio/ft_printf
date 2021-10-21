/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/21 15:40:11 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
	return (1);
}

static int	putstr_fd(char *s, int fd)
{
	char	*p;

	p = s;
	if (p == NULL)
		return (putstr_fd("(null)", 1));
	while (*s)
	{
		putchar_fd(*s, fd);
		s++;
	}
	return (s - p);
}

static int	putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				chars_printed;

	chars_printed = 0;
	if (n < 0)
	{
		chars_printed += putchar_fd('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
		chars_printed += putnbr_fd((nbr / 10), fd);
	chars_printed += putchar_fd(((nbr % 10) + '0'), fd);
	return (chars_printed);
}

static char	*reverse_string(char *s)
{
	int		first_index;
	int		last_index;
	char	temp;

	first_index = 0;
	last_index = ft_strlen(s) - 1;
	while (first_index < last_index)
	{
		temp = s[first_index];
		s[first_index] = s[last_index];
		s[last_index] = temp;
		first_index++;
		last_index--;
	}
	return (s);
}

static char	*itoa_base(unsigned long number, int base, char specifier)
{
	char	*digits;
	char	*string;
	int		i;
	int		uppercase_shift;

	digits = "0123456789abcdef0123456789ABCDEF";
	string = malloc(42);
	i = 0;
	if (specifier == 'X')
		uppercase_shift = 16;
	else
		uppercase_shift = 0;
	string[i++] = digits[(number % base) + uppercase_shift];
	number /= base;
	while (number > 0)
	{
		string[i++] = digits[(number % base) + uppercase_shift];
		number /= base;
	}
	string[i] = '\0';
	reverse_string(string);
	return (string);
}

static void	put_arg(char spec, va_list arg_ptr, int *chars_printed)
{
	char	*str;

	if (spec == 'c')
		*chars_printed += putchar_fd(va_arg(arg_ptr, int), 1);
	else if (spec == 's')
		*chars_printed += putstr_fd(va_arg(arg_ptr, char *), 1);
	else if (spec == 'd' || spec == 'i')
		*chars_printed += putnbr_fd(va_arg(arg_ptr, int), 1);
	else if (spec == 'p')
	{
		str = itoa_base((unsigned long) va_arg(arg_ptr, void *), 16, spec);
		*chars_printed += putstr_fd("0x", 1) + putstr_fd(str, 1);
		free(str);
	}
	else if (spec == 'u' || spec == 'x' || spec == 'X')
	{
		if (spec == 'u')
			str = itoa_base((unsigned int) va_arg(arg_ptr, int), 10, spec);
		else if (spec == 'x' || spec == 'X')
			str = itoa_base((unsigned int) va_arg(arg_ptr, int), 16, spec);
		*chars_printed += putstr_fd(str, 1);
		free(str);
	}
	else
		*chars_printed += putchar_fd(spec, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	int			chars_printed;

	va_start(arg_ptr, format);
	chars_printed = 0;
	while (*format)
	{
		if (*format != '%')
			chars_printed += putchar_fd(*format++, 1);
		else
		{
			format++;
			put_arg(*format, arg_ptr, &chars_printed);
			format++;
			continue ;
		}
	}
	va_end(arg_ptr);
	return (chars_printed);
}
