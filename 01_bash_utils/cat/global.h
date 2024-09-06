#ifndef GLOBAL_H
#define GLOBAL_H

#include <getopt.h>  // for getopt_long
#include <stdio.h>   // for printf
#include <stdlib.h>  // for exit

struct flags {
  int number_nonblank;
  int emarkEnd;
  int nmarkAll;
  int ssqueeze;
  int ttab;
  int printNonprint;
};

struct count {
  int lines;
  int empty_lines;
  char last_char;
};

int input_flags(int argc, char **argv, struct flags *Flags);
int print_file(FILE *file, struct flags *Flags, struct count *counters);

#endif