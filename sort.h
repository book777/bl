#ifndef _H_SORT
  #define _H_SORT

  #include <stdio.h>
  #include <stdlib.h>

  void shakerSort(int array[], int size)
  {
    for(int i = 0; i < size/2; i++)
    {
      bool swapped = false;

      for(int j = i; j < size - i - 1; ++j)// one way
        if(array[j] < array[j+1])
        {
          int tmp = array[j];
          array[j] = array[j+1];
          array[j+1] = tmp;
          swapped = true;
        }

      for(int j = size - 2 - i; j > i; --j) {// and back
        if(array[j] > array[j-1])
        {
          int tmp = array[j];
          array[j] = array[j-1];
          array[j-1] = tmp;
          swapped = true;
        }
      }
      if(!swapped)// block (break if no element was swapped - the array is sorted)
        break;
    }
  }

#endif
