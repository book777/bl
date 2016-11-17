#ifndef _H_GOTOXY
  #define _H_GOTOXY

  #ifdef _WIN32

    #include <windows.h>

    void bl_gotoxy(int y, int x)
    {
      COORD coord={.X=x, .Y=y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

  #else

    #include <stdio.h>

    void bl_gotoxy(int y, int x)
    {
      printf("%c[%d;%df", 0x1B, ++y, ++x);
    }

  #endif

#endif
