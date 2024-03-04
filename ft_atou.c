/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:25:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/04 13:07:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atou.c
 */

#include "libft.h"

/** @brief Converts s to a 64-bit unsigned integer value
 *
 * @param *s String to convert
 * @retval uint64_t Converted value of s
 */
uint64_t	ft_atou64(const char *s)
{
	uint64_t	out;

	out = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		if (out > UINT64_MAX / 10 || (out == UINT64_MAX / 10 && *s > '5'))
			return (0);
		out = out * 10 + (*s++ - '0');
	}
	return (out);
}

/** @brief Converts s to a 32-bit unsigned integer value
 *
 * @param *s String to convert
 * @retval uint32_t Converted value of s
 */
uint32_t	ft_atou32(const char *s)
{
	uint64_t	out;

	out = ft_atou64(s);
	if (out > UINT32_MAX)
		return (0);
	return ((uint32_t)out);
}

/** @brief Converts s to a 16-bit unsigned integer value
 *
 * @param *s String to convert
 * @retval uint16_t Converted value of s
 */
uint16_t	ft_atou16(const char *s)
{
	uint64_t	out;

	out = ft_atou64(s);
	if (out > UINT16_MAX)
		return (0);
	return ((uint16_t)out);
}

/** @brief Converts s to a 8-bit unsigned integer value
 *
 * @param *s String to convert
 * @retval uint8_t Converted value of s
 */
uint8_t	ft_atou8(const char *s)
{
	uint64_t	out;

	out = ft_atou64(s);
	if (out > UINT8_MAX)
		return (0);
	return ((uint8_t)out);
}

/** @brief Alias for ft_atou32
 */
uint32_t	ft_atou(const char *s)
{
	return (ft_atou32(s));
}
