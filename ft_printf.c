/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:03:03 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/20 07:10:44 by rlucio-l         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
		ft_putnbr_fd((nbr / 10), fd);
	ft_putchar_fd(((nbr % 10) + '0'), fd);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = malloc(sizeof(char) * (ft_count_digits(n) + 1));
	if (!s)
		return (NULL);
	sign = n;
	if (n < 0)
		n = -n;
	i = 0;
	while (n)
	{
		s[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse_string(s);
	return (s);
}

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
} */
// Don't forget to remove above

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

static char	*itob(unsigned long number, int base, char specifier)
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

int	ft_printf(const char *format, ...)
{
	va_list			arg_ptr;
	int				chars_printed;
	unsigned char	character;
	char			*string;
	unsigned long	pointer;
	signed int		signed_integer;
	unsigned int	unsigned_integer;

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
				character = (unsigned char) va_arg(arg_ptr, int);
				ft_putchar_fd(character, 1);
				format++;
				continue ;
			}
			else if (*format == 's')
			{
				string = va_arg(arg_ptr, char *);
				if (string == NULL)
				{
					chars_printed += 5;
					ft_putstr_fd("(null)", 1);
					format++;
					continue ;
				}
				else
				{
					chars_printed += ft_strlen(string) - 1;
					ft_putstr_fd(string, 1);
					format++;
					continue ;
				}
			}
			else if (*format == 'p')
			{
				ft_putstr_fd("0x", 1);
				chars_printed += 2;
				pointer = (unsigned long) va_arg(arg_ptr, void *);
				if (pointer == 0)
				{
					ft_putstr_fd("0", 1);
					format++;
					continue ;
				}
				string = itob(pointer, 16, *format);
				ft_putstr_fd(string, 1);
				chars_printed += ft_strlen(string) - 1;
				free(string);
				format++;
				continue ;
			}
			else if (*format == 'd' || *format == 'i')
			{
				signed_integer = (signed int) va_arg(arg_ptr, int);
				ft_putnbr_fd(signed_integer, 1);
				string = ft_itoa(signed_integer);
				chars_printed += ft_strlen(string) - 1;
				free(string);
				format++;
				continue ;
			}
			else if (*format == 'u')
			{
				unsigned_integer = (unsigned int) va_arg(arg_ptr, int);
				string = itob(unsigned_integer, 10, *format);
				ft_putstr_fd(string, 1);
				chars_printed += ft_strlen(string) - 1;
				free(string);
				format++;
				continue ;
			}
			else if (*format == 'x')
			{
				unsigned_integer = (unsigned int) va_arg(arg_ptr, int);
				string = itob(unsigned_integer, 16, *format);
				ft_putstr_fd(string, 1);
				chars_printed += ft_strlen(string) - 1;
				free(string);
				format++;
				continue ;
			}
			else if (*format == 'X')
			{
				unsigned_integer = (unsigned int) va_arg(arg_ptr, int);
				string = itob(unsigned_integer, 16, *format);
				ft_putstr_fd(string, 1);
				chars_printed += ft_strlen(string) - 1;
				free(string);
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
	return (chars_printed);
}

/* int main(void)
{
	ft_printf("%X", 16);
	return (0);
} */
