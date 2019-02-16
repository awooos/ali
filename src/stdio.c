#include <ali/event.h>
#include <stdio.h>

int putchar(int c)
{
    // FIXME: Make this significantly less kludgey.
    char string[2] = {(char)c, 0};

    event_trigger("print string", (char*)string);

    return c;
}

int puts(const char *string)
{
    int idx = 0;

    for (idx = 0; string[idx]; idx++) {
        putchar((int)string[idx]);
    }

    return idx;
}
