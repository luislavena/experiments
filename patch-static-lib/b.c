#include <stdio.h>

#include "a.h"
#include "b.h"

void perfect_awesome(void)
{
	puts("b: calling perfect...");
	perfect();

	puts("b: calling awesome...");
	awesome();
}
