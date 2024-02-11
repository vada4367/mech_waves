
//#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "headers/env.h"

const int w = 160, h = 20;

int main(void)
{
  Environment string = new_env(w);

  for (int i = 0; i < string.size; i++)
    string.env[i].pos = sinf(i * 0.1) * 5.0;

  for (;;)
    {
      update_env(&string);
      print_env(string, h);
      
      //for (int i = 20; i < string.size; i++)
      //  printf("%d: %f -- %f\n", i, string.env[i].pos, string.env[i].vel);

      usleep(50000);
    }

  return 0;
}
