#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

int ali_sprintn(char *str, size_t size, int min_length,
                uint64_t number, size_t base, int flags, int precision);

size_t ali_vprint_arg(char *str, const char *format, va_list args)
{
    size_t length = 0;

    for (const char *p = format; *p; p++) {
        switch (*p) {
        case 'd':
        case 'i':
            // Signed decimal integer.
            va_arg(args, int);
            break;
        case 'u':
            // Unsigned decimal integer.
            va_arg(args, unsigned int);
            break;
        case 'o':
            // Unsigned octal.
            va_arg(args, unsigned int);
            break;
        case 'x':
            // Unsigned hexadecimal integer, lowercase.
            va_arg(args, unsigned int);
            break;
        case 'X':
            // Unsigned hexadecimal integer, uppercase.
            va_arg(args, unsigned int);
            break;
        /*
        case 'f':
            // Decimal floating point, lowercase.
            va_arg(args, double);
            break;
        case 'F':
            // Decimal floating point, uppercase.
            va_arg(args, double);
            break;
        case 'e':
            // Scientific notation (mantissa/exponent), lowercase.
            va_arg(args, double);
            break;
        case 'E':
            // Scientific notation (mantissa/exponent), uppercase.
            va_arg(args, double);
            break;
        case 'g':
            // Use the shortest representation: %e or %f.
            va_arg(args, double);
            break;
        case 'G':
            // Use the shortest representation: %E or %F.
            va_arg(args, double);
            break;
        case 'a':
            // Hexadecimal floating point, lowercase.
            va_arg(args, double);
            break;
        case 'A':
            // Hexadecimal floating point, uppercase.
            va_arg(args, double);
            break;
        case 'c':
            // Character.
            va_arg(args, char);
            break;
        case 's':
            // String of characters.
            va_arg(args, const char*);
            break;
        case 'p':
            // Pointer address.
            va_arg(args, unsigned int);
            break;
        */
        case 'n':
            // Nothing printed.
            break;
        case '%':
            // A literal %.
            str[length] = '%';
            length++;
            break;
        }
    }

    return length;
}
