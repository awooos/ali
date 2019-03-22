#include <tinker.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sprintn.h"

size_t test_ali_sprintn_assertions(void)
{
    TEST_HAS_ASSERTIONS();

    char str[10] = {0,};
    int ret;

    ret = ali_sprintnu(
        str, 10 /* size */, 1 /* min_length */,
        123456 /* number */ , 10 /* base */, 0 /* flags */, 1 /* precision */
    );
    TEST_ASSERT(ret > 0);
    TEST_ASSERT(strncmp((const char*)str, "123456", 6) == 0);


    ret = ali_sprintni(
        str, 10 /* size */, 1 /* min_length */,
        -123456 /* number */ , 10 /* base */, 0 /* flags */, 1 /* precision */
    );
    TEST_ASSERT(ret > 0);
    TEST_ASSERT(strncmp((const char*)str, "-123456", 6) == 0);



    TEST_ASSERTIONS_RETURN();
}
