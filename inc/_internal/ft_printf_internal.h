/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:53:31 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 06:23:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include <stddef.h>
# include "ft_stdio/ft_printf.h"

# define PF_FLAG_ALT 0x1U
# define PF_FLAG_ZERO 0x2U
# define PF_FLAG_LEFT 0x4U
# define PF_FLAG_SPACE 0x8U
# define PF_FLAG_SIGN 0x10U
# define PF_FLAG_GROUP 0x20U
# define PF_FLAG_WIDTH 0x40U
# define PF_FLAG_PRECISION 0x80U

# define PF_LENGTH_HHALF 0x1U
# define PF_LENGTH_HALF 0x2U
# define PF_LENGTH_LONG 0x4U
# define PF_LENGTH_LLONG 0x8U
# define PF_LENGTH_IMAX 0x10U
# define PF_LENGTH_SIZE 0x20U
# define PF_LENGTH_DIFF 0x40U

# define PF_FLAG_CHARS "#0- +'"
# define PF_FORMAT_SPEC "diouxXcspn%"
# define PF_FORMAT_SPEC_EXP "diouxXcspn"
# define PF_FORMAT_SPEC_INT	"diouxX"

typedef enum e_format_type
{
	d,
	i,
	o,
	u,
	x,
	X,
	c,
	s,
	p,
	n,
	percent
}	t_format_type;

typedef struct s_pf_arg
{
	t_format_type	type;
	union
	{
		int64_t		intval;
		uint64_t	uintval;
		uint8_t		charval;
		uintptr_t	ptrval;
	};
}	t_pf_arg;

typedef struct s_pf_conversion
{
	t_pf_arg	arg;
	uint8_t		flags;
	size_t		width;
	size_t		precision;
	uint8_t		length;
}	t_pf_conversion;

// parse.c
t_list		*getconversions(const char *f, t_list *args);

// parse2.c
uint8_t		getflags(const char **conversion);
uint8_t		getlength(const char **conversion);
size_t		getwidth(const char **conversion, t_list **args);
size_t		getprecision(const char **conversion, t_list **args);

// expand.c
void		expandconversions(t_list *conversions, t_list **strings);

// expand2.c
char		*expandint(t_pf_conversion *cnv);
char		*expanduint(t_pf_conversion *cnv);
char		*expandchar(t_pf_conversion *cnv);
char		*expandstr(t_pf_conversion *cnv);

// cast.c
void		cast(t_pf_conversion *cnv);

// utils.c
uintptr_t	getnextarg(t_list **args);
uintptr_t	getarg(t_list *args, size_t argn);
ssize_t		getlen(t_list *strings);
char		*getconvstr(const char *f);
char		*cstr(uint8_t c, size_t len);

#endif
