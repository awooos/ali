#include <tinker.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t test_ali_printf_assertions(void)
{
    TEST_HAS_ASSERTIONS();

    char str[20];
    int ret;

    // Set str to the letter "x" repeated 19 times.
    memset(str, (int)'x', 19);
    str[19] = 0;

    ret = snprintf(str, 20, "bork bork\n");
    TEST_ASSERT(ret > 0);
    TEST_ASSERT(strncmp((const char*)str, "bork bork\n", 20) == 0);

    // Set str to the letter "x" repeated 19 times.
    memset(str, (int)'x', 19);
    str[19] = 0;

    ret = snprintf(str, 20, "%s %i %u %s", "foo", 3, -4, "bar");
    TEST_ASSERT(ret > 0);
    puts("\n\nstr='");
    puts(str);
    puts("'\n\n");
    TEST_ASSERT(strncmp((const char*)str, "foo 3 -4 bar", 20) == 0);

    TEST_ASSERTIONS_RETURN();
}

void add_ali_printf_tests(void)
{
    tinker_add_test(ali_printf_assertions);
}
