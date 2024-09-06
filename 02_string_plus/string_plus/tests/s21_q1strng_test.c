#include "s21_tests.h"

// 1

START_TEST(test_s21_memchr) {
  struct {
    char *str;
    char c;
    size_t len;
  } test_cases[] = {
      {"Hello world", 'o', strlen("Hello world")},
      {"Hello world\n\0", 'o', strlen("Hello world\n\0")},
      {"a\n\0", 'o', strlen("a\n\0")},
      {" \n\0", 'o', strlen(" \n\0")},
      {" \0", 'o', strlen(" \0")},
      {"\n\0", 'o', strlen("\n\0")},
      {"\0", 'o', strlen("\0")},
  };

  for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
    void *ptr =
        s21_memchr(test_cases[i].str, test_cases[i].c, test_cases[i].len);
    void *std_ptr =
        memchr(test_cases[i].str, test_cases[i].c, test_cases[i].len);
    ck_assert_ptr_eq(ptr, std_ptr);
  }
}
END_TEST

// 2

START_TEST(test_s21_memcmp) {
  char str_1[] = "Hello world\n\0";
  char str_2[] = "Hello world";
  char str_3[] = "a\n\0";
  char str_4[] = " \n\0";
  char str_5[] = " \0";
  int result_1 = s21_memcmp(str_1, str_2, strlen(str_1));
  int result_2 = s21_memcmp(str_1, str_3, strlen(str_1));
  int result_3 = s21_memcmp(str_1, str_4, strlen(str_1));
  int result_4 = s21_memcmp(str_1, str_5, strlen(str_1));
  int std_result_1 = memcmp(str_1, str_2, strlen(str_1));
  int std_result_2 = memcmp(str_1, str_3, strlen(str_1));
  int std_result_3 = memcmp(str_1, str_4, strlen(str_1));
  int std_result_4 = memcmp(str_1, str_5, strlen(str_1));
  ck_assert_int_eq(result_1, std_result_1);
  ck_assert_int_eq(result_2, std_result_2);
  ck_assert_int_eq(result_3, std_result_3);
  ck_assert_int_eq(result_4, std_result_4);
}
END_TEST

// 3

START_TEST(test_s21_memcpy) {
  char dest[10] = "abcdefgh";
  char src[] = "12345678";
  s21_memcpy(dest, src, 4);
  char std_dest[10] = "abcdefgh";
  memcpy(std_dest, src, 4);
  ck_assert_mem_eq(dest, std_dest, 4);
}
END_TEST

// 4

START_TEST(test_s21_memset) {
  char str_1[15] = "abcdefgh";
  char str_2[15] = "a\n\0";
  char str_3[15] = "\0";
  char str_4[15] = " \n\0";
  char str_5[15] = " \0";
  s21_memset(str_1, 'x', 4);
  s21_memset(str_2, 'x', 4);
  s21_memset(str_3, 'x', 4);
  s21_memset(str_4, 'x', 4);
  s21_memset(str_5, '\0', 1);

  char std_str_1[15] = "abcdefgh";
  char std_str_2[15] = "a\n\0";
  char std_str_3[15] = "\0";
  char std_str_4[15] = " \n\0";
  char std_str_5[15] = " \0";
  memset(std_str_1, 'x', 4);
  memset(std_str_2, 'x', 4);
  memset(std_str_3, 'x', 4);
  memset(std_str_4, 'x', 4);
  memset(std_str_5, '\0', 1);
  ck_assert_str_eq(str_1, std_str_1);
  ck_assert_str_eq(str_2, std_str_2);
  ck_assert_str_eq(str_3, std_str_3);
  ck_assert_str_eq(str_4, std_str_4);
  ck_assert_str_eq(str_5, std_str_5);
}
END_TEST

// 5

