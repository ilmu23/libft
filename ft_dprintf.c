/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:28:21 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 16:04:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		ret;
	int		out;

	if (!s)
		return (-1);
	ret = 1;
	out = 0;
	ft_pfsetfd(fd);
	va_start(args, s);
	while (*s && ret >= 0)
	{
		if (*s != '%')
			ret = ft_putchar_fd(*s, ft_pfgetfd());
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

int	ft_printformat(const char **f, va_list args)
{
	(*f)++;
	if (!(**f))
		return (0);
	return (ft_putarg(f, args));
}
