#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  format_parsed current_spec;
  char *p = str;
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      s21_init_current_spec(&current_spec);
      s21_parse_flags(&format, &current_spec);
      s21_parse_width(&format, &current_spec, args);
      s21_parse_precision(&format, &current_spec, args);
      s21_parse_length_mod(&format, &current_spec);
      s21_print_spec(&p, &current_spec, &format, args);
    } else {
      *p++ = *format;
    }
    format++;
  }
  *p = '\0';
  va_end(args);
  return p - str;
}
void s21_parse_flags(const char **format, format_parsed *current_spec) {
  int stop = 0;
  while (!stop && **format != '\0') {
    switch (**format) {
      case '-':
        current_spec->minus_flag = 1;
        break;
      case '+':
        current_spec->plus_flag = 1;
        break;
      case ' ':
        current_spec->space_flag = 1;
        break;
      case '#':
        current_spec->sharp_flag = 1;
        break;
      case '0':
        current_spec->zero_flag = 1;
        break;
      default:
        stop = 1;
        break;
    }
    if (!stop) {
      (*format)++;
    }
  }
  if (current_spec->minus_flag) current_spec->zero_flag = 0;
  if (current_spec->plus_flag) current_spec->space_flag = 0;
}
void s21_parse_width(const char **format, format_parsed *current_spec,
                     va_list args) {
  if (**format == '*') {
    (*format)++;
    current_spec->width = va_arg(args, long int);
    if (current_spec->width < 0) {
      current_spec->minus_flag = 1;
      current_spec->width = 10;
    }
  } else {
    while (**format >= '0' && **format <= '9') {
      current_spec->width = current_spec->width * 10 + (**format - '0');
      (*format)++;
    }
  }
}
void s21_init_current_spec(format_parsed *current_spec) {
  current_spec->spec = 0;
  current_spec->minus_flag = 0;
  current_spec->plus_flag = 0;
  current_spec->space_flag = 0;
  current_spec->sharp_flag = 0;
  current_spec->zero_flag = 0;
  current_spec->width = 0;
  current_spec->precision = -1;
  current_spec->length_mod = 0;
}
void s21_parse_precision(const char **format, format_parsed *current_spec,
                         va_list args) {
  if (**format == '.') {
    (*format)++;
    if (**format == '*') {
      (*format)++;
      current_spec->precision = va_arg(args, unsigned int);
    } else {
      current_spec->precision = 0;
      while (**format >= '0' && **format <= '9') {
        current_spec->precision =
            current_spec->precision * 10 + (**format - '0');
        (*format)++;
      }
    }
  }
}
void s21_parse_length_mod(const char **format, format_parsed *current_spec) {
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    current_spec->length_mod = **format;
    (*format)++;
  }
}
void s21_print_spec(char **p, format_parsed *current_spec, const char **format,
                    va_list args) {
  current_spec->spec = **format;
  switch (current_spec->spec) {
    case 'c':
      s21_print_c(args, p, *current_spec);
      break;
    case 'd':
    case 'i':
      s21_print_d(args, p, *current_spec);
      break;
    case 'f':
    case 'g':
    case 'G':
    case 'e':
    case 'E':
      s21_print_f(args, p, *current_spec);
      break;
    case 's':
      s21_print_s(args, p, *current_spec);
      break;
    case 'u':
    case 'x':
    case 'X':
    case 'o':
    case 'p':
      s21_print_uoxXp(args, p, *current_spec);
      break;
    case '%':
      *(*p)++ = '%';
      break;
  }
}
void s21_print_c(va_list args, char **p, format_parsed current_spec) {
  char c = (char)va_arg(args, int);
  if (current_spec.minus_flag) {
    *(*p)++ = c;
    s21_print_filler(current_spec.width - 1, p, ' ');
  } else {
    s21_print_filler(current_spec.width - 1, p, ' ');
    *(*p)++ = c;
  }
}
void s21_print_filler(int number, char **p, char filler) {
  for (int i = 0; i < number; i++) {
    **p = filler;
    (*p)++;
  }
}
void s21_print_s(va_list args, char **p, format_parsed current_spec) {
  char *s = (char *)va_arg(args, char *);
  if (s != NULL) {
    s21_size_t prescision;
    prescision = current_spec.precision < 0
                     ? s21_strlen(s)
                     : (s21_size_t)current_spec.precision;
    int length;
    length = prescision < s21_strlen(s) ? prescision : s21_strlen(s);
    if (current_spec.minus_flag) {
      s21_strncpy(*p, s, length);
      (*p) += length;
      s21_print_filler(current_spec.width - length, p, ' ');
    } else {
      s21_print_filler(current_spec.width - length, p, ' ');
      s21_strncpy(*p, s, length);
      (*p) += length;
    }
  }
}
unsigned long int s21_get_unsigned_number(va_list args, int length, char spec) {
  unsigned long int number;
  if (length == 'l' || spec == 'p') {
    number = va_arg(args, unsigned long int);
  } else if (length == 'h') {
    number = (unsigned short int)va_arg(args, unsigned int);
  } else {
    number = va_arg(args, unsigned int);
  }
  return number;
}
long int s21_get_d(va_list args, int length) {
  long int number;
  if (length == 'l') {
    number = va_arg(args, long int);
  } else if (length == 'h') {
    number = (short int)va_arg(args, int);
  } else {
    number = va_arg(args, int);
  }
  return number;
}
void s21_print_uoxXp(va_list args, char **p, format_parsed current_spec) {
  unsigned long int number =
      s21_get_unsigned_number(args, current_spec.length_mod, current_spec.spec);
  char buff[32] = {'\0'};
  char *q = buff + sizeof(buff) - 1;
  *q = '\0';
  q = s21_upxXtostr(q, current_spec, number);
  int length = s21_strlen(q);
  if (length == 1 && current_spec.precision == 0 && *q == '0' &&
      !(current_spec.sharp_flag && current_spec.spec == 'o')) {
    length = 0;
    *q = '\0';
  }
  int num_zeros =
      current_spec.precision > length ? current_spec.precision - length : 0;
  int num_fillers = current_spec.width > length + num_zeros
                        ? current_spec.width - (length + num_zeros)
                        : 0;
  if ((number != 0 && current_spec.spec != 'u' && current_spec.spec != 'o' &&
       current_spec.sharp_flag) ||
      current_spec.spec == 'p')
    num_fillers -= 2;
  char filler;
  if (current_spec.zero_flag && current_spec.precision != 0)
    filler = '0';
  else
    filler = ' ';
  if (current_spec.minus_flag) {
    s21_add_opxX(p, current_spec, number);
    s21_print_filler(num_zeros, p, '0');
    while (*q) {
      *(*p)++ = *q++;
    }
    s21_print_filler(num_fillers, p, ' ');
  } else {
    if (filler == ' ') s21_print_filler(num_fillers, p, filler);
    s21_add_opxX(p, current_spec, number);
    if (filler == '0') s21_print_filler(num_fillers, p, filler);
    s21_print_filler(num_zeros, p, '0');
    while (*q) {
      *(*p)++ = *q++;
    }
  }
}
char *s21_unzised_number_to_string(char *q, unsigned long int num, int base,
                                   char start_letter) {
  do {
    unsigned long int digit = num % base;
    *--q = digit < 10 ? '0' + digit : start_letter + digit - 10;
    num /= base;
  } while (num != 0);

  return q;
}
void s21_print_d(va_list args, char **p, format_parsed current_spec) {
  long int number = s21_get_d(args, current_spec.length_mod);
  int negative = 0;
  char buff[32] = {'\0'};
  char *q = buff + sizeof(buff) - 1;
  *q = '\0';
  if (number < 0) {
    negative = 1;
    number *= -1;
  }
  q = s21_unzised_number_to_string(q, (unsigned long)number, 10, '0');
  int length = s21_strlen(q);
  if (length == 1 && current_spec.precision == 0 && *q == '0') {
    length = 0;
    *q = '\0';
  }
  int num_zeros =
      current_spec.precision > length ? current_spec.precision - length : 0;
  int num_fillers = current_spec.width > length + num_zeros
                        ? current_spec.width - (length + num_zeros)
                        : 0;
  if (!current_spec.minus_flag &&
      (negative || (number != 0 && current_spec.plus_flag)))
    num_fillers--;
  char filler;
  if (current_spec.zero_flag && current_spec.precision != 0)
    filler = '0';
  else
    filler = ' ';
  if (current_spec.minus_flag) {
    s21_add_sign(p, negative, current_spec.plus_flag, current_spec.space_flag);
    s21_print_filler(num_zeros, p, '0');
    while (*q) {
      *(*p)++ = *q++;
    }
    s21_print_filler(num_fillers, p, ' ');
  } else {
    if (filler == ' ') s21_print_filler(num_fillers, p, filler);
    s21_add_sign(p, negative, current_spec.plus_flag, current_spec.space_flag);
    if (filler == '0') s21_print_filler(num_fillers, p, filler);
    s21_print_filler(num_zeros, p, '0');
    while (*q) {
      *(*p)++ = *q++;
    }
  }
}
void s21_print_f(va_list args, char **p, format_parsed current_spec) {
  if (current_spec.precision == -1) current_spec.precision = 6;
  long double number = s21_get_f(args, current_spec.length_mod);
  long double whole, fractional;
  char filler;
  char str_whole[4096], str_e[30], str_fract[4096];
  char *p_str_whole = str_whole + sizeof(str_whole) - 1;
  *p_str_whole = '\0';
  char *p_str_e = str_e + sizeof(str_e) - 1;
  *p_str_e = '\0';
  int count_e = 0, negative = 0, nozeroes = 0;
  if (number < 0) {
    negative = 1;
    number *= -1;
  }
  if (current_spec.spec == 'g' || current_spec.spec == 'G') {
    s21_gcheck(&current_spec, number);
    if (!current_spec.sharp_flag) nozeroes = 1;
  }
  if (current_spec.spec == 'E' || current_spec.spec == 'e') {
    number = s21_ftoe(number, &count_e);
    p_str_e = s21_epart_to_str(count_e, p_str_e, current_spec.spec);
  }
  number += 0.5 * pow(10, -current_spec.precision);
  fractional = modfl(number, &whole);
  s21_fract_to_str(str_fract, current_spec.precision, fractional, nozeroes);
  if ((current_spec.precision != 0 || current_spec.sharp_flag != 0) &&
      !(nozeroes && s21_strlen(str_fract) == 0))
    *--p_str_whole = '.';
  p_str_whole = s21_whole_to_str(p_str_whole, whole);
  int length =
      s21_strlen(str_fract) + s21_strlen(p_str_whole) + s21_strlen(p_str_e);
  if (negative ||
      ((!negative && current_spec.plus_flag) || current_spec.space_flag))
    length++;
  int num_fillers =
      current_spec.width > length ? current_spec.width - length : 0;
  filler = current_spec.zero_flag ? '0' : ' ';
  if (current_spec.minus_flag) {
    s21_add_sign(p, negative, current_spec.plus_flag, current_spec.space_flag);
    s21_print_whole_with_fract(p, p_str_whole, str_fract, p_str_e);
    s21_print_filler(num_fillers, p, filler);
  } else {
    if (filler == ' ') s21_print_filler(num_fillers, p, filler);
    s21_add_sign(p, negative, current_spec.plus_flag, current_spec.space_flag);
    if (filler == '0') s21_print_filler(num_fillers, p, filler);
    s21_print_whole_with_fract(p, p_str_whole, str_fract, p_str_e);
  }
}
long double s21_get_f(va_list args, int length) {
  long double num = 0;
  if (length == 'L') {
    num = va_arg(args, long double);
  } else {
    num = va_arg(args, double);
  }
  return num;
}
void s21_add_sign(char **p, int minus, int plus, int space) {
  if (minus)
    *(*p)++ = '-';
  else if (plus)
    *(*p)++ = '+';
  else if (space)
    *(*p)++ = ' ';
}
void s21_fract_to_str(char *str_fract, int precision, long double fractional,
                      int nozeroes) {
  int i = 0;
  while (precision-- > 0) {
    fractional *= 10;
    int digit = (int)fractional;
    str_fract[i] = digit + '0';
    fractional -= digit;
    i++;
  }
  str_fract[i--] = '\0';
  if (nozeroes) {
    while (i >= 0 && str_fract[i] == '0') {
      str_fract[i--] = '\0';
    }
  }
}
char *s21_whole_to_str(char *p_str_whole, long double whole) {
  if (whole >= 1) {
    while (whole >= 1.0) {
      long long digit = (long long)fmodl(whole, 10.0);
      *--p_str_whole = digit + '0';
      whole = whole / 10.0;
    }
  } else
    *--p_str_whole = '0';
  return p_str_whole;
}
void s21_print_whole_with_fract(char **p, char *p_str_whole, char *str_fract,
                                char *p_str_e) {
  while (*p_str_whole != '\0') {
    *(*p)++ = *p_str_whole++;
  }
  for (size_t i = 0; i < s21_strlen(str_fract); i++) {
    *(*p)++ = str_fract[i]++;
  }
  while (*p_str_e != '\0') {
    *(*p)++ = *p_str_e++;
  }
}
int s21_abs(int n) { return n > 0 ? n : n * -1; }
char *s21_epart_to_str(int count_e, char *p_str_e, char spec) {
  if (s21_abs(count_e) >= 10)
    p_str_e = s21_unzised_number_to_string(p_str_e, s21_abs(count_e), 10, '0');
  else {
    *--p_str_e = '0' + s21_abs(count_e);
    *--p_str_e = '0';
  }
  *--p_str_e = count_e < 0 ? '-' : '+';
  *--p_str_e = spec;
  return p_str_e;
}
long double s21_ftoe(long double number, int *count_e) {
  if (number != 0) {
    while (number >= 10) {
      number /= 10.0;
      (*count_e)++;
    }
    while (number < 1) {
      number *= 10;
      (*count_e)--;
    }
  }
  return number;
}

