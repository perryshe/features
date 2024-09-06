#include "s21_tests.h"

START_TEST(sscanf_c_1) {
  char *format = "%c";
  char *str = "He\tllo, world!";
  char out = 0, s21_out = 0;
  int res = sscanf(str, format, &out);
  int s21_res = s21_sscanf(str, format, &s21_out);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out, out);
}
END_TEST

START_TEST(sscanf_c_2) {
  char *format = "%c";
  char *str = "";
  char out = 0, s21_out = 0;
  int res = sscanf(str, format, &out);
  int s21_res = s21_sscanf(str, format, &s21_out);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_c_3) {
  char *format = "%10c %c %c";
  char *str = "Hello world!";
  char out_1[BUFF_SIZE] = {0}, s21_out_1[BUFF_SIZE] = {0};
  char out_2 = 0, out_3 = 0, s21_out_2 = 0, s21_out_3 = 0;
  int res = sscanf(str, format, out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_mem_eq(s21_out_1, out_1, 10);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_4) {
  char *format = "%c %c %c";
  char *str = "He\tllo, world!";
  char out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
       s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_5) {
  char *format = "%c %*c %c %c";
  char *str = "He\tllo, world!";
  char out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
       s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_c_6) {
  char *format = "%lc%lc%Lc";
  char *str = "English Юникод держи!";
  wchar_t out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
          s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_1) {
  char *format = "%d %d %d";
  char *str = "1 2  3 4";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_2) {
  char *format = "%1d %2d %3d";
  char *str = "0001 2 3 4";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_4) {
  char *format = "%d 3%d 5%*d %d";
  char *str = "12 34 56 7";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_5) {
  char *format = "%d/%d/%d";
  char *str = "24/07/2024";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_6) {
  char *format = "%d / %d / %d";
  char *str = "24/07/2024";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_7) {
  char *format = "%d%d%d";
  char *str = "1\t2\n3 4";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_8) {
  char *format = "%d %d %d";
  char *str = "+1 +02 -3 4";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_9) {
  char *format = "%ld %d %*ld %lld";
  char *str = "1 -2 -3 +4";
  long int out_1 = 0, s21_out_1 = 0;
  long long int out_3 = 0, s21_out_3 = 0;
  int out_2 = 0, s21_out_2 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_d_10) {
  char *format = "%hd %d %*hd %hd";
  char *str = "1 -2 -3 +4";
  short int out_1 = 0, out_3 = 0, s21_out_1 = 0, s21_out_3 = 0;
  int out_2 = 0, s21_out_2 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_s_1) {
  char *format = "%s";
  char *str = "Hello, world!";
  char out_1[BUFF_SIZE] = {0};
  char s21_out_1[BUFF_SIZE] = {0};
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
}
END_TEST

START_TEST(sscanf_s_2) {
  char *format = "%s";
  char *str = "";
  char out_1[BUFF_SIZE] = {0};
  char s21_out_1[BUFF_SIZE] = {0};
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_res, -1);
}
END_TEST

START_TEST(sscanf_s_3) {
  char *format = "%s %s %s";
  char *str = "Hello,\tworld!\nHi, test!";
  char out_1[BUFF_SIZE] = {0}, out_2[BUFF_SIZE] = {0}, out_3[BUFF_SIZE] = {0};
  char s21_out_1[BUFF_SIZE] = {0}, s21_out_2[BUFF_SIZE] = {0},
       s21_out_3[BUFF_SIZE] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_str_eq(s21_out_2, out_2);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_s_4) {
  char *format = "%2s %3s %4s";
  char *str = "Hello, world! Hi, test!";
  char out_1[BUFF_SIZE] = {0}, out_2[BUFF_SIZE] = {0}, out_3[BUFF_SIZE] = {0};
  char s21_out_1[BUFF_SIZE] = {0}, s21_out_2[BUFF_SIZE] = {0},
       s21_out_3[BUFF_SIZE] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_str_eq(s21_out_2, out_2);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_s_5) {
  char *format = "%s %*s %s %s";
  char *str = "Hello, world! Hi, test!";
  char out_1[BUFF_SIZE] = {0}, out_2[BUFF_SIZE] = {0}, out_3[BUFF_SIZE] = {0};
  char s21_out_1[BUFF_SIZE] = {0}, s21_out_2[BUFF_SIZE] = {0},
       s21_out_3[BUFF_SIZE] = {0};
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_str_eq(s21_out_1, out_1);
  ck_assert_str_eq(s21_out_2, out_2);
  ck_assert_str_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_1) {
  char *format = "%f %f %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_2) {
  char *format = "%f %*f %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  float out_1, out_2;
  float s21_out_1, s21_out_2;
  int res = sscanf(str, format, &out_1, &out_2);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
}
END_TEST

