
#include "headers/env.h"

int
main (void)
{
  Environment string = new_env (20);
  string.env[10].pos = 2.0;
  update_env(&string);
  print_env (string, 10);
  return 0;
}
