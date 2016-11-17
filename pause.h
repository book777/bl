#ifndef _H_PAUSE
  #define _H_PAUSE

  #ifndef _PAUSE_TEXT
    #define _PAUSE_TEXT "[PAUSE] Press any key to continue..."
  #endif

  #include <stdio.h>

  #ifdef _WIN32

    #include <stdlib.h>

    void bl_pause() {
      printf(_PAUSE_TEXT"\n");
      system("pause >nul");
    }

  #else

    #include <termios.h>
    #include <unistd.h>

    void bl_pause()
    {
      static struct termios oldt, newt;
      printf(_PAUSE_TEXT"\n");
      tcgetattr( STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO );
      tcsetattr( STDIN_FILENO, TCSANOW, &newt);
      getchar();
      tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    }

  #endif

#endif
