#include "s21_string.h"

/* Функция заполняет блок памяти заданным значением.
    str  блок заполнен.
    c    Значение, которое должно быть занесено в блок памяти.
    n    Сколько байт заполнять. */
void *s21_memset(void *str, const int c, s21_size_t n) {
  //  Преобразуем void-указатель в unsigned char-указатель, чтобы можно было
  //  работать с отдельными байтами
  unsigned char *byte_ptr = (unsigned char *)str;

  for (size_t i = 0; i < n; i++) { /* Цикл, который будет заполнять байты в
                                      блоке памяти значением c*/
    byte_ptr[i] = (unsigned char)c;
  }

  return str;
}