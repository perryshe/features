#include "s21_string.h"
/*Находит первый символ в строке str1, который соответствует любому символу,
указанному в str2.*/

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int flag = 0;
  while (*str1 != '\0' && flag == 0) {
    for (s21_size_t i = 0; flag == 0 && str2[i] != '\0'; i++) {
      if (*str1 == str2[i]) {
        result = (char *)str1;
        flag = 1;  // Return immediately when a match is found
      }
    }
    str1++;
  }
  return result;  // Return NULL if no match is found
}