START_TEST(test_s21_strncat) {
  char str_1[20] = "Hello world\n\0";
  char str_2[20] = "Hello world";
  char str_3[20] = " WOW Cool\0";
  char str_4[20] = " \n\0";
  s21_strncat(str_1, str_2, 5);
  s21_strncat(str_2, str_3, 5);
  s21_strncat(str_4, str_3, 5);

  char std_str_1[20] = "Hello world\n\0";
  char std_str_2[20] = "Hello world";
  char std_str_3[20] = " WOW Cool\0";
  char std_str_4[20] = " \n\0";
  strncat(std_str_1, std_str_2, 5);
  strncat(std_str_2, std_str_3, 5);
  strncat(std_str_4, std_str_3, 5);
  ck_assert_str_eq(str_1, std_str_1);
  ck_assert_str_eq(str_2, std_str_2);
  ck_assert_str_eq(str_4, std_str_4);
}
END_TEST

// 6

START_TEST(test_s21_strchr) {
  char str[] = "hello world";
  char *result = s21_strchr(str, 'l');
  ck_assert_ptr_eq(result, str + 2);

  char str2[] = "hello world";
  char *result2 = s21_strchr(str2, 'h');
  ck_assert_ptr_eq(result2, str2);

  char str3[] = "hello world";
  char *result3 = s21_strchr(str3, 'd');
  ck_assert_ptr_eq(result3, str3 + 10);

  char str4[] = "hello world";
  char *result4 = s21_strchr(str4, 'x');
  ck_assert_ptr_eq(result4, NULL);

  char str5[] = "";
  char *result5 = s21_strchr(str5, 'x');
  ck_assert_ptr_eq(result5, NULL);

  char str6[] = "a";
  char *result6 = s21_strchr(str6, 'a');
  ck_assert_ptr_eq(result6, str6);

  char str7[] = "hellohello";
  char *result7 = s21_strchr(str7, 'l');
  ck_assert_ptr_eq(result7, str7 + 2);
}
END_TEST

// 7

START_TEST(test_s21_strncmp) {
  char str1[] = "hello";
  char str2[] = "hello";
  //  char str3[] = "WOW";
  //  char str4[] = "D&D";
  int result_1 = s21_strncmp(str1, str2, strlen(str1));
  //  int result_2 = s21_strncmp(str1, str3, strlen(str1));
  //  int result_3 = s21_strncmp(str1, str4, strlen(str1));
  int std_result_1 = strncmp(str1, str2, strlen(str1));
  //  int std_result_2 = strncmp(str1, str3, strlen(str1));
  //  int std_result_3 = strncmp(str1, str4, strlen(str1));
  ck_assert_int_eq(result_1, std_result_1);
  //  ck_assert_int_eq(result_2, std_result_2);
  //  ck_assert_int_eq(result_3, std_result_3);
}
END_TEST

// 8

START_TEST(test_s21_strncpy) {
  char dest[20] = "abcdefgh";
  char src[] = "1234";
  s21_strncpy(dest, src, 10);
  char std_dest[20] = "abcdefgh";
  strncpy(std_dest, src, 10);
  ck_assert_str_eq(dest, std_dest);

  char dest2[20] = "abcdefgh";
  char src2[] = "1234567890";
  s21_strncpy(dest2, src2, 5);
  char std_dest2[20] = "abcdefgh";
  strncpy(std_dest2, src2, 5);
  ck_assert_str_eq(dest2, std_dest2);

  char dest3[20] = "abcdefgh";
  char src3[] = "";
  s21_strncpy(dest3, src3, 10);
  char std_dest3[20] = "abcdefgh";
  strncpy(std_dest3, src3, 10);
  ck_assert_str_eq(dest3, std_dest3);

  char dest4[20] = "abcdefgh";
  char src4[] = "12345678";
  char std_dest4[20] = "abcdefgh";
  s21_strncpy(dest4, src4, 0);
  strncpy(std_dest4, src4, 0);
  ck_assert_str_eq(dest4, std_dest4);

  char dest5[20] = "abcdefgh";
  char src5[] = "12345678";
  char *ptr = dest5 + 5;
  s21_strncpy(ptr, src5, 5);
  char std_dest5[20] = "abcdefgh";
  char *std_ptr = std_dest5 + 5;
  strncpy(std_ptr, src5, 5);
  ck_assert_str_eq(dest5, std_dest5);

  char dest6[20] = "abcdefgh";
  char src6[] = "123";
  s21_strncpy(dest6, src6, 10);
  char std_dest6[20] = "abcdefgh";
  strncpy(std_dest6, src6, 10);
  ck_assert_str_eq(dest6, std_dest6);
}
END_TEST

