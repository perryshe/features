#include "global.h"

int main(int argc, char *argv[]) {
  struct flags Flags = {0, 0, 0, 0, 0, 0};
  struct count counters = {1, 0, '\n'};
  if (argc > 1 && input_flags(argc, argv, &Flags)) {
    if (optind < argc) {
      while (optind < argc) {
        FILE *file = fopen(argv[optind++], "r");
        if (file != NULL) {
          print_file(file, &Flags, &counters);
          fclose(file);
        } else
          fprintf(stderr, "cat: %s: No such file or directory\n",
                  argv[optind - 1]);
      }
    } else {
      printf("no files\n");
    }
  } else {
    printf("Invalid options\n");
  }
}

int input_flags(int argc, char **argv, struct flags *Flags) {
  struct option longOpts[] = {{"number-nonblank", 0, NULL, 'b'},
                              {"number", 0, NULL, 'n'},
                              {"squeeze-blank", 0, NULL, 's'},
                              {NULL, 0, NULL, 0}};
  int result = 1;
  int currentFlag = getopt_long(argc, argv, "bevEnstT", longOpts, NULL);
  for (; currentFlag != -1;
       currentFlag = getopt_long(argc, argv, "+bevEnstT", longOpts, NULL)) {
    switch (currentFlag) {
      case 'v':
        Flags->printNonprint = 1;
        break;
      case 'b':
        Flags->number_nonblank = 1;
        break;
      case 'e':
        Flags->emarkEnd = 1;
        Flags->printNonprint = 1;
        break;
      case 'E':
        Flags->emarkEnd = 1;
        break;
      case 'n':
        Flags->nmarkAll = 1;
        break;
      case 's':
        Flags->ssqueeze = 1;
        break;
      case 't':
        Flags->ttab = 1;
        Flags->printNonprint = 1;
        break;
      case 'T':
        Flags->ttab = 1;
        break;
      default:
        result = 0;
    }
  }
  if (Flags->nmarkAll && Flags->number_nonblank) Flags->nmarkAll = 0;
  return result;
}

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