START_TEST(sscanf_f_3) {
  char *format = "%f %7f %*ld %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_4) {
  char *format = "%f %*7f %ld %f";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  long int out_2, s21_out_2;
  float out_1, out_3;
  float s21_out_1, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_5) {
  char *format = "%f %f %*f %f";
  char *str = "NAN -NaN +NAn -nan";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_nan(out_1);
  ck_assert_float_nan(out_2);
  ck_assert_float_nan(out_3);
}
END_TEST

START_TEST(sscanf_f_6) {
  char *format = "%f %f %*f %f";
  char *str = "INF -Inf +INf -inf";
  float out_1, out_2, out_3;
  float s21_out_1, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_f_7) {
  char *format = "%lf %llf %Lf";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  double out_1;
  double s21_out_1;
  long double out_2, out_3;
  long double s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_double_eq_tol(s21_out_1, out_1, 1e-7);
  ck_assert_ldouble_eq_tol(s21_out_2, out_2, 1e-7);
  ck_assert_ldouble_eq_tol(s21_out_3, out_3, 1e-7);
}
END_TEST

START_TEST(sscanf_f_8) {
  char *format = "%*llf %*Lf %Lf";
  char *str =
      "1.41421356237309504880 2.71828182845904523536 3.14159265358979323846";
  long double out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_double_eq(s21_out_1, out_1);
}
END_TEST

