/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:12:59 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/06 00:58:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_objmap.c
 */

#include "lft_put.h"
#include "lft_str.h"
#include "_internal/lft_gc_internal.h"
#include "_internal/lft_hmap_internal.h"

/** @brief Finds and returns the object corresponding to key
 *
 * @param *key Key for the object
 * @retval t_obj* Object found with the key, or NULL if none found
 */
t_obj	*ft_objmap_get(const char *key)
{
	static t_vm	*vm = NULL;
	t_objpair	*pair;
	size_t		i;
	size_t		j;

	if (!vm)
		vm = ft_getvm();
	j = 0;
	i = gethash(key, vm->objmap.size, j++);
	pair = vm->objmap.objs[i];
	while (pair)
	{
		if (pair != (void *)&g_hmap_sentinel && ft_strequals(pair->key, key))
			return ((t_obj *)pair->obj);
		i = gethash(key, vm->objmap.size, j++);
		pair = vm->objmap.objs[i];
	}
	return (NULL);
}

void	ft_objmap_rm(const char *key)
{
	static t_vm	*vm = NULL;
	t_objpair	*pair;
	size_t		i;
	size_t		j;

	if (!vm)
		vm = ft_getvm();
	j = 0;
	i = gethash(key, vm->objmap.size, j++);
	pair = vm->objmap.objs[i];
	while (pair)
	{
		if (pair != (void *)&g_hmap_sentinel && ft_strequals(pair->key, key))
		{
			free((void *)pair->key);
			free(pair);
			vm->objmap.objs[i] = (void *)&g_hmap_sentinel;
			break ;
		}
		i = gethash(key, vm->objmap.size, j++);
		pair = vm->objmap.objs[i];
	}
	vm->objmap.count--;
	free((void *)key);
}

/** @brief Grows the objmap
 */
void	ft_growobjmap(void)
{
	static t_vm	*vm = NULL;
	t_objpair	**objs;
	size_t		asize;
	size_t		i;

	if (!vm)
		vm = ft_getvm();
	asize = getnextprime(vm->objmap.size * 2);
	objs = malloc(asize * sizeof(t_objpair *));
	if (!objs)
	{
		ft_putendl_fd(E_ALLOC, 2);
		ft_exit(69);
	}
	i = 0;
	while (i < vm->objmap.size)
	{
		if (vm->objmap.objs[i]
			&& vm->objmap.objs[i] != (void *)&g_hmap_sentinel)
			ft_addpair(objs, vm->objmap.objs[i], asize);
		i++;
	}
	free(vm->objmap.objs);
	vm->objmap = (t_objmap){.bsize = vm->objmap.size * 2, .size = asize,
		.objs = objs, .count = vm->objmap.size};
}

/** @brief Adds a new object to the objmap
 *
 * @param *key String representation of the address of the objects block
 * @param *obj Pointer to the object
 */
void	ft_addobj(const char *key, const t_obj *obj)
{
	static t_vm	*vm = NULL;

	if (!vm)
		vm = ft_getvm();
	if ((vm->objmap.count * 100) / vm->objmap.size > 70)
		ft_growobjmap();
	ft_addpair(vm->objmap.objs, ft_newpair(key, obj), vm->objmap.size);
	vm->objmap.count++;
}

/** @brief Adds a new objpair to an array of objpairs
 *
 * @param **objs Array to add to
 * @param *pair Pair to add
 */
void	ft_addpair(t_objpair **objs, t_objpair *pair, const uint64_t size)
{
	t_objpair	*cur;
	size_t		i;
	size_t		j;

	j = 0;
	i = gethash(pair->key, size, j++);
	cur = objs[i];
	while (cur && cur != (void *)&g_hmap_sentinel)
	{
		i = gethash(pair->key, size, j++);
		cur = objs[i];
	}
	objs[i] = pair;
}
