#include "s21_string.h"
// Копирует до n символов из строки, на которую указывает src, в dest.

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  size_t i;
  // Цикл проходит по строке src до тех пор, пока не достигнет конца строки
  // ('\0')
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];  // Копируем символы из строки src в строку dest
  }
  for (; i < n; i++) {
    dest[i] = '\0';  // Добавляем символ конца строки ('\0') в конец строки dest
  }
  return dest;  // Возвращаем указатель на строку dest
}