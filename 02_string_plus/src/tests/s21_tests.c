#include "s21_tests.h"

#include <limits.h>
int main() {
  int failed = 0;
  Suite *s21_string_test[] = {s21_q23sprintf_test(), s21_q1strng_test(),
                              s21_q5sharp(), s21_q4sscanf_test(), s21_NULL};

  for (int i = 0; s21_string_test[i] != s21_NULL; i++) {
    SRunner *sr = s21_NULL;
    sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    printf("\n");
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}
