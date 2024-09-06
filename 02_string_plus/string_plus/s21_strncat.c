#include "s21_string.h"
/*Добавляет строку, на которую указывает src,
    в конец строки, на которую указывает dest,
    длиной до n символов. */

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = 0; /* Определяем длину строки dest*/
  size_t src_len = 0;      /*Определяем длину строки src*/

  while (dest[dest_len] !=
         '\0') { /*Считаем длину строки dest до конца строки ('\0')*/
    dest_len++;
  }

  while (src_len < n &&
         src[src_len] != '\0') { /* Копируем символы из строки src в строку dest
                                   до тех пор, пока не достигнем конца строки
                                   src или не скопируем n символов */
    dest[dest_len + src_len] = src[src_len];
    src_len++;
  }

  dest[dest_len + src_len] =
      '\0';  // Добавляем символ конца строки ('\0') в конец строки dest

  return dest;  // Возвращаем указатель на строку dest
}
