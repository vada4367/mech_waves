
// #include <stdio.h>
#include "headers/env.h"
#include <math.h>
#include <unistd.h>

const int W = 159, H = 20;

int
main (void)
{
  Environment string = new_env (W);

  for (int i = 0; i < string.size; i++)
    string.env[i].pos = sinf (i * 0.1) * 5.0;

  for (;;)
    {
      update_env (&string);

      print_env (string, H);
      // for (int i = 00; i < string.size; i++)
      //   printf("%d: %f -- %f\n", i, string.env[i].pos, string.env[i].vel);

      usleep (50000);
    }

  return 0;
}
