/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:34:58 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 03:53:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf_internal.h"
#include "lft_gc.h"

static inline size_t	_argcount(const char *f);
static inline size_t	_getdmax(const char *f);
static inline t_list	*_getargs(va_list args, size_t argc);
static inline void	_join(char *str, size_t size, t_list *conversions);

ssize_t	ft_vsnprintf(char *s, size_t size, const char *f, va_list args)
{
	t_list	*arglist;
	t_list	*conversions;
	t_list	*strings;
	uint8_t	ptrap_st;

	ptrap_st = ft_pushtrap_status();
	ft_pushtrap(PTRAP_ENABLE);
	ft_push(s);
	arglist = _getargs(args, _argcount(f));
	conversions = getconversions(f, arglist);
	strings = NULL;
	expandconversions(conversions, &strings);
	if (s)
		_join(s, size, strings);
	if (ptrap_st & PTRAP_DISABLE)
		ft_pushtrap(PTRAP_DISABLE | PTRAP_POP);
	return (getlen(strings));
}

static inline size_t	_argcount(const char *f)
{
	const char	*tmp;
	size_t		argc;
	char		*conversion;

	tmp = f;
	argc = 0;
	while (*tmp)
	{
		if (*tmp++ == '%')
		{
			conversion = getconvstr(tmp);
			if (ft_strchr(conversion, '$'))
				return (_getdmax(f));
			while (*conversion)
			{
				if (*conversion == '*')
					argc++;
				else if (ft_strchr(PF_FORMAT_SPEC_EXP, *conversion))
					argc++;
				conversion++;
				tmp++;
			}
		}
	}
	return (argc);
}

static inline size_t	_getdmax(const char *f)
{
	size_t	dmax;
	size_t	dcur;
	char	*conversion;

	dmax = 0;
	while (*f)
	{
		if (*f++ == '%')
		{
			conversion = getconvstr(f);
			while (*conversion)
			{
				if (ft_isdigit(*conversion))
				{
					dcur = ft_atoi64(conversion);
					conversion += ft_uintlen(dcur, DECIMAL);
					if (*conversion == '$' && dcur >= dmax)
						dmax = dcur;
				}
				conversion++;
				f++;
			}
		}
	}
	return (dmax);
}

static inline t_list	*_getargs(va_list args, size_t argc)
{
	t_list		*out;
	uintptr_t	*val;

	out = NULL;
	while (argc--)
	{
		val = ft_calloc(1, sizeof(*val));
		if (!val)
			return (NULL);
		*val = va_arg(args, uintptr_t);
		ft_lstadd_back(&out, ft_lstnew(val));
	}
	return (out);
}

static inline void	_join(char *str, size_t size, t_list *strings)
{
	ft_memset(str, 0, size);
	while (strings && size)
	{
		if (strings->blk)
		{
			ft_memcpy(str, strings->blk,
				ft_min(ft_getblksize(strings->blk), size));
			str += ft_min(ft_getblksize(strings->blk), size) - 1;
			size -= ft_min(ft_getblksize(strings->blk), size) - 1;
		}
		strings = strings->next;
	}
}