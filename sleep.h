#ifndef _H_SLEEP
  #define _H_SLEEP

  #ifdef _WIN32

    #include <windows.h>

    void bl_sleep(unsigned int msec) {
        Sleep(msec);
    }

  #else

    #include <unistd.h>

    void bl_sleep(unsigned int msec) {
      usleep(msec*1000);
    }

  #endif

#endif
