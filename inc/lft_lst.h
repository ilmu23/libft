/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:28:48 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:33:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_LST_H
# define LFT_LST_H
# include <stdlib.h>
# include "lft_data.h"
# include "lft_limits.h"

/*   alloc   */
t_list	*ft_lstnew(const void *blk);
t_list	*ft_lstdup(const t_list *node);
/*   alloc   */

/*   no alloc   */
t_list	*ft_lstpop(const t_list *node);
t_list	*ft_lstpush(const t_list *node);
t_list	*ft_lstlast(const t_list *list);
t_list	*ft_lstfirst(const t_list *list);

void	ft_lstadd_front(const t_list **list, t_list *node);
void	ft_lstadd_back(const t_list **list, t_list *node);
void	ft_lstrmnode(const t_list **list, const t_list *node);
void	ft_lstpopall(const t_list *list);
void	ft_lstpushall(const t_list *list);
/*   no alloc   */

#endif
