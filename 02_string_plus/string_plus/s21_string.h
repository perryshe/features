#ifndef SRC_HEADERS_BONUS_CSH
#define SRC_HEADERS_BONUS_CSH
#define _GNU_SOURCE

#include <errno.h>  // Если устанавливаеь или проверяет ошибки errno, вроде для strerror наверно нужна?
#include <limits.h>
#include <math.h>  // Мат константы на тестах
#include <stdarg.h>
#include <stddef.h>  // Для определение size_t
#include <stdio.h>
#include <stdlib.h>  // Если malloc или free

#define s21_NULL ((void *)0)
typedef long unsigned s21_size_t;

// STRING

// Поиск
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *s, int c);
char *s21_strstr(const char *haystack, const char *needle);

// Разделение
char *s21_strtok(char *str, const char *delim);

// Копирование
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// Вычисления
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);

// Сравнение
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

// Ошибки
char *s21_strerror(int errnum);

// SPRINTF

typedef struct {
  char spec;
  int minus_flag;
  int plus_flag;
  int space_flag;
  int sharp_flag;
  int zero_flag;
  int width;
  int precision;
  char length_mod;
} format_parsed;

int s21_sprintf(char *str, const char *format, ...);
void s21_parse_flags(const char **format, format_parsed *current_spec);
void s21_parse_width(const char **format, format_parsed *current_spec,
                     va_list args);
void s21_init_current_spec(format_parsed *current_spec);
void s21_parse_precision(const char **format, format_parsed *current_spec,
                         va_list args);
void s21_parse_length_mod(const char **format, format_parsed *current_spec);
void s21_print_spec(char **p, format_parsed *current_spec, const char **format,
                    va_list args);
void s21_print_c(va_list args, char **p, format_parsed current_spec);
void s21_print_filler(int number, char **p, char filler);
void s21_print_s(va_list args, char **p, format_parsed current_spec);
void s21_print_s(va_list args, char **p, format_parsed current_spec);
void s21_print_uoxXp(va_list args, char **p, format_parsed current_spec);
char *s21_unzised_number_to_string(char *q, unsigned long int num, int base,
                                   char start_letter);
void s21_print_x(va_list args, char **p, format_parsed current_spec);
long int s21_get_d(va_list args, int length);
void s21_print_d(va_list args, char **p, format_parsed current_spec);
void s21_print_f(va_list args, char **p, format_parsed current_spec);
long double s21_get_f(va_list args, int length);
void s21_add_sign(char **p, int minus, int plus, int space);
void s21_fract_to_str(char *str_fract, int precision, long double fractional,
                      int nozeroes);
char *s21_whole_to_str(char *p_str_whole, long double whole);
void s21_print_whole_with_fract(char **p, char *p_str_whole, char *str_fract,
                                char *p_str_e);
void s21_print_eE(va_list args, char **p, format_parsed current_spec);
int s21_abs(int n);
char *s21_epart_to_str(int count_e, char *p_str_e, char spec);
long double s21_ftoe(long double number, int *count_e);
void s21_gcheck(format_parsed *current_spec, long double number);
void s21_add_opxX(char **p, format_parsed current_spec,
                  unsigned long int number);
char *s21_upxXtostr(char *q, format_parsed current_spec,
                    unsigned long int number);

// SSCANF

typedef struct {
  int aster;
  int width;
  char spec;
  char length;
} FormatSpec;

int s21_sscanf(const char *str, const char *format, ...);
int s21_parse_format_specifier(const char *format, FormatSpec *spec, int i);
int s21_skip_space(const char *str, FormatSpec spec);
int s21_parse_char(va_list args, const char *str, FormatSpec spec, int *result);
int s21_parse_string(va_list args, const char *str, FormatSpec spec,
                     int *result);
int s21_parse_int_signed(va_list args, const char *str, FormatSpec spec,
                         int *result);
int s21_parse_int_unsigned(va_list args, const char *str, FormatSpec spec,
                           int *result);
int s21_parse_float(va_list args, const char *str, FormatSpec spect,
                    int *result);
long int s21_char_to_int(const char *buff, int base);
long double s21_char_to_float(const char *buff);
int s21_isdigit(char ch);

// SHARP

void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
int s21_startwith(const char *src, const char *ttrim, int offset);
int s21_endwith(const char *src, const char *ttrim, int offset);
void *s21_trim(const char *src, const char *trim_chars);

