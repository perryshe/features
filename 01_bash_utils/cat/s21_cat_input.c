#include "global.h"

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