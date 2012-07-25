#include <windows.h>
#include <stdio.h>
#include "interface.h"

typedef void (*sInitExtension)();

void load_library(char *filename)
{
	HMODULE handle;
	sInitExtension pInitExtension;

	/* load extension */
	handle = LoadLibrary(filename);
	if (handle)
	{
		/* Obtain a pointer to the init function */
		pInitExtension = (sInitExtension) GetProcAddress(handle, "Init_extension");
		if (pInitExtension)
		{
			/* Invoke initialization */
			(*pInitExtension)();
		}
		else
		{
			printf("Failed to obtain refrence to 'Init_extension': %d\n", GetLastError());
		}
	}
	else
	{
		printf("Failed to load dll1: %d\n", GetLastError());
	}

	if (handle)
	{
		FreeLibrary(handle);
	}
}

void call_me(void)
{
	puts("just say hi!");
}

BOOL WINAPI
DllMain(HINSTANCE dll, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		printf("mylib DLL_PROCESS_ATTACH: %#x\n", dll);
	}

	return TRUE;
}
