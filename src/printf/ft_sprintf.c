/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:21:07 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 02:22:57 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf.h"

ssize_t	ft_sprintf(char *s, const char *f, ...)
{
	va_list	args;
	ssize_t	rval;

	va_start(args, f);
	rval = ft_vsprintf(s, f, args);
	va_end(args);
	return (rval);
}
