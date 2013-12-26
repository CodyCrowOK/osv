/* panic.c
 * Used in order to throw a system hanging message,
 * even in situations where crashing unsafely is wildly
 * inappropriate, simply because I said so.
 * Linus has a lot of good ideas.
 */

void panic(const char * message)
{
	printk("Kernel Panic: %s\n", message);
	while(1);
}
