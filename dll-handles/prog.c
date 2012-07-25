#include <windows.h>
#include "interface.h"

int main(void)
{
	call_me();

	puts("Loading 'ext1'...");
	load_library("ext1.dll");

	puts("Loading 'ext2'...");
	load_library("ext2.dll");

	return 0;
}
