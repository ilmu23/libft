/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:37:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 03:07:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MATH_H
# define LFT_MATH_H
# include "lft_data.h"
# include "lft_limits.h"

/*   no alloc   */
/**   signed   **/
int64_t		ft_pow(const int64_t n, int64_t p);
int64_t		ft_max(const int64_t a, const int64_t b);
int64_t		ft_min(const int64_t a, const int64_t b);
/**   signed   **/

/**   unsigned   **/
uint64_t	ft_upow(const uint64_t n, int64_t p);
uint64_t	ft_umax(const uint64_t a, const uint64_t b);
uint64_t	ft_umin(const uint64_t a, const uint64_t b);
/**   unsigned   **/
/*   no alloc   */

#endif
