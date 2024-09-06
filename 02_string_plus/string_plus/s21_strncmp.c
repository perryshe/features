#include "s21_string.h"

/* Сравнивает не более первых n байтов str1 и str2.
        Возвращает отрицательное значение, если str1 меньше str2,
        положительное значение, если str1 больше str2,
        и 0, если str1 равен str2. */

int s21_strncmp(const char *str_1, const char *str_2, s21_size_t n) {
  int result = 0;
  while (n--) {
    if (*str_1 != *str_2) {
      result = *str_1 - *str_2;
    } else {
      ++str_1;
      ++str_2;
    }
  }
  return result;
}
