/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:28:03 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 09:35:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/ft_file_internal.h"

int8_t	ft_fclose(t_file *f)
{
	int32_t	rv;

	rv = 0;
	if (ft_fflush(f) == EOF)
		rv = EOF;
	if (close(f->fd) == -1)
		rv = EOF;
	ft_maprm(getbuffers(), f->path);
	ft_popblks(2, f->sof, f);
	return (rv);
}
