/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:23:55 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 06:22:15 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_printf_internal.h"

static inline void	_scast(t_pf_conversion *cnv);
static inline void	_ucast(t_pf_conversion *cnv);

void	cast(t_pf_conversion *cnv)
{
	if (cnv->arg.type == p)
		cnv->length = PF_LENGTH_IMAX;
	if (cnv->arg.type == d || cnv->arg.type == i)
		_scast(cnv);
	else
		_ucast(cnv);
}

static inline void	_scast(t_pf_conversion *cnv)
{
	if (!cnv->length)
		cnv->arg.intval = (int32_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_HHALF)
		cnv->arg.intval = (int8_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_HALF)
		cnv->arg.intval = (int16_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_LONG)
		cnv->arg.intval = (int32_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_LLONG)
		cnv->arg.intval = (int64_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_IMAX)
		cnv->arg.intval = (intmax_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_SIZE)
		cnv->arg.intval = (ssize_t)cnv->arg.intval;
	else if (cnv->length == PF_LENGTH_DIFF)
		cnv->arg.intval = (ptrdiff_t)cnv->arg.intval;
}

static inline void	_ucast(t_pf_conversion *cnv)
{
	if (!cnv->length)
		cnv->arg.uintval = (uint32_t)cnv->arg.uintval;
	else if (cnv->length == PF_LENGTH_HHALF)
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
}
