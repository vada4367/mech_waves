
#include "headers/atom.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int size;
  Atom *env;
} Environment;

Environment
new_env (int size)
{
  Atom *string = malloc (sizeof (Atom) * size);
  for (int i = 0; i < size; i++)
    {
      string[i].pos = 0;
      string[i].vel = 0;
      string[i].mass = 1;
    }

  Environment env = { size, string };

  return env;
}

int
max_pos (Environment string)
{
  int max = 0;
  for (int i = 0; i < string.size; i++)
    if (max < abs ((int)string.env[i].pos))
      max = abs ((int)string.env[i].pos);

  return max;
}

void
print_env (Environment string, int max_h)
{
  printf("\x1B[H\x1B[J");
  for (int i = 0; i < string.size; i++)
    {
      int y = (int)string.env[i].pos + max_h;
      if (i < 0)
        y = 0;
      if (i > max_h)
        y = max_h;
      
      printf("\x1B[%d;%dH#", y, i);
    }
}

void
update_env (Environment *string)
{
  for (int i = 0; i < string->size; i++)
    string->env[i].pos += string->env[i].vel;
  for (int i = 1; i < string->size - 1; i++)
    string->env[i].vel += ((string->env[i - 1].pos + string->env[i + 1].pos) / 2 - string->env[i].pos) / string->env[i].mass;
}
