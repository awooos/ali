#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ali_vprint_arg(char *str, size_t size, const char *format, va_list args);

int vsnprintf(char *str, size_t size, const char *fmt, va_list args)
{
    size_t length = 0;
    int tmp;

    // Leave room for the null byte at the end.
    if (size > 0) {
        size--;
    }

    for (const char *p = fmt; *p; p++) {
        switch (*p) {
        case '%':
            p++; // Skip the % we just matched.
            tmp = ali_vprint_arg(str + length, size - length, p, args);
            if (tmp < 0) {
                return tmp;
            }
            p += (size_t)tmp - 1;
            length += (size_t)tmp;
            break;
        /*case '\\':
            // TODO: Handle escaped text.
            break;*/
        default:
            if (length < size) {
                str[length] = *p;
            }
            length++;
            break;
        }
    }

    // Add trailing null byte, if the buffer is usable.
    if (size > 0) {
        if (length < size) {
            str[length] = '\0';
        } else {
            str[size + 1] = '\0';
        }
    }

    return (int)length;
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
