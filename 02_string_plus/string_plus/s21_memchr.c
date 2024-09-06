#include "s21_string.h"
/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
 байтах строки, на которую указывает аргумент str.*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *byte = (const unsigned char *)
      str; /*Преобразуем указатель на void в указатель на unsigned char,
               чтобы работать с байтами, а не с символами*/

  unsigned char ch = (unsigned char)c;  // приводим символ к типу unsigned char
  int flag = 0;
  void *res = s21_NULL;  // Указатель на результат поиска , на старте = NULL

  for (s21_size_t i = 0; i < n && !flag; i++, byte++) {
    if (*byte == ch) {
      res = (void *)
          byte;  // если совпадение найдено, сохраняем на него туказатель
      flag = 1;  // и прерываем цикл
    }
  }
  return res;  // Возвращаем найденный указатель или NULL если не нашли
}