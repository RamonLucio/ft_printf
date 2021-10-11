/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/11 17:15:43 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// Don't forget to remove below
/* #include <stdio.h>

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

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
} */

// Don't forget to remove above

int	ft_printf(const char *format, ...)
{
	va_list			arg_ptr;
	int 			chars_printed;
	unsigned char	char_value;
	char			*string_value;
	// int				ival;

	va_start(arg_ptr, format);
	chars_printed = 0;
	while (*format)
	{
		chars_printed++;
		if (*format != '%')
			ft_putchar_fd(*format++, 1);
		else
		{
			format++;
			if (*format == 'c')
			{
				char_value = va_arg(arg_ptr, int);
				ft_putchar_fd(char_value, 1);
				format++;
				continue ;
			}
			else if (*format == 's')
			{
				string_value = va_arg(arg_ptr, char *);
				chars_printed += ft_strlen(string_value) - 1;
				ft_putstr_fd(string_value, 1);
				format++;
				continue ;
			}
/* 			else if (*format == 'd')
			{
				ival = va_arg(arg_ptr, int);
				ft_putnbr_fd(ival, 1);
				format++;
				continue ;
			} */
			else
			{
				ft_putchar_fd(*format, 1);
				format++;
				continue ;
			}
		}
	}
	va_end(arg_ptr);
	return (chars_printed);
}

/* int main(void)
{
	ft_printf("%s", "");
	ft_printf(" %s", "");
	ft_printf("%s ", "");
	ft_printf(" %s ", "");
	ft_printf(" %s ", "-");
	ft_printf(" %s %s ", "", "-");
	ft_printf(" %s %s ", " - ", "");
	ft_printf(" %s %s %s %s ", " - ", "", "4", "");
	ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	ft_printf(" NULL %s NULL ", NULL);
	return (0);
} */
