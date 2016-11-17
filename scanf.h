#ifndef _H_SCANF
  #define _H_SCANF

  #ifdef  _WIN32

    #include <stdio.h>
    #include <conio.h>

    int bl_scanf_c()
    {
      while(!kbhit());
      return getch();
    }

    int bl_scanf_go()
    {
      if(kbhit())
        return getch();
      else
        return -1;
    }

  #else

    #include <unistd.h>
    #include <termios.h>
    #include <ncurses.h>

    int bl_scanf_c()
    {
      char buf=-1;
      struct termios old = {0};

      if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
      old.c_lflag &= ~ICANON;
      old.c_lflag &= ~ECHO;
      old.c_cc[VMIN] = 1;
      old.c_cc[VTIME] = 0;
      if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
      if(read(0, &buf, 1) < 0)
        perror("read()");
      old.c_lflag |= ICANON;
      old.c_lflag |= ECHO;

      if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

      return buf;
    }


    #include <stdlib.h>

    int bl_scanf_go()// without waiting
    {
        int retval;
        int rb = -1;
        struct termios oldt, newt;
        struct timeval tv;

        tcgetattr(STDIN_FILENO, &oldt);// открываем терминал для реакции на клавиши без эха
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);// 0 - стандартный вход

        tv.tv_sec = 0;
        tv.tv_usec = 10000;// ждем 0.01с
        retval = select(1, &rfds, NULL, NULL, &tv);

        if(retval && FD_ISSET(STDIN_FILENO, &rfds))
          rb = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return rb;
    }

  #endif

#endif