// ---------------ОШИБКИ------------------//
#ifdef __linux__
#define NAME "LINUX"
#define ERRORS_SIZE 134
#define ERRORS                                                                 \
  "Success", "Operation not permitted", "No such file or directory",           \
      "No such process", "Interrupted system call", "Input/output error",      \
      "No such device or address", "Argument list too long",                   \
      "Exec format error", "Bad file descriptor", "No child processes",        \
      "Resource temporarily unavailable", "Cannot allocate memory",            \
      "Permission denied", "Bad address", "Block device required",             \
      "Device or resource busy", "File exists", "Invalid cross-device link",   \
      "No such device", "Not a directory", "Is a directory",                   \
      "Invalid argument", "Too many open files in system",                     \
      "Too many open files", "Inappropriate ioctl for device",                 \
      "Text file busy", "File too large", "No space left on device",           \
      "Illegal seek", "Read-only file system", "Too many links",               \
      "Broken pipe", "Numerical argument out of domain",                       \
      "Numerical result out of range", "Resource deadlock avoided",            \
      "File name too long", "No locks available", "Function not implemented",  \
      "Directory not empty", "Too many levels of symbolic links",              \
      "Unknown error 41", "No message of desired type", "Identifier removed",  \
      "Channel number out of range", "Level 2 not synchronized",               \
      "Level 3 halted", "Level 3 reset", "Link number out of range",           \
      "Protocol driver not attached", "No CSI structure available",            \
      "Level 2 halted", "Invalid exchange", "Invalid request descriptor",      \
      "Exchange full", "No anode", "Invalid request code", "Invalid slot",     \
      "Unknown error 58", "Bad font file format", "Device not a stream",       \
      "No data available", "Timer expired", "Out of streams resources",        \
      "Machine is not on the network", "Package not installed",                \
      "Object is remote", "Link has been severed", "Advertise error",          \
      "Srmount error", "Communication error on send", "Protocol error",        \
      "Multihop attempted", "RFS specific error", "Bad message",               \
      "Value too large for defined data type", "Name not unique on network",   \
      "File descriptor in bad state", "Remote address changed",                \
      "Can not access a needed shared library",                                \
      "Accessing a corrupted shared library",                                  \
      ".lib section in a.out corrupted",                                       \
      "Attempting to link in too many shared libraries",                       \
      "Cannot exec a shared library directly",                                 \
      "Invalid or incomplete multibyte or wide character",                     \
      "Interrupted system call should be restarted", "Streams pipe error",     \
      "Too many users", "Socket operation on non-socket",                      \
      "Destination address required", "Message too long",                      \
      "Protocol wrong type for socket", "Protocol not available",              \
      "Protocol not supported", "Socket type not supported",                   \
      "Operation not supported", "Protocol family not supported",              \
      "Address family not supported by protocol", "Address already in use",    \
      "Cannot assign requested address", "Network is down",                    \
      "Network is unreachable", "Network dropped connection on reset",         \
      "Software caused connection abort", "Connection reset by peer",          \
      "No buffer space available", "Transport endpoint is already connected",  \
      "Transport endpoint is not connected",                                   \
      "Cannot send after transport endpoint shutdown",                         \
      "Too many references: cannot splice", "Connection timed out",            \
      "Connection refused", "Host is down", "No route to host",                \
      "Operation already in progress", "Operation now in progress",            \
      "Stale file handle", "Structure needs cleaning",                         \
      "Not a XENIX named type file", "No XENIX semaphores available",          \
      "Is a named type file", "Remote I/O error", "Disk quota exceeded",       \
      "No medium found", "Wrong medium type", "Operation canceled",            \
      "Required key not available", "Key has expired", "Key has been revoked", \
      "Key was rejected by service", "Owner died", "State not recoverable",    \
      "Operation not possible due to RF-kill",                                 \
      "Memory page has hardware error"

#elif __APPLE__
#define NAME "MACOS"
#define ERRORS_SIZE 107
#define ERRORS                                                                \
  "Undefined error: 0", "Operation not permitted",                            \
      "No such file or directory", "No such process",                         \
      "Interrupted system call", "Input/output error",                        \
      "Device not configured", "Argument list too long", "Exec format error", \
      "Bad file descriptor", "No child processes",                            \
      "Resource deadlock avoided", "Cannot allocate memory",                  \
      "Permission denied", "Bad address", "Block device required",            \
      "Resource busy", "File exists", "Cross-device link",                    \
      "Operation not supported by device", "Not a directory",                 \
      "Is a directory", "Invalid argument", "Too many open files in system",  \
      "Too many open files", "Inappropriate ioctl for device",                \
      "Text file busy", "File too large", "No space left on device",          \
      "Illegal seek", "Read-only file system", "Too many links",              \
      "Broken pipe", "Numerical argument out of domain", "Result too large",  \
      "Resource temporarily unavailable", "Operation now in progress",        \
      "Operation already in progress", "Socket operation on non-socket",      \
      "Destination address required", "Message too long",                     \
      "Protocol wrong type for socket", "Protocol not available",             \
      "Protocol not supported", "Socket type not supported",                  \
      "Operation not supported", "Protocol family not supported",             \
      "Address family not supported by protocol family",                      \
      "Address already in use", "Can't assign requested address",             \
      "Network is down", "Network is unreachable",                            \
      "Network dropped connection on reset",                                  \
      "Software caused connection abort", "Connection reset by peer",         \
      "No buffer space available", "Socket is already connected",             \
      "Socket is not connected", "Can't send after socket shutdown",          \
      "Too many references: can't splice", "Operation timed out",             \
      "Connection refused", "Too many levels of symbolic links",              \
      "File name too long", "Host is down", "No route to host",               \
      "Directory not empty", "Too many processes", "Too many users",          \
      "Disc quota exceeded", "Stale NFS file handle",                         \
      "Too many levels of remote in path", "RPC struct is bad",               \
      "RPC version wrong", "RPC prog. not avail", "Program version wrong",    \
      "Bad procedure for program", "No locks available",                      \
      "Function not implemented", "Inappropriate file type or format",        \
      "Authentication error", "Need authenticator", "Device power is off",    \
      "Device error", "Value too large to be stored in data type",            \
      "Bad executable (or shared library)", "Bad CPU type in executable",     \
      "Shared library version mismatch", "Malformed Mach-o file",             \
      "Operation canceled", "Identifier removed",                             \
      "No message of desired type", "Illegal byte sequence",                  \
      "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",           \
      "No message available on STREAM", "ENOLINK (Reserved)",                 \
      "No STREAM resources", "Not a STREAM", "Protocol error",                \
      "STREAM ioctl timeout", "Operation not supported on socket",            \
      "Policy not found", "State not recoverable", "Previous owner died",     \
      "Interface output queue is full"

#endif

#endif  // SRC_S21_STRING_H_
