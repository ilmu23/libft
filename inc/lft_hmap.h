/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_hmap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:07:12 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 04:16:31 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_HMAP_H
# define LFT_HMAP_H
# include "lft_data.h"
# include "lft_limits.h"

/*   alloc   */
uint8_t	ft_mapadd(t_hmap *hmap, const char *key, const void *val);

t_hmap	*ft_mapnew(size_t size);
/*   alloc   */

/*   no alloc   */
void	*ft_mapget(t_hmap *hmap, const char *key);

void	ft_maprm(t_hmap *hmap, const char *key);
void	ft_mappop(t_hmap_pair *pair);
void	ft_mappop_all(t_hmap *hmap);
/*   no alloc   */

#endif
