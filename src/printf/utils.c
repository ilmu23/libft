/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:04:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:43:07 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_printf_internal.h"

uintptr_t	getnextarg(t_list **args)
{
	uintptr_t	*val;

	val = (uintptr_t *)(*args)->blk;
	*args = (*args)->next;
	return (*val);
}

uintptr_t	getarg(t_list *args, size_t argn)
{
	while (--argn)
		args = args->next;
	return (*(uintptr_t *)args->blk);
}

ssize_t	getlen(t_list *strings)
{
	ssize_t	len;

	len = 0;
	while (strings)
	{
		if (strings->blk)
			len += ft_getblksize(strings->blk) - 1;
		strings = strings->next;
	}
	return (len);
}

char	*getconvstr(const char *f)
{
	size_t	i;

	i = 0;
	while (f[i] && !ft_strchr(PF_FORMAT_SPEC, f[i]))
		i++;
	return (ft_substr(f, 0, i + 1));
}

char	*cstr(uint8_t c, size_t slen)
{
	char	*out;

	out = ft_calloc(slen + 1, sizeof(*out));
	if (!out)
		return (NULL);
	ft_memset(out, c, slen);
	return (out);
}
