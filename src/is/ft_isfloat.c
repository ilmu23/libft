/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:35:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/07/25 15:00:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isfloat.c
 */

#include "lft_is.h"
#include "lft_to.h"
#include "lft_str.h"

static inline char	*_trimzeros(const char *s);

/** @brief Checks if n is a valid float representation
 *
 * @param *n String to check
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isfloat(const char *n)
{
	long double	nbr;

	if (!n)
		return (0);
	n = _trimzeros(n);
	if (!n)
		return (0);
	if (ft_strequals(n, "0"))
		return (1);
	nbr = ft_atof80(n);
	if ((nbr == -1 && !ft_strequals(n, "-1") && !ft_strequals(n, "-1."))
		|| (nbr == 0 && !ft_strequals(n, "0") && !ft_strequals(n, "0.")))
		return (0);
	if (*n == '+' || *n == '-')
		n++;
	while (ft_isdigit(*n))
		n++;
	if (*n == '.' || *n == ',')
		n++;
	while (ft_isdigit(*n))
		n++;
	return (*n == '\0');
}

static inline char	*_trimzeros(const char *s)
{
	size_t	start;
	size_t	end;

	if (!s[1])
		return ((char *)s);
	end = 0;
	if (ft_strchr(s, '.') || ft_strchr(s, ','))
		end = ft_strlen(s) - 1;
	start = 0;
	while (s[start] == '0' && !ft_strchr(".,", s[start + 1]))
		start++;
	while (end > start && s[end] == '0')
		end--;
	if (end)
		return (ft_substr(s, start, end - start + 1));
	return (ft_substr(s, start, ft_strlen(&s[start])));
}
