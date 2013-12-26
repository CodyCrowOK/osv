//printk.c

#include <stdbool.h> 
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "../include/kernel.h"
#include "terminal.h"

void putchar(char c);

terminal_initialize();
terminal_writestring("Hello, kernel World!\nMore Text.\nLet's try another line.");

/* Let's just support strings because I don't feel like allowing
 * anything else. It can be casted into a string if it's really 
 * important, and it never is.
 */

void printk(const char *fmt, ...)
{
va_list argp;
int i;
char *s;
char fmtbuf[256];

va_start(argp, fmt);

for(p = fmt; *p != '\0'; p++)
	{
	if(*p != '%')
		{
		putchar(*p);
		continue;
		}

	switch(*++p)
	{
	case 'c':
		i = va_arg(argp, int);
		putchar(i);
		break;

	case 's':
		s = va_arg(argp, char *);
		char *q = &s;
		while (*q) {
			putchar(*q);
			q++;
			//Wow, I used pointers appropriately.
		}
		break;

	case '%':
		putchar('%');
		break;
	}
	}

va_end(argp);
}

void putchar(char c)
{
	//Lazy putchar
	terminal_putchar(c);
}
