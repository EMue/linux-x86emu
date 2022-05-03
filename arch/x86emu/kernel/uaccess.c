#include <linux/highmem.h>

unsigned long raw_copy_from_user(void *to, const void __user *from, unsigned long n)
{
	memcpy(to, (__force void*)from, n);
	return 0;
}
EXPORT_SYMBOL(raw_copy_from_user);
