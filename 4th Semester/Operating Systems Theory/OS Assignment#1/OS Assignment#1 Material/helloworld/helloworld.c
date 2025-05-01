#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(helloworld)
{
	printk("Hello World\n");
	return 0;
}
