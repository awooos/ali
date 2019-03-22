#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <ali/number.h>

int ali_sprintni(char *str, size_t size, int min_length,
                 int64_t number, size_t base, int flags, int precision);
int ali_sprintnu(char *str, size_t size, int min_length,
                 uint64_t number, size_t base, int flags, int precision);

int ali_vprint_arg(char *str, int offset, size_t size, const char *format, va_list args)
{
    char tmp_c;
    const char *tmp_s;
    int tmp_i;
    unsigned int tmp_u;

    size -= (size_t)offset;
    str += offset;

    const char *p = format;

    switch (*p) {
    case 'd':
    case 'i':
        // Signed decimal integer.
        tmp_i = va_arg(args, int);
        return ali_sprintni(
            str, size, 1 /* min_length */,
            tmp_i, 10 /* base */, 0 /* flags */, 1 /* precision */
        );
    case 'u':
        // Unsigned decimal integer.
        tmp_u = va_arg(args, unsigned int);
        return ali_sprintnu(
            str, size, 1 /* min_length */,
            tmp_u, 10 /* base */, 0 /* flags */, 1 /* precision */
        );
    case 'o':
        // Unsigned octal.
        tmp_u = va_arg(args, unsigned int);
        return ali_sprintnu(
            str, size, 1 /* min_length */,
            tmp_u, 8 /* base */, 0 /* flags */, 1 /* precision */
        );
    case 'x':
        // Unsigned hexadecimal integer, lowercase.
        tmp_u = va_arg(args, unsigned int);
        return ali_sprintnu(
            str, size, 1 /* min_length */,
            tmp_u, 16 /* base */, 0 /* flags */, 1 /* precision */
        );
    case 'X':
        // Unsigned hexadecimal integer, uppercase.
        // TODO: Make this uppercase.
        tmp_u = va_arg(args, unsigned int);
        return ali_sprintnu(
            str, size, 1 /* min_length */,
            tmp_u, 16 /* base */, 0 /* flags */, 1 /* precision */
        );
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
    */
    case 'c':
        // Character.
        tmp_c = (char)va_arg(args, int);
        if (str) {
            str[0] = tmp_c;
        }
        return 1;
    case 's':
        // String of characters.
        tmp_s = va_arg(args, const char*);
        size_t tmp_s_len = strlen(tmp_s);

        if (size < tmp_s_len) {
            return -1;
        }

        if (str) {
            strncpy(str, tmp_s, tmp_s_len);
        }
        return (int)tmp_s_len;
    /*
    case 'p':
        // Pointer address.
        va_arg(args, unsigned int);
        break;
    */
    case 'n':
        // Nothing printed.
        return 0;
    case '%':
        // A literal %.
        str[0] = '%';
        return 1;
    }

    return -1;
}
