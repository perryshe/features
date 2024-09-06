#include "s21_tests.h"

START_TEST(sprintf_string_1) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "padding:\t[%20s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_2) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "padding:\t[%-20s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_3) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "padding:\t[%*s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, 20, _1);
  int s21_res = s21_sprintf(s21_str, format, 20, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_4) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "trunc:\t[%.5s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_5) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "trunc:\t[%*s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, 4, _1);
  int s21_res = s21_sprintf(s21_str, format, 4, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_6) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "\t[%10.5s]\n\t[%-10.5s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_7) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "\t[%*.*s]\n\t[%-*.*s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, 10, 4, _1, 10, 4, _1);
  int s21_res = s21_sprintf(s21_str, format, 10, 4, _1, 10, 4, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_8) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "wide string:\t[%s %10s][%-10s][%s]\n";
  char *_1 = "Hello,";
  char *_2 = "world!";
  int res = sprintf(str, format, _1, _2, _2, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_1) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "chars:\t[%c%%]\n";
  char _1 = '1';
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_2) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "chars:\t[%4.5c%%]\n";
  char _1 = '1';
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_3) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "chars:\t[%-*c%%]\n";
  char _1 = '1';
  int res = sprintf(str, format, 5, _1);
  int s21_res = s21_sprintf(s21_str, format, 5, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_4) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "chars:\t[%-*c]\t[%10c]\n";
  char _1 = '1';
  char _2 = '2';
  int res = sprintf(str, format, 5, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, 5, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_5) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "wide char:\t[%c][%-5lc][%5lc][%lc]\n";
  char _1 = 'H';
  wchar_t _2 = L'w', _3 = L'!';
  int res = sprintf(str, format, _1, _2, _3, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_6) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "wide char:\t[%hc][%-5lc][%5Lc][%-Lc]\n";
  char _1 = 'H';
  wchar_t _2 = L'w', _3 = L'!';
  int res = sprintf(str, format, _1, _2, _3, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_1) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "dec:\t% i %d %+i % +d %.6i % .6d %4.2i %4.2d %+.0i %+.0d\n";
  int _1 = 1;
  int _2 = 2;
  int _3 = 3;
  int _4 = 4;
  int _5 = 5;
  int res = sprintf(str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  int s21_res =
      s21_sprintf(s21_str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_2) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "dec:\t%i %d %+i %+d %.6i %.6d %4.2i %4.2d %+.0i %+.0d\n";
  int _1 = 0;
  int res = sprintf(str, format, _1, _1, _1, _1, _1, _1, _1, _1, _1, _1);
  int s21_res =
      s21_sprintf(s21_str, format, _1, _1, _1, _1, _1, _1, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_3) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "dec:\t%i %d %+i %+d %.6i %.6d %4.2i %4.2d %+.0i %+.0d\n";
  int _1 = -1;
  int _2 = -2;
  int _3 = -3;
  int _4 = -4;
  int _5 = -5;
  int res = sprintf(str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  int s21_res =
      s21_sprintf(s21_str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_4) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "hex:\t%x %x %X %#x\n";
  int _1 = 1;
  int _2 = 10;
  int _3 = 11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_5) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "hex:\t%4x %4x %4X %#4x\n";
  int _1 = 1;
  int _2 = 10;
  int _3 = 11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_6) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "hex:\t%4.2x %4.2x %4.2X %#4.4X\n";
  int _1 = 1;
  int _2 = 10;
  int _3 = 11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_7) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "hex:\t%4.2x %4.2x %4.2X %#4.4x\n";
  int _1 = -1;
  int _2 = -10;
  int _3 = -11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_8) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "hex:\t%4.2x %4.2x %4.2X %#4.4x\n";
  int _1 = 0;

  int res = sprintf(str, format, _1, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_9) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "hex:\t%+4.0x %+4.0x %+4.0X %#+4.0x\n";
  int _1 = 0;

  int res = sprintf(str, format, _1, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_10) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "oct:\t%o %+o %#o %#o\n";
  int _1 = 4;
  int _2 = 10;
  int res = sprintf(str, format, _1, _2, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_11) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "oct:\t%-4o %+4o %-#4o %-#5.4o\n";
  int _1 = 4;
  int _2 = 10;
  int res = sprintf(str, format, _1, _2, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_12) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "oct:\t% -4o % +4o %-#4o %-#5.4o\n";
  int _1 = -4;
  int _2 = -10;
  int res = sprintf(str, format, _1, _2, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_13) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "oct:\t%-4.0o %+4.0o %-#4.0o %-#5.0o\n";
  int _1 = 0;
  int res = sprintf(str, format, _1, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_14) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "unsign:\t%-*u %+.2u %6.0u %u\n";
  int _1 = 4;
  int _2 = 10;
  int _3 = 0;
  int _4 = -4;
  int res = sprintf(str, format, 4, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 4, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_15) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "wide int:\t%-*hd %+.2d %6.0hu %lu\n";
  short int _1 = 4;
  int _2 = 10;
  short int _3 = 0;
  long int _4 = 40;
  int res = sprintf(str, format, 4, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 4, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_16) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "wide int:\t%-*hx %+.2x %6.0hX %lX\n";
  short int _1 = 4;
  int _2 = 10;
  short int _3 = 0;
  long int _4 = 40;
  int res = sprintf(str, format, 4, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 4, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_1) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "round:\t%.*f % .0f %.0f %.16f\n";
  double _1 = M_PI;
  double _2 = M_SQRT2;
  double _3 = M_E;
  double _4 = M_PI;
  int res = sprintf(str, format, 1, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 1, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_2) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "padding:\t%*.2lf %+7.2lf % .2f %05.2f\n";
  double _1 = -1 / M_PI;
  double _2 = M_SQRT2;
  double _3 = M_E;
  double _4 = M_PI;
  int res = sprintf(str, format, -10, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, -10, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_3) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "sci:\t%E %e % -+10.0E %+.8e\n";
  double _1 = -1 / M_PI;
  double _2 = M_SQRT2 * 100;
  double _3 = M_E / 1e+6;
  double _4 = M_PI;
  int res = sprintf(str, format, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_4) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "sci:\t%G %g % +-10.0G %+.7g\n";
  double _1 = -1 / M_PI;
  double _2 = M_SQRT2 * 100;
  double _3 = M_E / 1e+6;
  double _4 = M_PI;
  int res = sprintf(str, format, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_5) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "spec:\t\t%Lf %Le %LE %LG\n";
  long double _1 = -1 / M_PI;
  long double _2 = M_SQRT2 * 100;
  long double _3 = M_E / 1e+6;
  long double _4 = M_PI;
  int res = sprintf(str, format, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_6) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  // char *format = "zero:\t%-#+5.0f%#+ 010.2e% 10E%#+ 010g% G\n";
  char *format = "zero:\t%-+5.0f%#+ 10.2e% 10E%+ 10g% G\n";
  float _1 = 0.0;
  float _2 = 0.0;

  int res = sprintf(str, format, _1, _2, _1, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_ptr_1) {
  char str[BUFF_SIZE] = {0};
  char s21_str[BUFF_SIZE] = {0};
  char *format = "ptr:\t%p %20p %-20p\n";
  int test_var = 10;
  int *_1 = &test_var;

  int res = sprintf(str, format, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST
START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);

  // hex = 0.0000334;
  // s21_sprintf(str1, format, hex);
  // sprintf(str2, format, hex);
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(percent) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% % % % % % %d";

  ck_assert_int_eq(s21_sprintf(str1, format, 4), sprintf(str2, format, 4));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_q23sprintf_test(void) {
  Suite *s = suite_create("\033[45ms21_q23sprintf_test\033[0m");
  TCase *tc = tcase_create("s21_q23sprintf_test");

  tcase_add_test(tc, sprintf_string_1);
  tcase_add_test(tc, sprintf_string_2);
  tcase_add_test(tc, sprintf_string_3);
  tcase_add_test(tc, sprintf_string_4);
  tcase_add_test(tc, sprintf_string_5);
  tcase_add_test(tc, sprintf_string_6);
  tcase_add_test(tc, sprintf_string_7);
  tcase_add_test(tc, sprintf_string_8);

  tcase_add_test(tc, sprintf_char_1);
  tcase_add_test(tc, sprintf_char_2);
  tcase_add_test(tc, sprintf_char_3);
  tcase_add_test(tc, sprintf_char_4);
  tcase_add_test(tc, sprintf_char_5);
  tcase_add_test(tc, sprintf_char_6);

  tcase_add_test(tc, sprintf_int_1);
  tcase_add_test(tc, sprintf_int_2);
  tcase_add_test(tc, sprintf_int_3);
  tcase_add_test(tc, sprintf_int_4);
  tcase_add_test(tc, sprintf_int_5);
  tcase_add_test(tc, sprintf_int_6);
  tcase_add_test(tc, sprintf_int_7);
  tcase_add_test(tc, sprintf_int_8);
  tcase_add_test(tc, sprintf_int_9);
  tcase_add_test(tc, sprintf_int_10);
  tcase_add_test(tc, sprintf_int_11);
  tcase_add_test(tc, sprintf_int_12);
  tcase_add_test(tc, sprintf_int_13);
  tcase_add_test(tc, sprintf_int_14);
  tcase_add_test(tc, sprintf_int_15);
  tcase_add_test(tc, sprintf_int_16);

  tcase_add_test(tc, sprintf_float_1);
  tcase_add_test(tc, sprintf_float_2);
  tcase_add_test(tc, sprintf_float_3);
  tcase_add_test(tc, sprintf_float_4);
  tcase_add_test(tc, sprintf_float_5);
  tcase_add_test(tc, sprintf_float_6);
  tcase_add_test(tc, sprintf_ptr_1);
  ////different_tests
  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, precise_int);
  tcase_add_test(tc, width_int);
  tcase_add_test(tc, minus_width_int);
  tcase_add_test(tc, plus_width_int);
  tcase_add_test(tc, padding_int);
  tcase_add_test(tc, star_width_int);
  tcase_add_test(tc, star_precision_int);
  tcase_add_test(tc, many_flags_many_ints);
  tcase_add_test(tc, flags_long_int);
  tcase_add_test(tc, flags_short_int);
  tcase_add_test(tc, flags_another_long_int);
  tcase_add_test(tc, zero_precision_zero_int);
  tcase_add_test(tc, space_flag_int);
  tcase_add_test(tc, unsigned_val);
  tcase_add_test(tc, unsigned_val_width);
  tcase_add_test(tc, unsigned_val_flags);
  tcase_add_test(tc, unsigned_val_precision);
  tcase_add_test(tc, unsigned_val_many_flags);
  tcase_add_test(tc, unsigned_val_short);
  tcase_add_test(tc, unsigned_val_long);
  tcase_add_test(tc, unsigned_val_many);
  tcase_add_test(tc, octal);
  tcase_add_test(tc, octal_width);
  tcase_add_test(tc, octal_flags);
  tcase_add_test(tc, octal_precision);
  tcase_add_test(tc, octal_many_flags);
  tcase_add_test(tc, octal_short);
  tcase_add_test(tc, octal_long);
  tcase_add_test(tc, octal_many);
  tcase_add_test(tc, octal_zero);
  tcase_add_test(tc, octal_hash);
  tcase_add_test(tc, unsigned_zero);
  tcase_add_test(tc, hex_width);
  tcase_add_test(tc, hex_precision);
  tcase_add_test(tc, hex_many_flags);
  tcase_add_test(tc, hex_zero);
  tcase_add_test(tc, hex_huge);
  tcase_add_test(tc, hex_short);
  tcase_add_test(tc, hex_long);
  tcase_add_test(tc, hex_one_longer_width);
  tcase_add_test(tc, hex_two_longer_width);
  tcase_add_test(tc, one_char);
  tcase_add_test(tc, one_precision);
  tcase_add_test(tc, one_flags);
  tcase_add_test(tc, one_width);
  tcase_add_test(tc, one_many);
  tcase_add_test(tc, one_many_flags);
  tcase_add_test(tc, string);
  tcase_add_test(tc, string_precision);
  tcase_add_test(tc, string_width);
  tcase_add_test(tc, string_flags);
  tcase_add_test(tc, string_long);
  tcase_add_test(tc, string_many);
  tcase_add_test(tc, ptr);
  tcase_add_test(tc, ptr_width);
  tcase_add_test(tc, ptr_precision);
  tcase_add_test(tc, string_width_huge);
  tcase_add_test(tc, float_precision);
  tcase_add_test(tc, float_width);
  tcase_add_test(tc, float_precision_zero);
  tcase_add_test(tc, float_precision_empty);
  tcase_add_test(tc, float_huge);
  tcase_add_test(tc, float_flags);
  tcase_add_test(tc, e_precision_zero);
  tcase_add_test(tc, e_precision_empty);
  tcase_add_test(tc, e_huge);
  tcase_add_test(tc, e_width);
  tcase_add_test(tc, e_flags);
  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, empty_format_and_parameters);
  tcase_add_test(tc, test_one_char);
  tcase_add_test(tc, test_many_char);
  tcase_add_test(tc, test_one_string);
  tcase_add_test(tc, test_many_string);
  tcase_add_test(tc, test_one_dec);
  tcase_add_test(tc, test_many_dec);
  tcase_add_test(tc, test_one_int);
  tcase_add_test(tc, test_many_int);
  tcase_add_test(tc, test_one_float);
  tcase_add_test(tc, test_one_unsigned_dec);
  tcase_add_test(tc, test_many_unsigned_dec);
  tcase_add_test(tc, test_one_char_with_alignment_left);
  tcase_add_test(tc, test_one_char_with_alignment_right);
  tcase_add_test(tc, test_many_char_with_alignment);
  tcase_add_test(tc, test_many_hex_lower);
  tcase_add_test(tc, test_many_hex_upper);
  tcase_add_test(tc, test_many_hex_lower_with_alignment);
  tcase_add_test(tc, test_many_hex_upper_with_alignment);
  tcase_add_test(tc, test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc, test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc, test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc, test_many_hex_upper_with_width_star);
  tcase_add_test(tc, test_one_hex_lower_with_precision);
  tcase_add_test(tc, test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc, test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc, test_one_hex_lower_with_length);
  tcase_add_test(tc, test_one_hex_upper_with_length);
  tcase_add_test(tc, g_trailing_zero);
  tcase_add_test(tc, g_large);
  tcase_add_test(tc, g_small);
  tcase_add_test(tc, g_precision);
  tcase_add_test(tc, g_precision_zero);
  tcase_add_test(tc, g_precision_missing);
  tcase_add_test(tc, g_many_zeroes_in_front);
  tcase_add_test(tc, g_one_zero);
  tcase_add_test(tc, g_mantiss);
  tcase_add_test(tc, g_short_no_mantiss);
  tcase_add_test(tc, LG);
  tcase_add_test(tc, g_many);
  tcase_add_test(tc, g_zero);
  tcase_add_test(tc, percent);
  suite_add_tcase(s, tc);

  suite_add_tcase(s, tc);
  return s;
}
