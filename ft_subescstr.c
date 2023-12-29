/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subescstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:41:02 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 14:16:01 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_subescstr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	return (ft_strremove(ft_substr(s, start, len), '\\'));
}
