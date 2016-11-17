#ifndef _H_MATRIX
  #define _H_MATRIX

  #ifndef _MATRIX_X
    #define _MATRIX_X 10
  #endif
  #ifndef _MATRIX_Y
    #define _MATRIX_Y 10
  #endif
  #ifndef _MATRIX_null
    #define _MATRIX_null ' '
  #endif
  #ifndef _MATRIX_border
    #define _MATRIX_border '#'
  #endif

  #include <stdio.h>

  char bl_matrix[_MATRIX_Y][_MATRIX_X]={};

  void bl_matrix_clear()
  {
    int x, y;
    for(y=0; y < _MATRIX_Y; ++y)
      for(x=0; x < _MATRIX_X; ++x)
        bl_matrix[y][x]=_MATRIX_null;
  }

  void bl_matrix_print()
  {
    int x, y;
    for(y=0; y < _MATRIX_Y; ++y) {
      for(x=0; x < _MATRIX_X; ++x)
        printf("%c", bl_matrix[y][x]);
      printf("\n");
    }
  }

  void bl_matrix_border()
  {
    int x,y;
    for(y=0; y<_MATRIX_Y; ++y)
      if(y==0||y==_MATRIX_Y-1)
        for(x=0; x<_MATRIX_X; ++x)
          bl_matrix[y][x]=_MATRIX_border;
      else {
        bl_matrix[y][0]=_MATRIX_border;
        bl_matrix[y][_MATRIX_X-1]=_MATRIX_border;
      }
  }

#endif
