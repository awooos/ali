#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <ali/number.h>

int ali_sprintni(char *str, size_t size, int min_length,
                 int64_t number, size_t base, int flags, int precision)
{
    char *tmp = int64_to_str_radix(number, base);
    size_t length = strlen(tmp);

    if (length > size) {
        return -1;
    }

    (void)min_length;
    (void)flags;
    (void)precision;

    for (size_t idx = 0; idx < length; idx++) {
        str[idx] = tmp[idx];
    }

    free(tmp);

    return (int)length;
}

int ali_sprintnu(char *str, size_t size, int min_length,
                 uint64_t number, size_t base, int flags, int precision)
{
    char *tmp = uint64_to_str_radix(number, base);
    size_t length = strlen(tmp);

    if (length > size) {
        return -1;
    }

    (void)min_length;
    (void)flags;
    (void)precision;

    for (size_t idx = 0; idx < length; idx++) {
        str[idx] = tmp[idx];
    }

    return (int)length;
}
