/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/11 16:29:37 by rlucio-l         ###   ########.fr       */
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
} */
// Don't forget to remove above

int	ft_printf(const char *format, ...)
{
	va_list			arg_ptr;
	int 			char_counter;
	unsigned char	chval;
	char			*sval;
	int				ival;

	va_start(arg_ptr, format);
	char_counter = 0;
	while (*format)
	{
		char_counter++;
		if (*format != '%')
			ft_putchar_fd(*format++, 1);
		else
		{
			format++;
			if (*format == 'c')
			{
				chval = va_arg(arg_ptr, int);
				ft_putchar_fd(chval, 1);
				format++;
				continue ;
			}
/* 			if (*format == 'd')
			{
				ival = va_arg(arg_ptr, int);
				ft_putnbr_fd(ival, 1);
				format++;
				continue ;
			}
			else if (*format == 's')
			{
				sval = va_arg(arg_ptr, char *);
				ft_putstr_fd(sval, 1);
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
	return (char_counter);
}

/* int main(void)
{
	ft_printf("%c\n", '0');
	ft_printf(" %c \n", '0');
	ft_printf(" %c\n", '0' - 256);
	ft_printf("%c \n", '0' + 256);
	ft_printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	ft_printf(" %c %c %c \n", '1', '2', '3');
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n", 0, '1', '2');
	return (0);
} */
