
#include "headers/env.h"
#include <unistd.h>
#include <stdlib.h>

int
main (void)
{
  Environment string = new_env (20);
  string.env[10].pos = 2.0;
  for (;;)
    {
      update_env (&string);
      //system ("clear");
      print_env (string, 10);
      usleep(2000000);
    }
  return 0;
}
