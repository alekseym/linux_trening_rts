#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_test(int i)
{
  int delta = 123;
  char* mem = (char*)malloc(1024);
  strcpy(mem, "i = ");
  printf("%s %d\n", mem, i + delta);
  /* free(mem); */
}

int main()
{
  int i;
  for(i = 0; i < 10; i++)
    run_test(i);
}
