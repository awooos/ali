#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vsnprintf(char *str, size_t size, const char *fmt, va_list args)
{
    int idx = 0;
    const char *p;

    // Leave room for the null byte.
    if (size != 0) {
        size--;
    }

    (void)args;

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            if (str) {
                str[idx] = *p;
            }
            idx++;
            continue;
        } else {
            // TODO.
        }
    }

    if (str) {
        str[idx] = '\0';
    }

    return idx;
}

int vsprintf(char *str, const char *fmt, va_list args)
{
    int len;
    len = vsnprintf(NULL, 0, fmt, args);
    len = vsnprintf(str, (size_t)(len + 1), fmt, args);
    return len;
}

int vprintf(const char *fmt, va_list args)
{
    char *str;
    int len;

    len = vsnprintf(NULL, 0, fmt, args);
    len++;

    str = malloc((size_t)len);
    len = vsnprintf(str, (size_t)len, fmt, args);

    for (size_t idx = 0; str[idx]; idx++) {
        putchar(str[idx++]);
    }

    free(str);

    return len;
}
