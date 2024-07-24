/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:12:45 by ivalimak          #+#    #+#             */
/*   Updated: 2024/07/24 12:47:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atof.c
 */

#include "lft_is.h"
#include "lft_to.h"

static inline long double	_getdec(const char *s);

/** @brief Converts s to a 80-bit float value
 *
 * @param *s String to convert
 * @retval long double Converted value of s
 */
long double	ft_atof80(const char *s)
{
	long double	out;
	int8_t		n;

	n = 1;
	out = 0.0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		n = -n;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		out = out * 10 + (*s++ - '0');
		if (out < 0)
			return ((n == 1) * -1);
	}
	if (*s == '.' || *s == ',')
		return ((out + _getdec(++s)) * n);
	return (out * n);
}

double	ft_atof64(const char *s)
{
	long double	n;

	n = ft_atof80(s);
	if (n > DBL_MAX)
		return (-1);
	if (n < -DBL_MAX)
		return (0);
	return ((double)n);
}

float	ft_atof32(const char *s)
{
	long double	n;

	n = ft_atof80(s);
	if (n > FLT_MAX)
		return (-1);
	if (n < -FLT_MAX)
		return (0);
	return ((float)n);
}

static inline long double	_getdec(const char *s)
{
	long double	out;
	long double	div;

	out = 0.0;
	div = 10.0;
	while (ft_isdigit(*s))
	{
		out += (*s++ - '0') / div;
		div *= 10.0;
	}
	return (out);
}
