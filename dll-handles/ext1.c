#include <windows.h>
#include <stdio.h>
#include "interface.h"

void Init_extension()
{
	puts("Init from ext1.dll");
	call_me();
}
