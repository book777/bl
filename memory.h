#ifndef _H_MEMORY
  #define _H_MEMORY

  #ifdef _WIN32

    #include <malloc.h>

    int bl_memory_size(void *buffer)
    {
      return _msize(buffer);
    }

    int* bl_memory_init_int(int i)
    {
      int *a=(int*)calloc(i, sizeof(int));

      return a;
    }




  #elif __APPLE__

    #include <malloc/malloc.h>

    int bl_memory_size(void *buffer)
    {
      return malloc_size(buffer);
    }




  #else

    #include <malloc.h>

    int bl_memory_size(void *buffer)//! Return more memory then necesary
    {
      return (size_t)malloc_usable_size(buffer);
    }

    int* bl_memory_init_int(int i)// Initialize memory
    {
      int *a=(int*)calloc(i, sizeof(int));

      return a;
    }



  #endif

#endif
