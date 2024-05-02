/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:25:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 11:36:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

int32_t	ft_fgetc(t_file *f)
{
	uint8_t	c;

	if (ft_fread(&c, sizeof(c), 1, f) != 1)
		return (EOF);
	return (c);
}
