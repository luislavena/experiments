#include <windows.h>

/*
  Broadcast to all processes a refresh of environment variables.

  Based on code from MSDN:
  http://support.microsoft.com/kb/104011
*/

int
main(int argc, char **argv)
{
  DWORD dwReturnValue = 0;

  /* ignore return value and dwReturnValue */
  SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0,
                    (LPARAM) "Environment", SMTO_ABORTIFHUNG,
                    5000, &dwReturnValue);

  return 0;
}
