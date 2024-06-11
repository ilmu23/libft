/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:34:04 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/11 15:39:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_objmap.c
 */

#include "lft_lst.h"
#include "lft_put.h"
#include "lft_str.h"
#include "_internal/lft_gc_internal.h"
#include "_internal/lft_hmap_internal.h"

static inline t_objpair	*_getpair(t_list *lst, const char *key);

/** @brief Finds the object corresponding to key
 *
 * @param *key Key to look for
 * @retval t_obj* Object corresponding to the key, or NULL if none found
 */
t_obj	*gc_objmap_get(const char *key)
{
	static t_vm	*vm = NULL;
	t_objpair	*pair;
	size_t		i;

	if (!vm)
		vm = ft_getvm();
	i = gethash(key, _GC_MAPSIZE, 5);
	pair = _getpair(vm->objmap.objs[i], key);
	if (pair)
		return ((t_obj *)pair->obj);
	return (NULL);
}

void	gc_objmap_rm(const char *key)
{
	static t_vm	*vm = NULL;
	t_objpair	*pair;
	t_list		*tmp;
	size_t		i;

	if (!vm)
		vm = ft_getvm();
	i = gethash(key, _GC_MAPSIZE, 5);
	pair = _getpair(vm->objmap.objs[i], key);
	if (!pair)
		return ;
	tmp = vm->objmap.objs[i];
	while (tmp->blk != pair)
		tmp = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		vm->objmap.objs[i] = tmp->next;
	free((void *)pair->key);
	free((void *)key);
	free(pair);
	free(tmp);
}

void	gc_objmap_add(const char *key, const t_obj *obj)
{
	static t_vm	*vm = NULL;
	t_objpair	*pair;
	size_t		i;

	if (!vm)
		vm = ft_getvm();
	pair = gc_newpair(key, obj);
	i = gethash(key, _GC_MAPSIZE, 5);
	gc_objmap_addpair(&vm->objmap.objs[i], pair);
}

void	gc_objmap_addpair(t_list **lst, t_objpair *pair)
{
	t_list	*node;
	t_list	*last;

	node = malloc(sizeof(*node));
	if (!node)
	{
		ft_putendl_fd(E_ALLOC, 2);
		ft_exit(69);
	}
	last = ft_lstlast(*lst);
	*node = (t_list){.blk = pair, .next = NULL, .prev = last, .size = NULL};
	if (node->prev)
		node->prev->next = node;
	else
		*lst = node;
}

static inline t_objpair	*_getpair(t_list *lst, const char *key)
{
	t_objpair	*out;

	while (lst)
	{
		out = (t_objpair *)lst->blk;
		if (ft_strequals(out->key, key))
			return (out);
		lst = lst->next;
	}
	return (NULL);
}
