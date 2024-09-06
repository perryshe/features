#include "s21_tests.h"

START_TEST(test_s21_q5sharp_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_3) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
}
END_TEST

START_TEST(test_s21_q5sharp_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
}
END_TEST

START_TEST(test_s21_q5sharp_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_9) {
  char s1[] = " wtf ";
  char *s3 = s21_NULL;
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_11) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_str_eq(s3, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_12) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_str_eq(s3, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_13) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_str_eq(s3, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_14) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_str_eq(s3, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_15) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(s3, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_16) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_str_eq(s3, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_17) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  int rezult = 0;
  if (s3 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
}
END_TEST

START_TEST(test_s21_q5sharp_18) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_19) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_20) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_21) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_22) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_23) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_24) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  int rezult = 0;
  if (s1 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
}
END_TEST

START_TEST(test_s21_q5sharp_25) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_str_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_26) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_27) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_28) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_str_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_29) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = s21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_30) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = s21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_31) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_32) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_str_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_33) {
  char s1[] = "wtf";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_34) {
  char s1[] = "";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  int rezult = 0;
  if (s4 == s21_NULL && s2 == s21_NULL) rezult = 1;
  ck_assert_int_eq(rezult, 1);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_q5sharp_35) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdef");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_36) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 2;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abdefc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_37) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "adefbc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_38) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "defabc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_39) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_40) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_41) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_42) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_43) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_44) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_45) {
  char str1[] = "";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
}
END_TEST

START_TEST(test_s21_q5sharp_46) {
  char str1[] = "";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

Suite *s21_q5sharp(void) {
  Suite *s = suite_create("\033[45ms21_q5sharp\033[0m");
  TCase *tc = tcase_create("s21_q5sharp");

  tcase_add_test(tc, test_s21_q5sharp_1);
  tcase_add_test(tc, test_s21_q5sharp_2);
  tcase_add_test(tc, test_s21_q5sharp_3);
  tcase_add_test(tc, test_s21_q5sharp_4);
  tcase_add_test(tc, test_s21_q5sharp_5);
  tcase_add_test(tc, test_s21_q5sharp_6);
  tcase_add_test(tc, test_s21_q5sharp_7);
  tcase_add_test(tc, test_s21_q5sharp_8);
  tcase_add_test(tc, test_s21_q5sharp_9);
  tcase_add_test(tc, test_s21_q5sharp_10);
  tcase_add_test(tc, test_s21_q5sharp_11);
  tcase_add_test(tc, test_s21_q5sharp_12);
  tcase_add_test(tc, test_s21_q5sharp_13);
  tcase_add_test(tc, test_s21_q5sharp_14);
  tcase_add_test(tc, test_s21_q5sharp_15);
  tcase_add_test(tc, test_s21_q5sharp_16);
  tcase_add_test(tc, test_s21_q5sharp_17);
  tcase_add_test(tc, test_s21_q5sharp_18);
  tcase_add_test(tc, test_s21_q5sharp_19);
  tcase_add_test(tc, test_s21_q5sharp_20);
  tcase_add_test(tc, test_s21_q5sharp_21);
  tcase_add_test(tc, test_s21_q5sharp_22);
  tcase_add_test(tc, test_s21_q5sharp_23);
  tcase_add_test(tc, test_s21_q5sharp_24);
  tcase_add_test(tc, test_s21_q5sharp_25);
  tcase_add_test(tc, test_s21_q5sharp_26);
  tcase_add_test(tc, test_s21_q5sharp_27);
  tcase_add_test(tc, test_s21_q5sharp_28);
  tcase_add_test(tc, test_s21_q5sharp_29);
  tcase_add_test(tc, test_s21_q5sharp_30);
  tcase_add_test(tc, test_s21_q5sharp_31);
  tcase_add_test(tc, test_s21_q5sharp_32);
  tcase_add_test(tc, test_s21_q5sharp_33);
  tcase_add_test(tc, test_s21_q5sharp_34);
  tcase_add_test(tc, test_s21_q5sharp_35);
  tcase_add_test(tc, test_s21_q5sharp_36);
  tcase_add_test(tc, test_s21_q5sharp_37);
  tcase_add_test(tc, test_s21_q5sharp_38);
  tcase_add_test(tc, test_s21_q5sharp_39);
  tcase_add_test(tc, test_s21_q5sharp_40);
  tcase_add_test(tc, test_s21_q5sharp_41);
  tcase_add_test(tc, test_s21_q5sharp_42);
  tcase_add_test(tc, test_s21_q5sharp_43);
  tcase_add_test(tc, test_s21_q5sharp_44);
  tcase_add_test(tc, test_s21_q5sharp_45);
  tcase_add_test(tc, test_s21_q5sharp_46);

  suite_add_tcase(s, tc);
  return s;
}
