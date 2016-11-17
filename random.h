// If _nanoCHANGE is not defined, randomize seed has been changed every second
//#define _nanoCHANGE// If defined, randomize seed has been changed every nanosecond
#ifndef _H_RANDOM
  #define _H_RANDOM

  #include <time.h>
  #include <stdlib.h>

  int bl_rand(int min, int max)
  {
    if(min==max)
      return min;

    #ifdef _nanoCHANGE
      struct timespec curtime;
      clock_gettime(CLOCK_MONOTONIC_RAW, &curtime);
      srand(curtime.tv_nsec);//Randomize rand seed
    #else
      srand(time(NULL));//Randomize rand seed
    #endif

    if(min>max)
      return (rand() % (min-max+1)) +max;
    else
      return (rand() % (max-min+1)) +min;
  }

  int bl_random() {
    #ifdef _nanoCHANGE
      struct timespec curtime;
      clock_gettime(CLOCK_MONOTONIC_RAW, &curtime);
      srand(curtime.tv_nsec);//Randomize rand seed
    #else
      srand(time(NULL));//Randomize rand seed
    #endif
    return rand();
  }

#endif
