/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:17:04 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 02:19:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf.h"

ssize_t	ft_dprintf(int32_t fd, const char *f, ...)
{
	va_list	args;
	ssize_t	rval;

	va_start(args, f);
	rval = ft_vdprintf(fd, f, args);
	va_end(args);
	return (rval);
}
