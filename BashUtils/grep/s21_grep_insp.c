#include "global.h"

void upd_opt(struct Flags *Flags) {
  if (Flags->lmatching_files) {
    Flags->count_matching = 0;
    Flags->only_matchpartstr = 0;
    Flags->hlines_nofiles = 0;
    Flags->number_lines_in = 0;
  }
  if (Flags->count_matching) {
    Flags->only_matchpartstr = 0;
    Flags->number_lines_in = 0;
  }
}

int check_patts(struct patterns *patterns) {
  int result = 1;
  int regerr;
  regex_t preg;
  for (size_t i = 0; i < patterns->count; i++) {
    if ((regerr = regcomp(&preg, patterns->pattern[i], 0)) != 0) {
      result = 0;
      char errstr[256];
      regerror(regerr, &preg, errstr, sizeof(errstr));
      printf("s21_grep:%s\n", errstr);
    }
    regfree(&preg);
  }
  return result;
}