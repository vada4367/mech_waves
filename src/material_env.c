
#include <stdio.h>
#include <stdlib.h>
#include "headers/atom.h"

typedef struct {
  int size;
  Atom *env;
} Environment;

Environment
new_env(int size)
{
  Atom *string = malloc (sizeof(Atom) * size);
  for (int i = 0; i < size; i++)
    {
      string[i].pos = 0;
      string[i].mass = 1;
    }

  Environment env = { size, string };

  return env;
}

int
max_pos(Environment string)
{
  int max = 0;
  for (int i = 0; i < string.size; i++)
    if (max < abs((int)string.env[i].pos))
      max = abs((int)string.env[i].pos);

  return max;
}

void
print_env(Environment string, int max_h)
{
  char *frame = malloc (sizeof(char) * (2 * max_h * string.size + 1));
  for (int i = 0; i < 2 * max_h * string.size + 1; i++)
    frame[i] = ' ';

  float max_pos_h = (float)max_pos(string);
  for (int i = 0; i < string.size; i++)
    {
      int y = (int)((string.env[i].pos * (float)max_h / max_pos_h)*0.9) + max_h;
      frame[i + y * string.size] = '#';
    }

  printf("\x1B[H");
  for (int i = 0; i < 2 * max_h * string.size + 1; i++)
    {
      printf("%c", frame[i]);
      if (!(i % string.size))
        printf("\n");
    }
}
