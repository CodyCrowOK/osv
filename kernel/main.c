#include <stdbool.h> 
#include <stddef.h>
#include <stdint.h>
#include "../include/kernel.h"

/* Right now, I prefer using explicit includes and the
 * perl build script build.pl. All real dependencies
 * should probably at some point be switched over to
 * implicit dependencies using make or something.
 * But for now...
 */

#include "printk.c"

void kernel_main()
{
	terminal_initialize();
	printk("Testing printk:\n");
	printk("Percent sign: %%\n");
	printk("String: %s\n", "My string");
	printk("Both: %s %s\n", "Another string", "fouou");
}
