#include <getopt.h>  //arguments comm
#include <regex.h>   //regular expression
#include <stdio.h>   //input/output
#include <stdlib.h>  //memory
#include <string.h>  //strings
#define USE "Use: s21_grep [OPTION]... PATTERNS [FILE]...\n"

typedef struct Flags {
  int epattern;
  int ignor_registr;
  int vinvert_search;
  int count_matching;
  int lmatching_files;
  int number_lines_in;
  int hlines_nofiles;
  int snowarnings;
  int file_retrives_regulars;
  int only_matchpartstr;
} Flags;

typedef struct patterns {
  char **pattern;
  size_t count;
} patterns;

int input_flags(int argc, char **argv, struct Flags *Flags,
                struct patterns *patterns);
void add_patts(struct patterns *patterns, char *pats);
void add_patt(struct patterns *patterns, char *pat, size_t len);
int read_patts(struct patterns *patterns, char *pats_file);
void upd_opt(struct Flags *Flags);
int check_patts(struct patterns *patterns);
void printF(int argc, char **argv, int foptind, Flags *Flags,
            patterns *patterns);
void grepF(FILE *f, struct Flags *Flags, struct patterns *patterns,
           char *filename);
void grepo(char *lnbuf, int lnnum, struct Flags *Flags,
           struct patterns *patterns, char *filename);
void printl(char *lnbuf, int lnnum, struct Flags *Flags, char *filename);
int grepl(char *lnbuf, struct Flags *Flags, struct patterns *patterns,
          int *subpos, int *sublen);
void free_patts(struct patterns *patterns);

int main(int argc, char **argv) {
  struct Flags Flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  struct patterns patterns = {NULL, 0};
  int error = 0;
  int foptind;
  if (argc > 1 && (foptind = input_flags(argc, argv, &Flags, &patterns)) > 0) {
    if (!Flags.file_retrives_regulars && !Flags.epattern) {
      if (foptind < argc) {
        add_patts(&patterns, argv[foptind++]);
      } else
        error = 1;
    }
    if (check_patts(&patterns) && !error) {
      if (foptind < argc) {
        printF(argc, argv, foptind, &Flags, &patterns);
      } else
        printf(USE);
    }
  } else {
    printf(USE);
  }
  free_patts(&patterns);
}

int input_flags(int argc, char **argv, struct Flags *Flags,
                struct patterns *patterns) {
  int currentFlag = 0;
  int result = 1;
  for (currentFlag = getopt(argc, argv, "e:ivclnhsf:o"); currentFlag != -1;
       currentFlag = getopt(argc, argv, "e:ivclnhsf:o")) {
    switch (currentFlag) {
      case 'e':
        Flags->epattern = 1;
        add_patts(patterns, optarg);
        break;
      case 'i':
        Flags->ignor_registr = 1;
        break;
      case 'v':
        Flags->vinvert_search = 1;
        break;
      case 'c':
        Flags->count_matching = 1;
        break;
      case 'l':
        Flags->lmatching_files = 1;
        break;
      case 'n':
        Flags->number_lines_in = 1;
        break;
      case 'h':
        Flags->hlines_nofiles = 1;
        break;
      case 's':
        Flags->snowarnings = 1;
        break;
      case 'f':
        Flags->file_retrives_regulars = 1;
        result = read_patts(patterns, optarg);
        break;
      case 'o':
        Flags->only_matchpartstr = 1;
        break;
      default:
        result = 0;
    }
  }
  upd_opt(Flags);
  if (result) result = optind;
  return result;
}

void add_patts(struct patterns *patterns, char *pats) {
  char *nl;
  while ((nl = strchr(pats, '\n')) != NULL) {
    add_patt(patterns, pats, (size_t)(nl - pats));
    pats = nl + 1;
  }
  add_patt(patterns, pats, strlen(pats));
}

void add_patt(struct patterns *patterns, char *pat, size_t len) {
  if (len > 0) {
    patterns->pattern =
        realloc(patterns->pattern, (patterns->count + 1) * sizeof(char *));
    patterns->pattern[patterns->count] = malloc(len + 1);
    memcpy(patterns->pattern[patterns->count], pat, len);
    patterns->pattern[patterns->count][len] = '\0';
    patterns->count++;
  }
}

int read_patts(struct patterns *patterns, char *pats_file) {
  FILE *f;
  char line[256];
  int result = 1;
  if ((f = fopen(pats_file, "r")) == NULL) {
    printf("file %s not found", pats_file);
    result = 0;
  } else {
    while (fgets(line, sizeof(line), f)) {
      if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';
      add_patt(patterns, line, *line == '\n' ? 0 : strlen(line));
    }
    fclose(f);
  }
  return result;
}

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