// 9

START_TEST(test_s21_strcspn) {
  char str1[] = "hello";
  char str2[] = "lo";
  s21_size_t len = s21_strcspn(str1, str2);
  s21_size_t std_len = strcspn(str1, str2);
  ck_assert_uint_eq(len, std_len);
}
END_TEST

// 10

START_TEST(test_s21_strerror) {
  ck_assert_str_eq(strerror(500), s21_strerror(500));
  ck_assert_str_eq(strerror(1), s21_strerror(1));
  ck_assert_str_eq(strerror(-56), s21_strerror(-56));

  // Дополнительные тесты
  ck_assert_str_eq(strerror(0), s21_strerror(0));
  ck_assert_str_eq(strerror(EINVAL), s21_strerror(EINVAL));
  ck_assert_str_eq(strerror(ERANGE), s21_strerror(ERANGE));
  ck_assert_str_eq(strerror(INT_MAX), s21_strerror(INT_MAX));
  ck_assert_str_eq(strerror(INT_MIN + 1), s21_strerror(INT_MIN + 1));

  // Тесты с недопустимыми кодами ошибок
  ck_assert_str_eq(strerror(-1), s21_strerror(-1));
  ck_assert_str_eq(strerror(INT_MIN), s21_strerror(INT_MIN));

  // Тест с NULL-входом (если s21_strerror позволяет это)
  ck_assert_str_eq(strerror(0), s21_strerror(0));
}
END_TEST

// 11

START_TEST(test_s21_strlen) {
  char str[] = "hello";
  s21_size_t len = s21_strlen(str);
  s21_size_t std_len = strlen(str);
  ck_assert_uint_eq(len, std_len);
}
END_TEST

// 12

START_TEST(test_s21_strpbrk) {
  char str_1[] = "30245043704281\n\0";
  char str_2[] = "hello World";
  char str_3[] = " WOW Cool\0";
  char str_4[] = "Hello world\n\0";
  char str_5[] = " 1111121111\0";
  char str_6[] = "=";
  ck_assert_str_eq(strpbrk(str_2, str_3), s21_strpbrk(str_2, str_3));
  ck_assert_str_eq(strpbrk(str_2, str_4), s21_strpbrk(str_2, str_4));
  ck_assert_str_eq(strpbrk(str_1, str_5), s21_strpbrk(str_1, str_5));
  ck_assert(strpbrk(str_1, str_6) == s21_strpbrk(str_1, str_6));
}
END_TEST

// 13

START_TEST(test_s21_strrchr) {
  char str_1[] = "Hello world\n\0";
  char str_2[] = "Hello world";
  char str_3[] = " WOW Cool\0";
  char str_4[] = " \n\0";
  char str_5[] = " \0";

  ck_assert_ptr_eq(strrchr(str_1, 'o'), s21_strrchr(str_1, 'o'));
  ck_assert_ptr_eq(strrchr(str_1, 'z'), s21_strrchr(str_1, 'z'));
  ck_assert_ptr_eq(strrchr(str_2, 'o'), s21_strrchr(str_2, 'o'));
  ck_assert_ptr_eq(strrchr(str_3, 'G'), s21_strrchr(str_3, 'G'));
  ck_assert_ptr_eq(strrchr(str_4, '\n'), s21_strrchr(str_4, '\n'));
  ck_assert_ptr_eq(strrchr(str_5, '4'), s21_strrchr(str_5, '4'));
}
END_TEST

