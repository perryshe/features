#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int result = 0;  // Количество успешно считанных значений
  int return_value = 0;  // Переменная для хранения результата

  if (format == NULL || str == NULL || s21_strlen(str) == 0) {
    return_value = -1;

  } else {
    va_list args;  // va_list - для работы с переменным числом аргументов
    va_start(args, format);
    int len = s21_strlen(format);
    int n = 0;  // Счетчик символов - отслеживает текущую позицию в строке (str)
    for (int i = 0; i < len; i++) {  // Перебор символов строки формата (format)
      if (format[i] == '%') {
        FormatSpec spec = {0, -1, 0, 0};
        i = s21_parse_format_specifier(format, &spec, i);
        n += s21_skip_space(str + n, spec);
        switch (spec.spec) {
          case 'c':
            n += s21_parse_char(args, str + n, spec, &result);
            break;
          case 's':
            n += s21_parse_string(args, str + n, spec, &result);
            break;
          case 'i':
          case 'd':
            n += s21_parse_int_signed(args, str + n, spec, &result);
            break;
          case 'o':
          case 'u':
          case 'x':
          case 'X':
          case 'p':
            n += s21_parse_int_unsigned(args, str + n, spec, &result);
            break;
          case 'e':
          case 'E':
          case 'f':
          case 'g':
          case 'G':
            n += s21_parse_float(args, str + n, spec, &result);
            break;
          case 'n':
            *va_arg(args, int *) = n;
            break;
          default:
            if (str[n] == '%') n++;
            break;
        }
      } else if (s21_strchr(" \n\t\r\x0B\f", format[i]) && format[i]) {
        while (s21_strchr(" \n\t\r\x0B\f", str[n]) && str[n]) n++;
      } else {
        if (format[i] == str[n]) n++;
      }
    }
    va_end(args);
    return_value = result;
  }

  return return_value;
}

int s21_isdigit(char ch) { return (ch >= '0' && ch <= '9'); }

// Разбор спецификаторов формата
int s21_parse_format_specifier(const char *format, FormatSpec *spec, int i) {
  i++;
  if (format[i] == '*') {
    spec->aster = 1;
    i++;
  }
  if (s21_isdigit(format[i])) {
    spec->width = 0;
    while (s21_isdigit(format[i])) {
      spec->width = spec->width * 10 + (format[i] - '0');
      i++;
    }
  }
  if (format[i] == 'l') {
    if (format[i + 1] == 'l') {
      spec->length = 'L';
      i += 2;
    } else {
      spec->length = 'l';
      i++;
    }
  } else if (format[i] == 'L') {
    spec->length = 'L';
    i++;
  } else if (format[i] == 'h') {
    spec->length = 'h';
    i++;
  } else {
    spec->length = '\0';
  }

  if (s21_strchr("cdieEfgGosuxXpn%", format[i])) {
    spec->spec = format[i];
  }
  return i;
}

// Пропуск пробелов
int s21_skip_space(const char *str, FormatSpec spec) {
  int i = 0;
  if (spec.spec != 'c')
    while (s21_strchr(" \n\t\r\x0B\f", str[i]) && str[i]) i++;
  return i;
}

// Разбор символа
int s21_parse_char(va_list args, const char *str, FormatSpec spec,
                   int *result) {
  int i = 0;

  if (str[0] == '\0') {
    i = 0;
  } else {
    int width = (spec.width > 0) ? spec.width : 1;

    if (!spec.aster) {
      char *out = va_arg(args, char *);
      for (i = 0; i < width && str[i]; i++) {
        out[i] = str[i];
      }
      (*result)++;
    } else {
      i = width;
    }
  }

  return i;
}

// Разбор строки
int s21_parse_string(va_list args, const char *str, FormatSpec spec,
                     int *result) {
  int i = 0;
  char *buffer = NULL;
  if (!spec.aster) {
    buffer = va_arg(args, char *);
    if (str[0]) {
      (*result)++;
    }
  }
  while (str[i] && !s21_strchr(" \n\t\r\x0B\f", str[i]) && i != spec.width) {
    if (buffer) {
      buffer[i] = str[i];
    }
    i++;
  }
  if (buffer) {
    buffer[i] = '\0';
  }
  return i;
}

// Разбор знаковых целых чисел
int s21_parse_int_signed(va_list args, const char *str, FormatSpec spec,
                         int *result) {
  int i = 0;
  char *numstr;
  char *buffer = calloc(s21_strlen(str) + 1, sizeof(char));
  if (buffer) {
    int j = 0;
    int base = 10;
    numstr = "0123456789";
    if (str[i] == '+' || str[i] == '-') {
      buffer[j++] = str[i++];
    }
    if (str[i] == '0' && spec.spec == 'i') {
      base = 8;
      numstr = "01234567";
      i++;
      if (str[i] == 'x' || str[i] == 'X') {
        base = 16;
        numstr = "0123456789abcdefxABCDEF";
        i++;
      }
    }
    while (s21_strchr(numstr, str[i]) && str[i] && i != spec.width) {
      buffer[j] = str[i];
      i++;
      j++;
    }

    buffer[j] = '\0';
    if (j == 0) {
      i = 0;
    } else {
      if (!spec.aster) {
        if (spec.length == 'h')
          *va_arg(args, short int *) = s21_char_to_int(buffer, base);
        else if (spec.length == 'l')
          *va_arg(args, long int *) = s21_char_to_int(buffer, base);
        else if (spec.length == 'L')
          *va_arg(args, long long int *) = s21_char_to_int(buffer, base);
        else
          *va_arg(args, int *) = s21_char_to_int(buffer, base);
        if (str[0]) *result = *result + 1;
      }
    }
  }
  free(buffer);
  return i;
}

