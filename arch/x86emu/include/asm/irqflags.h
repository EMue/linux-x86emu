/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __X86EMU_IRQFLAGS_H
#define __X86EMU_IRQFLAGS_H

#define arch_local_save_flags arch_local_save_flags
static inline unsigned long arch_local_save_flags(void)
{
	// FIXME: Stub.
	return 0;
}

#define arch_local_irq_restore arch_local_irq_restore
static inline void arch_local_irq_restore(unsigned long flags)
{
	// FIXME: Stub.
}

#define arch_local_irq_enable arch_local_irq_enable
static inline void arch_local_irq_enable(void)
{
	// FIXME: Stub.
}

#define arch_local_irq_disable arch_local_irq_disable
static inline void arch_local_irq_disable(void)
{
	// FIXME: Stub.
}

#define ARCH_IRQ_DISABLED	0
#define ARCh_IRQ_ENABLED	(SIGIO|SIGVTALRM)

#include <asm-generic/irqflags.h>

#endif
