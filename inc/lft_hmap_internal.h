/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_hmap_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:59:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 04:13:08 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_HMAP_INTERNAL_H
# define LFT_HMAP_INTERNAL_H
# include "lft_hmap.h"

# define HMAP_SALT_1 347ULL
# define HMAP_SALT_2 677ULL

/*   no alloc   */
t_hmap_pair	*getdelmarker(void);
size_t		gethash(const char *s, const size_t size, const size_t attempt);
/*   no alloc   */

#endif
