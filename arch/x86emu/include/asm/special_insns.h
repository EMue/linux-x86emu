/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_X86EMU_SPECIAL_INSNS_H
#define _ASM_X86EMU_SPECIAL_INSNS_H


#ifdef __KERNEL__

#include <asm/nops.h>

/*
 * Volatile isn't enough to prevent the compiler from reordering the
 * read/write functions for the control registers and messing everything up.
 * A memory clobber would solve the problem, but would prevent reordering of
 * all loads stores around it, which can hurt performance. Solution is to
 * use a variable and mimic reads and writes to it to enforce serialization
 */
extern unsigned long __force_order;

// Removed inline definition.
unsigned long native_read_cr0(void);

// Removed inline definition.
void native_write_cr0(unsigned long val);

// Removed inline definition.
unsigned long native_read_cr2(void);

// Removed inline definition.
void native_write_cr2(unsigned long val);

// Removed inline definition.
unsigned long __native_read_cr3(void);

// Removed inline definition.
void native_write_cr3(unsigned long val);

// Removed inline definition.
unsigned long native_read_cr4(void);

// Removed inline definition.
void native_write_cr4(unsigned long val);

#ifdef CONFIG_X86_64
// Removed inline definition.
unsigned long native_read_cr8(void);

// Removed inline definition.
void native_write_cr8(unsigned long val);
#endif

#ifdef CONFIG_X86_INTEL_MEMORY_PROTECTION_KEYS
// Removed inline definition.
u32 __read_pkru(void);

// Removed inline definition.
void __write_pkru(u32 pkru);
#else
// Removed inline definition.
u32 __read_pkru(void);

// Removed inline definition.
void __write_pkru(u32 pkru);
#endif

// Removed inline definition.
void native_wbinvd(void);

extern asmlinkage void native_load_gs_index(unsigned);

static inline unsigned long __read_cr4(void)
{
	return native_read_cr4();
}

#ifdef CONFIG_PARAVIRT_XXL
#include <asm/paravirt.h>
#else

static inline unsigned long read_cr0(void)
{
	return native_read_cr0();
}

static inline void write_cr0(unsigned long x)
{
	native_write_cr0(x);
}

static inline unsigned long read_cr2(void)
{
	return native_read_cr2();
}

static inline void write_cr2(unsigned long x)
{
	native_write_cr2(x);
}

/*
 * Careful!  CR3 contains more than just an address.  You probably want
 * read_cr3_pa() instead.
 */
static inline unsigned long __read_cr3(void)
{
	return __native_read_cr3();
}

static inline void write_cr3(unsigned long x)
{
	native_write_cr3(x);
}

static inline void __write_cr4(unsigned long x)
{
	native_write_cr4(x);
}

static inline void wbinvd(void)
{
	native_wbinvd();
}

#ifdef CONFIG_X86_64

static inline unsigned long read_cr8(void)
{
	return native_read_cr8();
}

static inline void write_cr8(unsigned long x)
{
	native_write_cr8(x);
}

static inline void load_gs_index(unsigned selector)
{
	native_load_gs_index(selector);
}

#endif

#endif /* CONFIG_PARAVIRT_XXL */

// Removed inline definition.
void clflush(volatile void *__p);

// Removed inline definition.
void clflushopt(volatile void *__p);

// Removed inline definition.
void clwb(volatile void *__p);

#define nop() asm volatile ("nop")


#endif /* __KERNEL__ */

#endif /* _ASM_X86EMU_SPECIAL_INSNS_H */
