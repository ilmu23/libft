/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:54:05 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 02:48:24 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf.h"

ssize_t	ft_snprintf(char *s, size_t size, const char *f, ...)
{
	va_list	args;
	ssize_t	rval;

	va_start(args, f);
	rval = ft_vsnprintf(s, size, f, args);
	va_end(args);
	return (rval);
}
