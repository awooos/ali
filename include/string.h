#ifndef STRING_H
#define STRING_H

#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n);

extern void *memmove(void *dest, const void *src, size_t n);
extern void *memset(void *s, int c, size_t n);

extern char *strcpy(char *dest, const char *src);
extern char *strncpy(char *dest, const char *src, size_t n);

// extern char *strcat(char *dest, const char *src);
// extern char *strncat(char *dest, const char *src, size_t n);

extern int memcmp(const void *s1, const void *s2, size_t n);
extern int strcmp(const char *s1, const char *s2);
extern int strncmp(const char *s1, const char *s2, size_t n);

// extern char *strchr(const char *s, int c);
// extern char *strrchr(const char *s, int c);

extern size_t strlen(const char *str);
extern size_t strnlen(const char *str, size_t maxlen);

char *strrev(char *str);

#endif
