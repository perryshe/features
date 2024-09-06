#include "s21_string.h"
// Разбивает строку str на ряд токенов, разделенных delim.

char *s21_strtok(char *str, const char *delim) {
  // Статическая переменная result, которая будет хранить текущий токен
  static char *result = s21_NULL;
  if (str) {  // Если передана строка str, то инициализируем result значением
              // str
    result = str;
    // Удаляем все символы-разделители в начале строки
    while (*result && s21_strchr(delim, *result)) *result++ = '\0';
  }
  if (result !=
      s21_NULL) {  // Если result не равен NULL, то продолжаем разбиение строки
    if (*result != '\0') {  // Если текущий символ строки не равен '\0', то
                            // продолжаем разбиение
      str = result;  // Cохраяем указатель на текущий токен в str
      while (*result && !s21_strchr(delim, *result))
        ++result;  // Ищем конец текущего токена
      while (*result && s21_strchr(delim, *result))
        *result++ =
            '\0';  // Удаляем символы-разделители после конца текущего токена
    } else {
      str = s21_NULL;  // Если текущий символ строки равен '\0', то обнуляем str
    }
  }
  return str;  // Возвращаем указатель на текущий токен или NULL, если токены
               // закончились
}
