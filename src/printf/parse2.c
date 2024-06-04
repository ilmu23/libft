/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:14:34 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/04 16:55:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_printf_internal.h"

static inline uint8_t	_getflags(const char **cnv);

uint8_t	getflags(const char **cnv)
{
	const char	*tmp;
	uint8_t		flags;
	uint8_t		fspec;

	flags = _getflags(cnv);
	tmp = *cnv;
	if (ft_isdigit(*tmp) || *tmp == '*')
	{
		flags |= PF_FLAG_WIDTH;
		while (ft_isdigit(*tmp))
			tmp++;
		tmp += (*tmp == '*');
	}
	fspec = tmp[ft_strlen(tmp) - 1];
	if (*tmp == '.')
	{
		if (ft_strchr(PF_FORMAT_SPEC_INT, fspec))
			flags = (PF_FLAG_PRECISION | (flags & ~PF_FLAG_ZERO));
		else
			flags |= PF_FLAG_PRECISION;
	}
	return (flags);
}

uint8_t	getlength(const char **cnv)
{
	static const char	specs[7][3] = {"hh", "h", "ll", "l", "j", "z", "t"};
	size_t				i;

	i = 0;
	while (ft_strncmp(*cnv, specs[i], ft_strlen(specs[i])))
	{
		if (++i == 7)
			return (0);
	}
	(*cnv) += 1 + (i == 0 || i == 2);
	if (i == 0)
		return (PF_LENGTH_HHALF);
	if (i == 1)
		return (PF_LENGTH_HALF);
	if (i == 2)
		return (PF_LENGTH_LLONG);
	if (i == 3)
		return (PF_LENGTH_LONG);
	if (i == 4)
		return (PF_LENGTH_IMAX);
	if (i == 5)
		return (PF_LENGTH_SIZE);
	return (PF_LENGTH_DIFF);
}

size_t	getwidth(const char **cnv, t_list **args)
{
	size_t	n;

	if (ft_isdigit(**cnv))
	{
		n = ft_atou64((*cnv)++);
		while (ft_isdigit(**cnv))
			(*cnv)++;
		return (n);
	}
	if (**cnv != '*')
		return (0);
	n = 0;
	if (ft_isdigit(*++(*cnv)))
		n = ft_atou64(*cnv);
	if (n)
	{
		*cnv += ft_uintlen(n, DECIMAL) + 1;
		return ((size_t)getarg(*args, n));
	}
	return ((size_t)getnextarg(args));
}

size_t	getprecision(const char **cnv, t_list **args)
{
	size_t	n;

	if (ft_isdigit(**cnv))
	{
		n = ft_atou64((*cnv)++);
		while (ft_isdigit(**cnv))
			(*cnv)++;
		return (n);
	}
	if (**cnv != '*')
		return (0);
	n = 0;
	if (ft_isdigit(*++(*cnv)))
		n = ft_atou64(*cnv);
	if (n)
	{
		*cnv += ft_uintlen(n, DECIMAL) + 1;
		return ((size_t)getarg(*args, n));
	}
	return ((size_t)getnextarg(args));
}

static inline uint8_t	_getflags(const char **cnv)
{
	const char	*tmp;
	uint8_t		flags;

	tmp = *cnv;
	flags = 0;
	while (ft_strchr(PF_FLAG_CHARS, *tmp))
	{
		if (*tmp == '#')
			flags |= PF_FLAG_ALT;
		else if (*tmp == '0' && !(flags & PF_FLAG_LEFT))
			flags |= PF_FLAG_ZERO;
		else if (*tmp == '-')
			flags = (PF_FLAG_LEFT | (flags & ~PF_FLAG_ZERO));
		else if (*tmp == ' ' && !(flags & PF_FLAG_SIGN))
			flags |= PF_FLAG_SPACE;
		else if (*tmp == '+')
			flags = (PF_FLAG_SIGN | (flags & ~PF_FLAG_SPACE));
		else
			flags |= PF_FLAG_GROUP;
		tmp++;
	}
	*cnv = tmp;
	return (flags);
}
