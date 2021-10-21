/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucio-l <rlucio-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:26 by rlucio-l          #+#    #+#             */
/*   Updated: 2021/10/21 19:02:50 by rlucio-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_char_fd(char character, int fd);
int		print_str_fd(char *string, int fd);
int		print_nbr_fd(int number, int fd);
char	*reverse_string(char *s);
char	*itoa_base(unsigned long number, int base, char specifier);

#endif
