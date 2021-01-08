/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_BUG_H
#define _LINUX_BUG_H

#include <asm/bug.h>
#include <linux/compiler.h>
#include <linux/build_bug.h>

enum bug_trap_type {
	BUG_TRAP_TYPE_NONE = 0,
	BUG_TRAP_TYPE_WARN = 1,
	BUG_TRAP_TYPE_BUG = 2,
};

struct pt_regs;

#ifdef __CHECKER__
#define MAYBE_BUILD_BUG_ON(cond) (0)
#else /* __CHECKER__ */

#define MAYBE_BUILD_BUG_ON(cond)			\
	do {						\
		if (__builtin_constant_p((cond)))       \
			BUILD_BUG_ON(cond);             \
		else                                    \
			BUG_ON(cond);                   \
	} while (0)

#endif	/* __CHECKER__ */

#endif	/* _LINUX_BUG_H */
