#include "global.h"

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