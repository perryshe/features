#include "s21_string.h"
/*Выполняет поиск первого вхождения символа c (беззнаковый тип)
     в строке, на которую указывает аргумент str.*/

char *s21_strchr(const char *str, int c) {
  char *result_first =
      s21_NULL;  // Инициализируем переменную result_first значением NULL

  for (; (*str != '\0') && (*str != c);
       str++) { /* Цикл проходит по строке str до тех пор,
                      пока не достигнет конца строки ('\0')
                      или не найдет символ c */
  }

  if (*str == c) {
    result_first = (char *)str;
  }

  return result_first;  // Возвращаем адрес найденного символа или NULL, если
                        // символ не найден
}