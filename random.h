#ifndef _H_RANDOM
  #define _H_RANDOM

  #include <time.h>
  #include <stdlib.h>

  int bl_rand(int min, int max)
  {
    if(min==max)
      return min;
    if(min>max)
      return (rand()%(min-max+1))+max;
    else
      return (rand()%(max-min+1))+min;
  }

#endif