// //14

START_TEST(test_s21_strstr) {
  char str[] = "Hello, world!";
  char str1[] = ", ";
  char str2[] = ",";
  char str3[] = "Hello, world!";
  char str4[] = "H";
  char str5[] = "!";
  char str6[] = "wo";
  char str7[] = "l";
  char str8[] = " ";
  char str9[] = "\0";
  char str10[] = "o,";

  ck_assert(strstr(str1, str) == s21_strstr(str1, str));
  ck_assert(strstr(str2, str) == s21_strstr(str2, str));
  ck_assert(strstr(str3, str) == s21_strstr(str3, str));
  ck_assert(strstr(str4, str) == s21_strstr(str4, str));
  ck_assert(strstr(str5, str) == s21_strstr(str5, str));
  ck_assert(strstr(str6, str) == s21_strstr(str6, str));
  ck_assert(strstr(str7, str) == s21_strstr(str7, str));
  ck_assert(strstr(str8, str) == s21_strstr(str8, str));
  ck_assert(strstr(str9, str) == s21_strstr(str9, str));
  ck_assert(strstr(str10, str) == s21_strstr(str10, str));
  ck_assert(strstr(str, str9) == s21_strstr(str, str9));
}
END_TEST

// //15

START_TEST(test_s21_strtok) {
  char str[] = "hello world";
  char *token = s21_strtok(str, " ");
  ck_assert_str_eq(token, "hello");
  token = s21_strtok(NULL, " ");
  ck_assert_str_eq(token, "world");
  token = s21_strtok(NULL, " ");
  ck_assert_ptr_eq(token, NULL);

  char str2[] = "hello,,world";
  token = s21_strtok(str2, ",");
  ck_assert_str_eq(token, "hello");
  token = s21_strtok(NULL, ",");
  ck_assert_str_eq(token, "world");
  token = s21_strtok(NULL, ",");
  ck_assert_ptr_eq(token, NULL);

  char str3[] = ",,hello,world";
  token = s21_strtok(str3, ",");
  ck_assert_str_eq(token, "hello");
  token = s21_strtok(NULL, ",");
  ck_assert_str_eq(token, "world");
  token = s21_strtok(NULL, ",");
  ck_assert_ptr_eq(token, NULL);

  char str4[] = "hello,world,,";
  token = s21_strtok(str4, ",");
  ck_assert_str_eq(token, "hello");
  token = s21_strtok(NULL, ",");
  ck_assert_str_eq(token, "world");
  token = s21_strtok(NULL, ",");
  ck_assert_ptr_eq(token, NULL);

  char str5[] = "";
  token = s21_strtok(str5, ",");
  ck_assert_ptr_eq(token, NULL);

  token = s21_strtok(NULL, ",");
  ck_assert_ptr_eq(token, NULL);
}
END_TEST

Suite *s21_q1strng_test(void) {
  Suite *s = suite_create("\033[45ms21_q1strng_test\033[0m");
  TCase *tc = tcase_create("s21_q1strng_test");

  tcase_add_test(tc, test_s21_memchr);
  tcase_add_test(tc, test_s21_memcmp);
  tcase_add_test(tc, test_s21_memcpy);
  tcase_add_test(tc, test_s21_memset);
  tcase_add_test(tc, test_s21_strlen);
  tcase_add_test(tc, test_s21_strcspn);
  tcase_add_test(tc, test_s21_strncmp);
  tcase_add_test(tc, test_s21_strncat);
  tcase_add_test(tc, test_s21_strchr);
  tcase_add_test(tc, test_s21_strncpy);
  tcase_add_test(tc, test_s21_strerror);
  tcase_add_test(tc, test_s21_strpbrk);
  tcase_add_test(tc, test_s21_strrchr);
  tcase_add_test(tc, test_s21_strstr);
  tcase_add_test(tc, test_s21_strtok);
  suite_add_tcase(s, tc);
  return s;
}
