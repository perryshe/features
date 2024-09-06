#include "global.h"

int print_file(FILE *file, struct flags *Flags, struct count *counters) {
  int c;
  while ((c = getc(file)) != EOF) {
    int print_line = 1;
    if (Flags->ssqueeze && c == '\n' && counters->last_char == '\n') {
      if (++counters->empty_lines > 1) print_line = 0;
    } else {
      counters->empty_lines = 0;
    }
    if (print_line) {
      if (Flags->nmarkAll && counters->last_char == '\n')
        printf("%6d\t", counters->lines++);
      if (Flags->number_nonblank && counters->last_char == '\n' && c != '\n')
        printf("%6d\t", counters->lines++);
      if (Flags->ttab && c == '\t') {
        printf("^");
        c = 'I';
      }
      if (Flags->printNonprint && c != '\t' && c != '\n') {
        if (c >= 128) {
          c -= 128;
          printf("M-");
        }
        if (c < 32 || c == 127) {
          c ^= 0x40;
          printf("^");
        }
      }
      if (Flags->emarkEnd && c == '\n') printf("$");
      counters->last_char = c;
      printf("%c", c);
    }
  }
  return 0;
}