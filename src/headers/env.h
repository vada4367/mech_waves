#include "atom.h"

typedef struct
{
  int size;
  Atom *env;
} Environment;

Environment new_env (int size);

int max_pos (Environment string);

void print_env (Environment string, int max_h);

void update_env (Environment *string);
