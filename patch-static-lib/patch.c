#include <stdio.h>

/* we need to define __real_awesome to use it */
void __real_awesome();

void __wrap_awesome(void)
{
	puts("Awesome from replacement!");

	/* here you can call the original awesome() function */
	/* __real_awesome(); */
}
