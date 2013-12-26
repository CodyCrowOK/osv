#include <stdbool.h> 
#include <stddef.h>
#include <stdint.h>
#include "../include/kernel.h"


void kernel_main()
{
	printk("Testing printk: %s and %%", "John McInroe");
}
