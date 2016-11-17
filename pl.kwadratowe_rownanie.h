// GCC must have a flag -lm
#ifndef _H_PL_KWADRATOWE_ROWNANIE
  #define _H_PL_KWADRATOWE_ROWNANIE

  #include <stdio.h>
  #include <math.h>

  void bl_kwadratowe_rownanie()
  {
    float a,b,c, delta;

    printf("Podaj 'a b c' zgodnie z a*x*x+b*x+c => ");
    scanf("%f %f %f\n", &a, &b, &c);

    printf("\n");

    if(a==0)
    {
      printf("(nie jest to rozwiazanie kwadrotowe)\n");
      if(b!=0)
        printf("x = %f\n", (-c)/b);
      else if(c==0)
          printf("Nieskonczenie wiele\n");
        else
          printf("Niema razwiazan\n");
    }
    else
    {
      delta = b*b - 4*a*c;
      if(delta > 0)
        printf("x1 = %f\nx2 = %f\n", (-b - sqrt(delta))/(2*a), (-b + sqrt(delta))/(2*a));
      else if(delta == 0)
        printf("x = %f\n", (b*-1)/2*a);
      else
        printf("Niema razwiazan\n");
    }
  }

#endif
