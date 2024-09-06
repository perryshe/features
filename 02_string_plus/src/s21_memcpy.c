#include "s21_string.h"

/*Копирует n символов из src в dest.*/

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  // Цикл, который будет копировать байты из src в dest
  for (s21_size_t i = 0; i < n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
    // Kопируем i-й байт из src в i-й байт dest
  }
  return dest;
}