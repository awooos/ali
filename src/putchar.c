#include <ali/event.h>

int putchar(int c)
{
    // FIXME: Make this significantly less kludgey.
    char string[2] = {(char)c, 0};

    event_trigger("print string", (char*)string);

    return c;
}

