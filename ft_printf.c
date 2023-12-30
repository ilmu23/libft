/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:28:21 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:40:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 */

#include "libft.h"

/** @brief Prints the format string
 *
 * Prints the format string replacing all occurences of %[%csdiupx]
 * with the next argument in the va_list
 * @param *s Format string to print
 * @param ... Arguments for format string conversions
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;
	int		out;

	if (!s)
		return (-1);
	ret = 1;
	out = 0;
	va_start(args, s);
	while (*s && ret >= 0)
	{
		if (*s != '%')
			ret = ft_putchar_fd(*s, 1);
		else
			ret = ft_printformat(&s, args);
		out += ret;
		s++;
	}
	va_end(args);
	if (ret < 0)
		return (-1);
	return (out);
}

/** @brief NULL checks the character after the %
 *
 * @param **f Address of the pointer to the current position in the format string
 * @param args va_list containing the variable to print
 * @retval int Amount of characters printed or -1 if an error occurred
 */
int	ft_printformat(const char **f, va_list args)
{
	(*f)++;
	if (!(**f))
		return (0);
	return (ft_putarg(f, args));
}
