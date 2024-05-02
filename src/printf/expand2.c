/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:49:21 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 06:22:46 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_printf_internal.h"

static inline t_base	_getbase(t_format_type type);

char	*expandint(t_pf_conversion *cnv)
{
	size_t	slen;
	char	*out;

	if (cnv->flags & PF_FLAG_PRECISION && !cnv->precision && !cnv->arg.intval)
		return (NULL);
	cast(cnv);
	out = ft_push(ft_itoa(cnv->arg.intval));
	if (!out)
		return (NULL);
	slen = ft_strlen(out);
	if (cnv->flags & PF_FLAG_PRECISION && cnv->precision > slen - (*out == '-'))
		out = ft_strjoin(cstr('0', cnv->precision - slen + (*out == '-')
					- (cnv->flags & (PF_FLAG_SPACE | PF_FLAG_SIGN)
						&& cnv->arg.intval >= 0)), out);
	if (ft_strrchr(out, '-') && out && ft_strrchr(out, '-') != out)
	{
		*ft_strrchr(out, '-') = '0';
		*out = '-';
	}
	if (cnv->arg.intval >= 0 && cnv->flags & PF_FLAG_SIGN)
		out = ft_strjoin("+", out);
	else if (cnv->arg.intval >= 0 && cnv->flags & PF_FLAG_SPACE)
		out = ft_strjoin(" ", out);
	return (out);
}

char	*expanduint(t_pf_conversion *cnv)
{
	size_t	slen;
	char	*out;

	if (cnv->flags & PF_FLAG_PRECISION && !cnv->precision && !cnv->arg.intval)
		return (NULL);
	cast(cnv);
	out = ft_push(ft_utoa_base(cnv->arg.uintval, _getbase(cnv->arg.type)));
	if (!out)
		return (NULL);
	slen = ft_strlen(out);
	if (cnv->flags & PF_FLAG_PRECISION && cnv->precision > slen)
		out = ft_strjoin(cstr('0', cnv->precision - slen), out);
	if ((cnv->flags & PF_FLAG_ALT && cnv->arg.uintval != 0)
		|| cnv->arg.type == p)
	{
		if (cnv->arg.type == o && out && *out != '0')
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

	if (!cnv->arg.ptrval && (!(cnv->flags & PF_FLAG_PRECISION)
			|| cnv->precision >= 6))
		return (ft_strdup("(null)"));
	slen = ft_strlen((char *)cnv->arg.ptrval);
	if (slen && cnv->flags & PF_FLAG_PRECISION)
		slen = ft_min(slen, cnv->precision);
	if (!slen)
		return (NULL);
	out = ft_push(ft_calloc(slen + 1, sizeof(*out)));
	if (!out)
		return (NULL);
	ft_strlcpy(out, (char *)cnv->arg.ptrval, slen + 1);
	return (out);
}

static inline t_base	_getbase(t_format_type type)
{
	if (type == o)
		return (OCTAL);
	else if (type == x || type == X || type == p)
		return (HEX);
	return (DECIMAL);
}
