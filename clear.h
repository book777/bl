#ifndef _H_CLEAR
  #define _H_CLEAR

  #ifdef _WIN32

    #include <stdlib.h>

    void bl_clear()
    {
      system("cls");
    }

  #else

    #include <stdio.h>

    void bl_clear()
    {
      printf("\033[H\033[J");
    }

  #endif

#endif
