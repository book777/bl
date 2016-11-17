/* Example:

  bl_color(1);
  printf("Hello world!\n");

  bl_color(2);
  printf("Hello world!\n");

  bl_color(-1);// Back to default color
  printf("Hello world!\n");
*/
#ifndef _H_COLOR
  #define _H_COLOR

  #ifdef _WIN32

    #include <stdio.h>
    #include <windows.h>

    WORD _CUR_COLORW;
    int _CUR_COLOR=0;

    void bl_color(int i)// https://goo.gl/0j7MCE
    {
      if(!_CUR_COLOR) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        _CUR_COLORW = consoleInfo.wAttributes;
        ++_CUR_COLOR;
      }

      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      switch (i)
      {
        case 1:
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
          break;
        case 2:
          SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
          break;
        case 4:
          SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
          break;
        default:
          SetConsoleTextAttribute(hConsole, _CUR_COLORW);
      }
    }

  #else

    #include <stdio.h>

    void bl_color(int i)
    {
      switch (i)
      {
        case 1: printf("\033[22;31m");return;// red
        case 11: printf("\033[01;31m");return;// light red

        case 2: printf("\033[22;32m");return;// green
        case 12: printf("\033[01;32m");return;// light green

        case 3: printf("\033[22;33m");return;// brown
        case 13: printf("\033[01;33m");return;// yellow

        case 4:printf("\033[22;34m");return;// blue
        case 14:printf("\033[01;34m");return;// light blue

        case 5:printf("\033[22;35m");return;// pink
        case 15:printf("\033[01;35m");return;// light pink

        case 6:printf("\033[22;36m");return;// cyan
        case 16:printf("\033[01;36m");return;// light cyan

        case 7:printf("\033[01;37m");return;// white
        case 8:printf("\033[22;37m");return;// gray
        case 9:printf("\033[01;30m");return;// dark gray
        case 10:printf("\033[22;30m");return;// black

        default:printf("\033[0m");return;
      }
    }
    /*
    // Example:
    //  printf("This is %sred%s text!", bl_color_string(1), bl_color_string(-1));
    unsigned char* bl_color_string(int i) {
      switch (i)
      {
        case 1: return (unsigned char*)"\033[22;31m";// red
        case 11: return (unsigned char*)"\033[01;31m";// light red

        case 2: return (unsigned char*)"\033[22;32m";// green
        case 22: return (unsigned char*)"\033[01;32m";// light green

        case 3: return (unsigned char*)"\033[22;33m";// brown
        case 33: return (unsigned char*)"\033[01;33m";// yellow

        case 4: return (unsigned char*)"\033[22;34m";// blue
        case 44: return (unsigned char*)"\033[01;34m";// light blue

        case 5: return (unsigned char*)"\033[22;35m";// pink
        case 55: return (unsigned char*)"\033[01;35m";// light pink

        case 6: return (unsigned char*)"\033[22;36m";// cyan
        case 66: return (unsigned char*)"\033[01;36m";// light cyan

        case 7: return (unsigned char*)"\033[22;37m";// gray
        case 77: return (unsigned char*)"\033[01;37m";// white

        case 8: return (unsigned char*)"\033[22;30m";// black
        case 88: return (unsigned char*)"\033[01;30m";// dark gray

        default: return (unsigned char*)"\033[0m";
      }
    }
    */

  #endif

#endif
