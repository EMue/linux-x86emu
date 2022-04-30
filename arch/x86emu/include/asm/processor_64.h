/*
 * Copyright 2003 PathScale, Inc.
 *
 * Licensed under the GPL
 */

#ifndef __X86EMU_PROCESSOR_X86_64_H
#define __X86EMU_PROCESSOR_X86_64_H

struct arch_thread {
        unsigned long debugregs[8];
        int debugregs_seq;
        unsigned long fs;
        struct faultinfo faultinfo;
};

#define INIT_ARCH_THREAD { .debugregs  		= { [ 0 ... 7 ] = 0 }, \
			   .debugregs_seq	= 0, \
			   .fs			= 0, \
			   .faultinfo		= { 0, 0, 0 } }

#define STACKSLOTS_PER_LINE 4

static inline void arch_flush_thread(struct arch_thread *thread)
{
}

static inline void arch_copy_thread(struct arch_thread *from,
                                    struct arch_thread *to)
{
	to->fs = from->fs;
}

// Inline definitions removed.
void* current_sp(void);
unsigned current_bp(void);

#endif
