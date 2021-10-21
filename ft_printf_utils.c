/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:18:30 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/21 19:04:27 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** 		Outputs 'character' to the given file descriptor.
** RETURN VALUE
** 		Returns the	number of characters printed.
*/

int	print_char_fd(char character, int fd)
{
	write(fd, &character, sizeof(character));
	return (1);
}

/*
** DESCRIPTION
** 		Outputs 'string' to the given file descriptor.
** RETURN VALUE
** 		Returns the	number of characters printed.
*/

int	print_str_fd(char *string, int fd)
{
	char	*pointer;

	pointer = string;
	if (pointer == NULL)
		return (print_str_fd("(null)", 1));
	while (*string)
	{
		print_char_fd(*string, fd);
		string++;
	}
	return (string - pointer);
}

/*
** DESCRIPTION
** 		Outputs 'number' to the given file descriptor.
** RETURN VALUE
** 		Returns the	number of characters printed.
*/

int	print_nbr_fd(int number, int fd)
{
	unsigned int	unsigned_number;
	int				chars_printed;

	chars_printed = 0;
	if (number < 0)
	{
		chars_printed += print_char_fd('-', fd);
		unsigned_number = -number;
	}
	else
		unsigned_number = number;
	if (unsigned_number > 9)
		chars_printed += print_nbr_fd((unsigned_number / 10), fd);
	chars_printed += print_char_fd(((unsigned_number % 10) + '0'), fd);
	return (chars_printed);
}

char	*reverse_string(char *s)
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

/*
** DESCRIPTION
** 		Allocates (with malloc(3)) and returns a string
** 		representing the integer received as an argument
**		converted to a given base.
** RETURN VALUE
** 		The string representing the integer converted.
**		NULL if the allocation fails.
*/

char	*itoa_base(unsigned long number, int base, char specifier)
{
	char	*digits;
	char	*string;
	int		i;
	int		uppercase_shift;

	digits = "0123456789abcdef0123456789ABCDEF";
	string = malloc(42);
	if (!string)
		return (NULL);
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
