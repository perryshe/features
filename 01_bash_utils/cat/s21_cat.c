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