/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_X86EMU_CURRENT_H
#define _ASM_X86EMU_CURRENT_H

#include <linux/compiler.h>
#include <asm/percpu.h>

#ifndef __ASSEMBLY__
struct task_struct;

DECLARE_PER_CPU(struct task_struct *, current_task);

// Removed inline definition.
struct task_struct *get_current(void);

#define current get_current()

#endif /* __ASSEMBLY__ */

#endif /* _ASM_X86EMU_CURRENT_H */
