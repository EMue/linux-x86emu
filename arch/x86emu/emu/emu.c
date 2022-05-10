#include <linux/slab.h>

#include <emu/emu.h>

void kfree(const void *p)
{
	emu_free(p);
}
