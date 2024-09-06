#include "s21_string.h"
/*Сравнивает первые n байтов str1 и str2.*/

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  unsigned char *str_1 =
      (unsigned char *)s1; /*Преобразуем void в unsigned char-указатели, */
  unsigned char *str_2 =
      (unsigned char *)s2; /*чтобы можно было работать с отдельными байтами*/
  s21_size_t i = 0, flag = 0; /*Задаём переменные: i - индекс текущего байта и
                                 flag - флаг, для разници строк*/
  while (i < n) {
    if (str_1[i] != str_2[i]) {
      flag = (str_1[i] - str_2[i]);
      i += n; /* Пропустим оставшиеся байты и выходим из цикла*/
    }
    i++;
  }
  return flag;
}
