#include <errno.h>
#include <tinker.h>
#include <stdint.h>
#include <stdlib.h>

void test_ali_str_to_int_assertions(void)
{
    // The base has to be between 2 and 36, inclusive.
    // Outside of that range, it should set errno to EINVAL.
    /*
    int errsv;
    errno = 0;
    strtoll("abcd", NULL, 1);
    errsv = errno;
    tinker_assert(errsv == EINVAL);

    errno = 0;
    strtoll("abcd", NULL, 2);
    errsv = errno;
    tinker_assert(errsv != EINVAL);

    errno = 0;
    strtoll("abcd", NULL, 36);
    errsv = errno;
    tinker_assert(errsv != EINVAL);

    errno = 0;
    ret = strtoll("abcd", NULL, 37);
    errsv = errno;
    tinker_assert(ret == -1);
    tinker_assert(errsv == EINVAL);
    */

    tinker_assert(atoi("10") == 10);
    tinker_assert(atoi("1234567890") == 1234567890);
    tinker_assert(atoi("000000001234567890") == 1234567890);

    tinker_assert(atoi("-0") == 0);
    tinker_assert(atoi("-10") == -10);
    tinker_assert(atoi("-1234567890") == -1234567890);
    tinker_assert(atoi("-000000001234567890") == -1234567890);

    tinker_assert(strtol("abcd", NULL, 16) == 0xabcd);
    tinker_assert(strtol("ABCD", NULL, 16) == 0xABCD);
    tinker_assert(strtoll("12a3bc89f", NULL, 16) == 0x12a3bc89f);

    tinker_assert(strtol("-abcd", NULL, 16) == -0xabcd);
    tinker_assert(strtol("-ABCD", NULL, 16) == -0xABCD);
    tinker_assert(strtoll("-12a3bc89f", NULL, 16) == -0x12a3bc89f);

    const char *str = "-12a9 NaN 4321";
    char *end10;
    char *end16;
    tinker_assert(strtoll("-12a9 NaN 4321", &end16, 16) == -0x12a9);
    tinker_assert(strtoll("-12a9 NaN 4321", &end10, 10) == -12);
    tinker_assert(end16 == str + 5);
    tinker_assert(end10 == str + 3);
}

void add_ali_str_to_int_tests(void)
{
    tinker_add_test(ali_str_to_int_assertions);
}
