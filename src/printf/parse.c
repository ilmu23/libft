/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:20:25 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/04 16:54:03 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_printf_internal.h"

static inline t_pf_conversion	*_newstring(const char *s);
static inline t_pf_conversion	*_newconversion(const char *cnv, t_list **args);
static inline t_pf_arg		_gettype(const char *cnv, t_list **args, size_t n);
static inline t_format_type	_argtype(const uint8_t c);

t_list	*getconversions(const char *f, t_list *args)
{
	const t_list	*out;
	t_pf_conversion	*conversion;

	out = NULL;
	while (*f)
	{
		if (*f != '%')
		{
			conversion = _newstring(ft_substr(f, 0, ft_strclen(f, '%')));
			f += ft_strclen(f, '%');
		}
		else
		{
			conversion = _newconversion(getconvstr(++f), &args);
			while (*f && !ft_strchr(PF_FORMAT_SPEC, *f))
				f++;
			f++;
		}
		ft_lstadd_back(&out, ft_lstnew(conversion));
	}
	return ((t_list *)out);
}

static inline t_pf_conversion	*_newstring(const char *str)
{
	t_pf_conversion	*out;

	ft_push(str);
	out = ft_calloc(1, sizeof(*out));
	if (!out)
		return (NULL);
	*out = (t_pf_conversion){.arg.type = s, .arg.ptrval = (uintptr_t)str,
		.flags = 0, .width = 0, .precision = 0, .length = 0};
	return (out);
}

static inline t_pf_conversion	*_newconversion(const char *cnv, t_list **args)
{
	t_pf_conversion	*out;
	size_t			argn;

	ft_push(cnv);
	out = ft_calloc(1, sizeof(*out));
	if (!out)
		return (NULL);
	argn = 0;
	if (ft_strchr(cnv, '$'))
	{
		argn = ft_atou64(cnv);
		cnv += ft_uintlen(argn, DECIMAL) + 1;
	}
	out->flags = getflags(&cnv);
	if (ft_isdigit(*cnv) || *cnv == '*')
		out->width = getwidth(&cnv, args);
	if (*cnv == '.')
	{
		cnv++;
		out->precision = getprecision(&cnv, args);
	}
	out->length = getlength(&cnv);
	out->arg = _gettype(cnv, args, argn);
	return (out);
}

static inline t_pf_arg	_gettype(const char *cnv, t_list **args, size_t n)
{
	t_pf_arg	arg;

	arg.type = _argtype(*cnv);
	if (arg.type != percent && !n)
		arg.ptrval = getnextarg(args);
	else if (arg.type != percent)
		arg.ptrval = getarg(*args, n);
	return (arg);
}

static inline t_format_type	_argtype(const uint8_t chr)
{
	if (chr == 'd' || chr == 'i')
		return (d + (chr == 'i'));
	if (chr == 'o')
		return (o);
	if (chr == 'u')
		return (u);
	if (chr == 'x' || chr == 'X')
		return (x + (chr == 'X'));
	if (chr == 'c')
		return (c);
	if (chr == 's')
		return (s);
	if (chr == 'p')
		return (p);
	if (chr == 'n')
		return (n);
	return (percent);
}