void s21_gcheck(format_parsed *current_spec, long double number) {
  int x = 0;
  int prec;
  if (current_spec->precision == 0)
    prec = 1;
  else
    prec = current_spec->precision;
  if (number == 0 || (number >= 0.0001 && number < pow(10, prec))) {
    s21_ftoe(number, &x);
    current_spec->spec = 'f';
    current_spec->precision = prec - 1 - x;
  } else {
    current_spec->precision = prec - 1;
    current_spec->spec = current_spec->spec == 'G' ? 'E' : 'e';
  }
}

void s21_add_opxX(char **p, format_parsed current_spec,
                  unsigned long int number) {
  if (number != 0 && current_spec.spec != 'o' &&
      (current_spec.sharp_flag || current_spec.spec == 'p')) {
    *(*p)++ = '0';
    if (current_spec.spec == 'X')
      *(*p)++ = 'X';
    else if (current_spec.spec == 'x' || current_spec.spec == 'p')
      *(*p)++ = 'x';
  }
}
char *s21_upxXtostr(char *q, format_parsed current_spec,
                    unsigned long int number) {
  if (current_spec.spec == 'u')
    q = s21_unzised_number_to_string(q, number, 10, '0');
  else if (current_spec.spec == 'x' || current_spec.spec == 'p')
    q = s21_unzised_number_to_string(q, number, 16, 'a');
  else if (current_spec.spec == 'X')
    q = s21_unzised_number_to_string(q, number, 16, 'A');
  else if (current_spec.spec == 'o') {
    q = s21_unzised_number_to_string(q, number, 8, '0');
    if (number != 0 && (current_spec.sharp_flag)) *--q = '0';
  }
  return q;
}