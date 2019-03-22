#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <ali/number.h>

int ali_sprintni(char *str, int offset, size_t size, int min_length,
                 int64_t number, size_t base, int flags, int precision);
int ali_sprintnu(char *str, int offset, size_t size, int min_length,
                 uint64_t number, size_t base, int flags, int precision);

int ali_vprint_arg(char *str, int offset, size_t size, const char *format, va_list args)
{
    char tmp_c;
    const char *tmp_s;
    int tmp_i;
    unsigned int tmp_u;

    int length = 0;
    int tmp_ret = 0;

    str += offset;
    length += offset;

    for (const char *p = format; *p; p++) {
        switch (*p) {
        case 'd':
        case 'i':
            // Signed decimal integer.
            tmp_i = va_arg(args, int);
            tmp_ret = ali_sprintni(
                str, length, (size - (size_t)length), 1 /* min_length */,
                tmp_i, 10 /* base */, 0 /* flags */, 1 /* precision */
            );
            length += tmp_ret;
            return length;
        case 'u':
            // Unsigned decimal integer.
            tmp_u = va_arg(args, unsigned int);
            tmp_ret = ali_sprintnu(
                str, length, (size - (size_t)length), 1 /* min_length */,
                tmp_u, 10 /* base */, 0 /* flags */, 1 /* precision */
            );
            length += tmp_ret;
            return length;
        case 'o':
            // Unsigned octal.
            tmp_u = va_arg(args, unsigned int);
            tmp_ret = ali_sprintnu(
                str, length, (size - (size_t)length), 1 /* min_length */,
                tmp_u, 8 /* base */, 0 /* flags */, 1 /* precision */
            );
            length += tmp_ret;
            return length;
        case 'x':
            // Unsigned hexadecimal integer, lowercase.
            tmp_u = va_arg(args, unsigned int);
            tmp_ret = ali_sprintnu(
                str, length, (size - (size_t)length), 1 /* min_length */,
                tmp_u, 16 /* base */, 0 /* flags */, 1 /* precision */
            );
            length += tmp_ret;
            return length;
        case 'X':
            // Unsigned hexadecimal integer, uppercase.
            // TODO: Make this uppercase.
            tmp_u = va_arg(args, unsigned int);
            tmp_ret = ali_sprintnu(
                str, length, (size - (size_t)length), 1 /* min_length */,
                tmp_u, 16 /* base */, 0 /* flags */, 1 /* precision */
            );
            length += tmp_ret;
            return length;
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
                str[length] = tmp_c;
            }
            length++;
            return length;
        case 's':
            // String of characters.
            tmp_s = va_arg(args, const char*);
            size_t tmp_s_len = strlen(tmp_s);

            if ((size - (size_t)length) < tmp_s_len) {
                return -1;
            }

            if (str) {
                strncpy(str, tmp_s, tmp_s_len);
            }
            length += tmp_s_len;
            return length;
        /*
        case 'p':
            // Pointer address.
            va_arg(args, unsigned int);
            break;
        */
        case 'n':
            // Nothing printed.
            return length;
        case '%':
            // A literal %.
            str[length] = '%';
            length++;
            return length;
        }

        if (tmp_ret < 0) {
            return tmp_ret;
        }
    }

    return (int)length;
}
