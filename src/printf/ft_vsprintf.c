/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:34:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 02:35:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf.h"

ssize_t	ft_vsprintf(char *s, const char *f, va_list args)
{
	return (ft_vsnprintf(s, SIZE_MAX, f, args));
}
