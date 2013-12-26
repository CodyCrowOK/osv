//printk.c

#include <stdbool.h> 
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "../include/kernel.h"
#include "terminal.h"

void putchar(char c);
//terminal_writestring("Hello, kernel World!\nMore Text.\nLet's try another line.");

/* Let's just support strings because I don't feel like allowing
 * anything else. It can be casted into a string if it's really 
 * important, and it never is.
 */

// printk: Print kernel messages.
void printk(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	for (unsigned int i = 0; i < strlen(fmt); i++) {
		if (*(fmt + i) != '%') putchar(*(fmt + i));
		else {
			if ((*(fmt + ++i)) == 's') { //char after %
				char *str;
				str = va_arg(args, char *);
				for (unsigned int j = 0; j < strlen(str); j++) {
					putchar(*(str + j));
				}
			}
			else if ((*(fmt + ++i)) == '%') putchar('%');
		}
	}
	va_end(args);
}

void putchar(char c)
{
	//Lazy putchar
	terminal_putchar(c);
}
