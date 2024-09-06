#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *result = s21_NULL;

  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_lenght = s21_strlen(src);
    s21_size_t str_lenght = s21_strlen(str);
    s21_size_t lenght = src_lenght + str_lenght;

    if (start_index <= src_lenght) {
      result = (char *)calloc(lenght + 1, sizeof(char));
      if (result) {
        for (s21_size_t i = 0; i < lenght; i++) {
          if (i < start_index) {
            result[i] = src[i];
          } else if (i < str_lenght + start_index) {
            result[i] = str[i - start_index];
          } else {
            result[i] = src[i - str_lenght];
          }
        }
        result[lenght] = '\0';
      }
    }
  }
  return result;
}

void *s21_to_lower(const char *str) {
  char *newstr = NULL;  // Объявляем переменную для хранения результата

  if (str == NULL) {
    // Обработка случая, когда входная строка равна NULL
    fprintf(stderr, " ");  // Ошибка: входная строка равна NULL\n
  } else {
    size_t str_len =
        s21_strlen(str);  // Используем нашу функцию для расчета длины строки
    newstr = (char *)calloc(str_len + 1, sizeof(char));  // выделение памяти

    if (newstr == NULL) {
      perror("Ошибка при выделении памяти");
    } else {
      // Преобразование каждого символа к нижнему регистру
      for (size_t i = 0; i < str_len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          newstr[i] = str[i] + 32;
        } else {
          newstr[i] = str[i];
        }
      }
    }
  }

  return (void *)newstr;
}

void *s21_to_upper(const char *str) {
  char *newstr = NULL;  // Объявляем переменную для хранения результата

  if (str == NULL) {
    // Обработка случая, когда входная строка равна NULL
    fprintf(stderr, " ");  // Ошибка: входная строка равна NULL\n
  } else {
    size_t str_len =
        s21_strlen(str);  // Используем нашу функцию для расчета длины строки
    newstr = (char *)calloc(str_len + 1, sizeof(char));  // выделение памяти

    if (newstr == NULL) {
      perror("Ошибка при выделении памяти");
    } else {
      // Преобразование каждого символа к верхнему регистру
      for (size_t i = 0; i < str_len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          newstr[i] = str[i] - 32;
        } else {
          newstr[i] = str[i];
        }
      }
    }
  }

  return (void *)newstr;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *newstr = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      newstr = calloc(s21_strlen(src) + 1, 1);
      s21_size_t start = 0, end = s21_strlen(src);
      while (s21_startwith(src, trim_chars, start)) {
        start++;
      }
      if (start != end) {
        while (s21_endwith(src, trim_chars, end)) end--;
      }
      for (int i = 0; start < end; i++) {
        newstr[i] = src[start];
        start++;
      }
    } else {
      s21_size_t src_len = s21_strlen(src);
      newstr = (char *)calloc(src_len + 1, 1);
      for (s21_size_t i = 0; i < src_len; i++) {
        newstr[i] = src[i];
      }
      newstr[src_len] = '\0';
    }
  }
  return newstr;
}

int s21_startwith(const char *src, const char *ttrim, int offset) {
  int result = 0;
  int size = s21_strlen(ttrim);
  for (int i = 0; i < size; i++) {
    if (src[offset] == ttrim[i]) result = 1;
  }
  return result;
}

int s21_endwith(const char *src, const char *ttrim, int offset) {
  int result = 0;
  offset--;
  int size = s21_strlen(ttrim);
  for (int i = 0; i < size; i++) {
    if (src[offset] == ttrim[i]) result = 1;
  }
  return result;
}