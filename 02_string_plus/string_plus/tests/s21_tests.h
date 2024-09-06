#ifndef TESTS_H
#define TESTS_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_SQRT2
#define M_SQRT2 1.41421356237309504880
#endif

#ifndef M_E
#define M_E 2.71828182845904523536
#endif

#include <check.h>
#include <string.h>

#include "../s21_string.h"

#define BUFF_SIZE (512)

Suite *s21_q1strng_test(void);
Suite *s21_q23sprintf_test(void);
Suite *s21_q4sscanf_test(void);
Suite *s21_q5sharp(void);

#endif