// Разбор беззнаковых целых чисел
int s21_parse_int_unsigned(va_list args, const char *str, FormatSpec spec,
                           int *result) {
  int i = 0;
  char *numstr;
  char *buffer = calloc(s21_strlen(str) + 1, sizeof(char));
  if (buffer) {
    int j = 0;
    int base;
    if (str[i] == '+' || str[i] == '-') {
      buffer[j++] = str[i++];
    }
    if (spec.spec == 'o') base = 8, numstr = "01234567";
    if (spec.spec == 'u') base = 10, numstr = "0123456789";
    if (spec.spec == 'x' || spec.spec == 'X' || spec.spec == 'p')
      base = 16, numstr = "0123456789abcdefxABCDEF";

    while (s21_strchr(numstr, str[i]) && str[i] && i != spec.width) {
      buffer[j] = str[i];
      i++;
      j++;
    }
    buffer[j] = '\0';

    if (j == 0) {
      i = 0;
    } else {
      if (!spec.aster) {
        if (spec.spec == 'p') {
          unsigned long int *p_void = va_arg(args, void *);
          *p_void = s21_char_to_int(buffer, base);
        } else if (spec.length == 'h')
          *va_arg(args, unsigned short int *) = s21_char_to_int(buffer, base);
        else if (spec.length == 'l')
          *va_arg(args, unsigned long int *) = s21_char_to_int(buffer, base);
        else
          *va_arg(args, unsigned int *) = s21_char_to_int(buffer, base);
        if (str[0]) *result = *result + 1;
      }
    }
  }
  free(buffer);
  return i;
}

// Разбор чисел с плавающей точкой
int s21_parse_float(va_list args, const char *str, FormatSpec spec,
                    int *result) {
  int i = 0;
  int j = 0;
  char *buffer = calloc(s21_strlen(str) + 1, sizeof(char));
  if (buffer) {
    if (str[i] == '+' || str[i] == '-') i++;
    if (s21_strchr("nNiI", str[i])) {
      while (s21_strchr("NAIFnaif", str[i]) && str[i] && i != spec.width) i++;
    } else {
      const char *numstr = "0123456789";
      int point_count = 0;
      while ((s21_strchr(numstr, str[i]) || str[i] == '.') && str[i] &&
             point_count < 2 && i != spec.width) {
        if (str[i] == '.') point_count++;
        i++;
      }
      if (str[i] == 'e' || str[i] == 'E') {
        i++;
        if (str[i] == '+' || str[i] == '-') i++;
        while (s21_strchr(numstr, str[i]) && str[i]) i++;
      }
    }
    for (j = 0; j < i; j++) {
      buffer[j] = str[j];
    }
    buffer[j] = '\0';
    if (j == 0) {
      i = 0;
    } else {
      if (!spec.aster) {
        if (spec.length == 'l')
          *va_arg(args, double *) = s21_char_to_float(buffer);
        else if (spec.length == 'L')
          *va_arg(args, long double *) = s21_char_to_float(buffer);
        else
          *va_arg(args, float *) = s21_char_to_float(buffer);

        if (str[0]) (*result)++;
      }
    }
  }
  free(buffer);
  return i;
}

// Преобразование строки в целое число
long int s21_char_to_int(const char *buffer, int base) {
  long int result = 0;
  int sing = 1;
  int len = s21_strlen(buffer);
  for (int i = 0; i < len; i++) {
    long int digit = 0;
    if (buffer[i] == '-') {
      i++;
      sing = -1;
    } else if (buffer[i] == '+')
      i++;
    if (buffer[i] >= '0' && buffer[i] <= '9')
      digit = buffer[i] - '0';
    else if (buffer[i] >= 'a' && buffer[i] <= 'f')
      digit = buffer[i] - 'a' + 10;
    else if (buffer[i] >= 'A' && buffer[i] <= 'F')
      digit = buffer[i] - 'A' + 10;
    result = result * base + digit;
  }
  return result * sing;
}

// Преобразование строки в дробное число
long double s21_char_to_float(const char *buffer) {
  long double result = 0;
  int i = 0, sign = 1, exp_sign = 1, exp = 0, point = 0;
  int len = s21_strlen(buffer);
  if (buffer[0] == '-') {
    sign = -1;
    i++;
  } else if (buffer[0] == '+') {
    i++;
  }
  if (s21_strchr("nNiI", buffer[i])) {
    if (s21_strchr("nN", buffer[i])) {
      if (s21_strchr("aA", buffer[i + 1]) && s21_strchr("nN", buffer[i + 2])) {
        return sign * NAN;
      }
    } else if (s21_strchr("iI", buffer[i])) {
      if (s21_strchr("nN", buffer[i + 1]) && s21_strchr("fF", buffer[i + 2])) {
        return sign * INFINITY;
      }
    }
  }
  while (i < len && buffer[i] != '\0') {
    if (s21_isdigit(buffer[i])) {
      if (point) {
        result += (buffer[i] - '0') * pow(10, -point);
        point++;
      } else {
        result = result * 10 + (buffer[i] - '0');
      }
    } else if (buffer[i] == '.') {
      point = 1;
    } else {
      break;
    }
    i++;
  }
  if (buffer[i] == 'e' || buffer[i] == 'E') {
    i++;
    if (buffer[i] == '-') {
      exp_sign = -1;
      i++;
    } else if (buffer[i] == '+') {
      i++;
    }
    if (s21_isdigit(buffer[i])) {
      exp = s21_char_to_int(buffer + i, 10);
    }
  }
  return sign * result * pow(10, exp_sign * exp);
}
