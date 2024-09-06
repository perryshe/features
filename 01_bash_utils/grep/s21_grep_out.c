#include "global.h"

void printF(int argc, char **argv, int foptind, Flags *Flags,
            patterns *patterns) {
  if (argc - foptind == 1) Flags->hlines_nofiles = 1;
  while (foptind < argc) {
    FILE *f;
    if ((f = fopen(argv[foptind++], "r")) != NULL) {
      grepF(f, Flags, patterns, argv[foptind - 1]);
      fclose(f);
    } else if (!Flags->snowarnings)
      fprintf(stderr, "grep: %s: No such file or directory\n",
              argv[foptind - 1]);
  }
}

void grepF(FILE *f, struct Flags *Flags, struct patterns *patterns,
           char *filename) {
  char lnbuf[10000];
  int lnnum = 0;
  int mlncnt = 0;
  int stop = 0;

  while (fgets(lnbuf, sizeof(lnbuf), f) && !stop) {
    lnnum++;
    if (lnbuf[strlen(lnbuf) - 1] == '\n') lnbuf[strlen(lnbuf) - 1] = '\0';
    int lresult = 0;
    if (Flags->only_matchpartstr) {
      grepo(lnbuf, lnnum, Flags, patterns, filename);
    } else
      lresult = grepl(lnbuf, Flags, patterns, NULL, NULL);
    if ((lresult && !Flags->vinvert_search) ||
        (!lresult && Flags->vinvert_search)) {
      mlncnt++;
      if (!Flags->lmatching_files && !Flags->count_matching &&
          !Flags->only_matchpartstr) {
        printl(lnbuf, lnnum, Flags, filename);
      } else if (Flags->lmatching_files) {
        printf("%s\n", filename);
        stop = 1;
      }
    }
  }
  if (Flags->count_matching) {
    if (!Flags->hlines_nofiles) printf("%s:", filename);
    printf("%d\n", mlncnt);
  }
}

void grepo(char *lnbuf, int lnnum, struct Flags *Flags,
           struct patterns *patterns, char *filename) {
  int no_match = 0;
  char *tbuf = lnbuf;
  if (Flags->only_matchpartstr && !Flags->vinvert_search)
    while (strlen(tbuf) > 0 && !no_match) {
      int subpos = -1;
      int sublen = 0;
      if (grepl(tbuf, Flags, patterns, &subpos, &sublen)) {
        char *obuffer = malloc(sublen + 1);
        memcpy(obuffer, tbuf + subpos, sublen);
        obuffer[sublen] = '\0';
        printl(obuffer, lnnum, Flags, filename);
        free(obuffer);
        tbuf += subpos + sublen;
      } else
        no_match = 1;
    }
}

int grepl(char *lnbuf, struct Flags *Flags, struct patterns *patterns,
          int *subpos, int *sublen) {
  int result = 0;
  regex_t preg;
  int clafg = 0;
  regmatch_t pmatch[100];
  if (Flags->ignor_registr) clafg |= REG_ICASE;
  for (size_t i = 0; i < patterns->count; i++) {
    if (regcomp(&preg, patterns->pattern[i], clafg) == 0)
      if (regexec(&preg, lnbuf, 1, pmatch, 0) == 0) {
        result = 1;
        int olen = pmatch[0].rm_eo - pmatch[0].rm_so;
        if (sublen && subpos)
          if (*subpos == -1 || pmatch[0].rm_so < *subpos ||
              (pmatch[0].rm_so == *subpos && olen > *sublen)) {
            *subpos = pmatch[0].rm_so;
            *sublen = olen;
          }
      }
    regfree(&preg);
  }
  return result;
}

void printl(char *lnbuf, int lnnum, struct Flags *Flags, char *filename) {
  if (!Flags->hlines_nofiles) printf("%s:", filename);
  if (Flags->number_lines_in) printf("%d:", lnnum);
  printf("%s", lnbuf);
  if (lnbuf[strlen(lnbuf) - 1] != '\n') printf("\n");
}

void free_patts(struct patterns *patterns) {
  if (patterns->pattern) {
    for (size_t i = 0; i < patterns->count; i++) free(patterns->pattern[i]);
    free(patterns->pattern);
  }
  patterns->count = 0;
  patterns->pattern = NULL;
}
