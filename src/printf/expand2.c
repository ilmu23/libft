/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:49:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/30 05:24:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf_internal.h"

static inline void	_cast(t_pf_conversion *cnv);

char	*expandint(t_pf_conversion *cnv)
{
	size_t	slen;
	char	*out;

	_cast(cnv);
	out = ft_itoa(cnv->arg.intval);
	if (!out)
		return (NULL);
	slen = ft_strlen(out);
	if (cnv->precision > slen)
		out = ft_strjoin(cstr('0', cnv->precision - slen -
			(cnv->flags & (PF_FLAG_SPACE | PF_FLAG_SIGN)
				&& cnv->arg.intval >= 0)), out);
	if (cnv->arg.intval >= 0)
	{
		if (cnv->flags & PF_FLAG_SIGN)
			out = ft_strjoin("+", out);
		else if (cnv->flags & PF_FLAG_SPACE)
			out = ft_strjoin(" ", out);
	}
	return (out);
}

char	*expanduint(t_pf_conversion *cnv)
{
	t_base	base;
	size_t	slen;
	char	*out;

	_cast(cnv);
	base = DECIMAL;
	if (cnv->arg.type == o)
		base = OCTAL;
	else if (cnv->arg.type == x || cnv->arg.type == X || cnv->arg.type == p)
		base = HEX;
	out = ft_utoa_base(cnv->arg.uintval, base);
	if (!out)
		return (NULL);
	slen = ft_strlen(out);
	if (cnv->precision > slen)
		out = ft_strjoin(cstr('0', cnv->precision - slen + 1), out);
	if (cnv->flags & PF_FLAG_ALT || cnv->arg.type == p)
	{
		if (cnv->arg.type == o && out &&  *out != '0')
			out = ft_strjoin("0", out);
		else if (cnv->arg.type == x || cnv->arg.type == X || cnv->arg.type == p)
			out = ft_strjoin("0X", out);
	}
	if (cnv->arg.type == x || cnv->arg.type == p)
		ft_strlower(out);
	return (out);
}

char	*expandchar(t_pf_conversion *cnv)
{
	char	*out;

	out = ft_calloc(2, sizeof(*out));
	if (!out)
		return (NULL);
	*out = cnv->arg.charval;
	return (out);
}

char	*expandstr(t_pf_conversion *cnv)
{
	size_t	slen;
	char	*out;

	slen = ft_strlen((char *)cnv->arg.ptrval);
	out = ft_calloc(slen, sizeof(*out));
	if (!out)
		return (NULL);
	if (cnv->precision)
		slen = cnv->precision;
	ft_strlcpy(out, (char *)cnv->arg.ptrval, slen + 1);
	return (out);
}

static inline void	_cast(t_pf_conversion *cnv)
{
	if (!cnv->length)
		return ;
	if (cnv->length == PF_LENGTH_HHALF)
		cnv->arg.uintval = (uint8_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_HALF)
		cnv->arg.uintval = (uint16_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_LONG)
		cnv->arg.uintval = (uint32_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_LLONG)
		cnv->arg.uintval = (uint64_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_IMAX)
		cnv->arg.uintval = (uintmax_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_SIZE)
		cnv->arg.uintval = (size_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_DIFF)
		cnv->arg.intval = (ptrdiff_t)cnv->arg.intval;
}
