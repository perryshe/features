#include "s21_string.h"
/*Находит первое вхождение всей строки needle (не включая завершающий нулевой
символ), которая появляется в строке haystack.*/

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;  // Инициализируем переменную result значением NULL
  int flag = 0;  // Инициализируем флаг flag значением 0

  if (*needle == '\0')
    result = (char *)haystack;  // Если строка needle пуста,  возвращаем
                                // указатель на начало строки haystack
  // Цикл проходит по строке haystack до тех пор, пока не достигнет конца строки
  // ('\0')
  while (!flag && *haystack != '\0') {
    if (*haystack == needle[0]) {  // Проверяем, является ли текущий символ
                                   // haystack равным первому символу needle
      flag = 1;  // Если символы равны, то flag в 1 и сохраняем указатель на
                 // текущий символ строки haystack в переменную result
      result = (char *)haystack;
      // Внутренний цикл проверяет, является ли подстрока haystack равной строке
      // needle
      for (s21_size_t i = 0; flag && needle[i] != '\0'; i++) {
        if (*haystack ==
            needle[i]) {  // Является ли текущий символ строки haystack равным
                          // соответствующему символу строки needle
          haystack++;  // Если символы равны, то переходим к следующему символу
                       // в строке haystack
        } else {
          flag = 0;  // Если символы не равны, то сбрасываем флаг flag в 0 и
                     // обнуляем переменную result
          result = s21_NULL;
          haystack++;  // Переходим к следующему символу в строке haystack
        }
      }
    }
    haystack++;  // Переходим к следующему символу в строке haystack
  }
  // Возвращаем указатель на найденную подстроку или NULL, если подстрока не
  // найдена
  return result;
}