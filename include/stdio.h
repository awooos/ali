#ifndef ALI__STDIO_H
#define ALI__STDIO_H

#include <stdarg.h>
#include <stddef.h>

//#define stdin   0
//#define stdout  1
//#define stderr  2

#define EOF (-1)

int printf(const char *format, ...);
int putchar(int);
int puts(const char *);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int vprintf(const char *format, va_list args);
int vsnprintf(char *str, size_t size, const char *format, va_list args);
int vsprintf(char *str, const char *format, va_list args);

#endif
