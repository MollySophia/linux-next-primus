/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_POWERPC_ARCHRANDOM_H
#define _ASM_POWERPC_ARCHRANDOM_H

#include <asm/machdep.h>

static inline size_t __must_check arch_get_random_longs(unsigned long *v, size_t max_longs)
{
	return 0;
}

static inline size_t __must_check arch_get_random_seed_longs(unsigned long *v, size_t max_longs)
{
	if (max_longs && ppc_md.get_random_seed && ppc_md.get_random_seed(v))
		return 1;
	return 0;
}

#ifdef CONFIG_PPC_POWERNV
int pnv_get_random_long(unsigned long *v);
#endif

#endif /* _ASM_POWERPC_ARCHRANDOM_H */
