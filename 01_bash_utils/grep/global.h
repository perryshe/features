#ifndef GLOBAL_H
#define GLOBAL_H

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

#endif