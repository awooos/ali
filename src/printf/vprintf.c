#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ali_vprint_arg(char *str, int offset, size_t size, const char *format, va_list args);

int vsnprintf(char *str, size_t size, const char *fmt, va_list args) {
    int length = 0;
    int tmp;

    for (const char *p = fmt; *p; p++) {
        switch (*p) {
        case '%':
            p++; // Skip the % we just matched.
            tmp = ali_vprint_arg(str, length, size - (size_t)length, p, args);
            if (tmp < 0) {
                return length;
            }
            length += tmp;
            p += tmp - 1;
            break;
        /*case '\\':
            // TODO: Handle escaped text.
            break;*/
        default:
            if (((size_t)length < size) && str) {
                str[length] = *p;
            }
            length++;
            break;
        }
    }

    // Add trailing null byte, if the buffer is usable.
    if (size > 0) {
        if ((size_t)length < size) {
            str[length] = '\0';
        } else {
            str[size + 1] = '\0';
        }
    }

    return length;
}

int vsprintf(char *str, const char *fmt, va_list args) {
    int len;
    len = vsnprintf(NULL, 0, fmt, args);
    len = vsnprintf(str, (size_t)(len + 1), fmt, args);
    return len;
}

int vprintf(const char *fmt, va_list args) {
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
