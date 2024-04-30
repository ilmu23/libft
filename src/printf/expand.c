/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:12:20 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/30 07:35:32 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio/ft_printf_internal.h"

static inline char	*_padstr(t_pf_conversion *cnv, char *str, size_t slen);
static inline void	_addstr(t_list **out, t_pf_conversion *cnv, char *str);
static inline void	_storelen(t_pf_conversion *cnv, t_list *out);

t_list	*expandconversions(t_list *conversions)
{
	t_pf_conversion	*cnv;
	t_list			*out;
	char			*str;

	out = NULL;
	str = NULL;
	while (conversions)
	{
		cnv = conversions->blk;
		if (cnv->arg.type == d || cnv->arg.type == i)
			str = expandint(cnv);
		else if (cnv->arg.type == o || cnv->arg.type == u
			|| cnv->arg.type == x || cnv->arg.type == X || cnv->arg.type == p)
			str = expanduint(cnv);
		else if (cnv->arg.type == c)
			str = expandchar(cnv);
		else if (cnv->arg.type == s)
			str = expandstr(cnv);
		else if (cnv->arg.type == percent)
			str = ft_strdup("%");
		if (cnv->arg.type == n)
			_storelen(cnv, out);
		else
			_addstr(&out, cnv, str);
		conversions = conversions->next;
	}
	return (out);
}

static inline char	*_padstr(t_pf_conversion *cnv, char *str, size_t slen)
{
	char	*out;
	char	pc;

	pc = ' ';
	ft_push(str);
	if ((cnv->arg.type == d || cnv->arg.type == i || cnv->arg.type == o
		|| cnv->arg.type == u || cnv->arg.type == x || cnv->arg.type == X)
		&& cnv->flags & PF_FLAG_ZERO)
		pc = '0';
	if (cnv->flags & PF_FLAG_LEFT)
		out = ft_strjoin(str, cstr(pc, cnv->width - slen));
	else
		out = ft_strjoin(cstr(pc, cnv->width - slen + (slen != 0)), str);
	return (out);
}

static inline void	_addstr(t_list **out, t_pf_conversion *cnv, char *str)
{
	size_t	slen;

	slen = ft_strlen(str);
	if (cnv->width > slen)
		str = _padstr(cnv, str, slen);
	ft_lstadd_back(out, ft_lstnew(str));
}

static inline void	_storelen(t_pf_conversion *cnv, t_list *out)
{
	*(ssize_t *)cnv->arg.ptrval = getlen(out);
}
