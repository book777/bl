#ifndef _H_PL_NWW_NWD
  #define _H_PL_NWW_NWD

  #include <stdio.h>

  int bl_NWD(int a, int b) {// Największy wspólny dzielnik
    int c;
    while(b != 0) {
      c = a % b;
      a = b;
      b = c;
    }
    return a;
  }

  int bl_NWW(int a, int b) {// Najmniejsza wspólna wielokrotność
    return (a*b)/bl_NWD(a, b);
  }

#endif
