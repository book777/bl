/* Example:
int main(int argc, char **argv)
{
    if(argc < 2) {
        fputs("Need an argument.\n", stderr);
        return 1;
    }
    char *result = file_read(argv[1]);
    if(!result) return -1;
    fputs(result, stdout);
    free(result);
    return 0;
}
*/
#ifndef _H_FILE
  #define _H_FILE

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  char *bl_file_read(const char *filename)
  {
      long int size = 0;
      FILE *file = fopen(filename, "r");

      if(!file) {
          fputs("No file.\n", stderr);
          return 0;
      }

      fseek(file, 0, SEEK_END);
      size = ftell(file);
      rewind(file);

      char *result = (char*)malloc(size);
      if(!result) {
          fputs("Memory error.\n", stderr);
          return 0;
      }

      if(fread(result, 1, size, file) != (unsigned)size) {
          fputs("Read error.\n", stderr);
          return 0;
      }

      fclose(file);
      return result;
  }

  int bl_file_strlen(char *s) {
    int tmp;
    tmp=strlen(s);
    if(tmp>0)
      return --tmp;
    else
      return 0;
  }

#endif
