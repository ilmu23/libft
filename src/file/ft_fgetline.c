/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:10:44 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 13:12:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

ssize_t	ft_fgetline(char **buf, size_t *bsize, t_file *f)
{
	return (ft_fgetdelim(buf, bsize, '\n', f));
}
