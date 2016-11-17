/* Example:
  bl_pointer(0);// Hide cursor
  bl_pointer(1);// Show cursor
*/
#ifndef _H_POINTER
  #define _H_POINTER

  #ifdef _WIN32

    #include <windows.h>

    void bl_pointer(int cur)
    {
      HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO info;
      info.dwSize = 100;
      info.bVisible = (cur)?TRUE:FALSE;
      SetConsoleCursorInfo(consoleHandle, &info);
    }

  #else

    #include <stdio.h>

    void bl_pointer(int cur)
    {
      if(cur)
        printf("\e[?25h");
      else
        printf("\e[?25l");
    }

  #endif

#endif