START_TEST(sscanf_f_9) {
  char *format = "%f";
  char *str = "text without digit";
  float out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_i_1) {
  char *format = "%i%i%i";
  char *str = "010 10 0x10";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_i_2) {
  char *format = "%*i%i%*i%i%*i%i";
  char *str = "010 020 10 20 0x10 0x20";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_i_3) {
  char *format = "%i%i%i";
  char *str = "+010 -10 +0x10";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_i_4) {
  char *format = "%*3i %i %10i %2i";
  char *str = "010 10 0x10";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_i_5) {
  char *format = "%hi%2hi%*hi%hi";
  char *str = "010 10 0x10 0x8000";
  short int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
            s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_i_6) {
  char *format = "%li %2li %*li %li";
  char *str = "010 10 0x10 0x8000000";
  long int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
           s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_i_7) {
  char *format = "%i";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_o_1) {
  char *format = "%o%o%o";
  char *str = "+011 -0010 109";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_o_2) {
  char *format = "%3o %*d %*3o %o %3o";
  char *str = "+011 -0010 109";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_o_3) {
  char *format = "%ho%23lo%*ho%lo";
  char *str = "+010 -1000000000000000000001 -0010 +1000000000000000000000";
  short int out_1 = 0, s21_out_1 = 0;
  long int out_2, out_3, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_o_4) {
  char *format = "%o";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_x_1) {
  char *format = "%x%X%X";
  char *str = "+011 -0010 10G";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_x_2) {
  char *format = "%3x%*d%*3X%x%3X";
  char *str = "+011 -0010 10G";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_x_3) {
  char *format = "%hx%23lX%*hx%lX";
  char *str = "+010 -8000000000000001 -0010 +8000000000000000";
  short int out_1 = 0, s21_out_1 = 0;
  long int out_2, out_3, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_x_4) {
  char *format = "%x";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_u_1) {
  char *format = "%u%u%u";
  char *str = "+010 -001 4294967296";
  unsigned int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
               s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_u_2) {
  char *format = "%3u%*d%*3u%u%3u";
  char *str = "+010 -001 42A4967296";
  unsigned int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
               s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_u_3) {
  char *format = "%hu%23lu%*hu%lu";
  char *str = "+010 -1 -0010 4294967296";
  short unsigned int out_1 = 0, s21_out_1 = 0;
  long unsigned int out_2, out_3, s21_out_2, s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_u_4) {
  char *format = "%u";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_p_1) {
  char *format = "%p%p%p";
  char *str = "0x7ffddddddddd 0x7ffdcccccccc 0x7ffdbbbbbbbb";
  void *out_1, *out_2, *out_3, *s21_out_1, *s21_out_2, *s21_out_3;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_ptr_eq(s21_out_1, out_1);
  ck_assert_ptr_eq(s21_out_2, out_2);
  ck_assert_ptr_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_p_2) {
  char *format = "%p";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_n_1) {
  char *format = "%i %*s %*s %40i %n";
  char *str = "-012 Hello, world! +0x34";
  int out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
      s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_1) {
  char *format = "%e%E%E";
  char *str = "+011 -0010 0010G";
  float out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
        s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_2) {
  char *format = "%e%E%E";
  char *str = "1e2 1E0 0e2";
  float out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
        s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_3) {
  char *format = "%e%*c%E%E";
  char *str = "1e+2e .5E-1 0.4e.2";
  float out_1 = 0, out_2 = 0, out_3 = 0, s21_out_1 = 0, s21_out_2 = 0,
        s21_out_3 = 0;
  int res = sscanf(str, format, &out_1, &out_2, &out_3);
  int s21_res = s21_sscanf(str, format, &s21_out_1, &s21_out_2, &s21_out_3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
  ck_assert_float_eq(s21_out_2, out_2);
  ck_assert_float_eq(s21_out_3, out_3);
}
END_TEST

START_TEST(sscanf_e_4) {
  char *format = "%e";
  char *str = "text without digit";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sscanf_pct_1) {
  char *format = "%*s %*s %d %% %*s";
  char *str = "our targer 100% result";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_float_eq(s21_out_1, out_1);
}
END_TEST

START_TEST(sscanf_pct_2) {
  char *format = "%%";
  char *str = "text without percents";
  int out_1 = 0, s21_out_1 = 0;
  int res = sscanf(str, format, &out_1);
  int s21_res = s21_sscanf(str, format, &s21_out_1);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *s21_q4sscanf_test(void) {
  Suite *s = suite_create("\033[45ms21_q4sscanf_test\033[0m");
  TCase *tc = tcase_create("s21_q4sscanf_test");

  tcase_add_test(tc, sscanf_c_1);
  tcase_add_test(tc, sscanf_c_2);
  tcase_add_test(tc, sscanf_c_3);
  tcase_add_test(tc, sscanf_c_4);
  tcase_add_test(tc, sscanf_c_5);
  tcase_add_test(tc, sscanf_c_6);

  tcase_add_test(tc, sscanf_d_1);
  tcase_add_test(tc, sscanf_d_2);
  tcase_add_test(tc, sscanf_d_4);
  tcase_add_test(tc, sscanf_d_5);
  tcase_add_test(tc, sscanf_d_6);
  tcase_add_test(tc, sscanf_d_7);
  tcase_add_test(tc, sscanf_d_8);
  tcase_add_test(tc, sscanf_d_9);
  tcase_add_test(tc, sscanf_d_10);

  tcase_add_test(tc, sscanf_s_1);
  tcase_add_test(tc, sscanf_s_2);
  tcase_add_test(tc, sscanf_s_3);
  tcase_add_test(tc, sscanf_s_4);
  tcase_add_test(tc, sscanf_s_5);

  tcase_add_test(tc, sscanf_f_1);
  tcase_add_test(tc, sscanf_f_2);
  tcase_add_test(tc, sscanf_f_3);
  tcase_add_test(tc, sscanf_f_4);
  tcase_add_test(tc, sscanf_f_5);
  tcase_add_test(tc, sscanf_f_6);
  tcase_add_test(tc, sscanf_f_7);
  tcase_add_test(tc, sscanf_f_8);
  tcase_add_test(tc, sscanf_f_9);

  tcase_add_test(tc, sscanf_i_1);
  tcase_add_test(tc, sscanf_i_2);
  tcase_add_test(tc, sscanf_i_3);
  tcase_add_test(tc, sscanf_i_4);
  tcase_add_test(tc, sscanf_i_5);
  tcase_add_test(tc, sscanf_i_6);
  tcase_add_test(tc, sscanf_i_7);

  tcase_add_test(tc, sscanf_o_1);
  tcase_add_test(tc, sscanf_o_2);
  tcase_add_test(tc, sscanf_o_3);
  tcase_add_test(tc, sscanf_o_4);

  tcase_add_test(tc, sscanf_x_1);
  tcase_add_test(tc, sscanf_x_2);
  tcase_add_test(tc, sscanf_x_3);
  tcase_add_test(tc, sscanf_x_4);

  tcase_add_test(tc, sscanf_u_1);
  tcase_add_test(tc, sscanf_u_2);
  tcase_add_test(tc, sscanf_u_3);
  tcase_add_test(tc, sscanf_u_4);

  tcase_add_test(tc, sscanf_p_1);
  tcase_add_test(tc, sscanf_p_2);

  tcase_add_test(tc, sscanf_n_1);

  tcase_add_test(tc, sscanf_e_1);
  tcase_add_test(tc, sscanf_e_2);
  tcase_add_test(tc, sscanf_e_3);
  tcase_add_test(tc, sscanf_e_4);

  tcase_add_test(tc, sscanf_pct_1);
  tcase_add_test(tc, sscanf_pct_2);

  suite_add_tcase(s, tc);
  return s;
}
