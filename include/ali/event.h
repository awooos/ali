#ifndef ALI_EVENT_H
#define ALI_EVENT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef void AliEventHandler(void *data);

#define ALI_EVENT_MAX_EVENT_GROUPS 50
#define ALI_EVENT_MAX_HANDLERS_PER_GROUP 50

typedef struct ali_event_group {
    const char *name;
    size_t number_of_handlers;
    AliEventHandler *handlers[ALI_EVENT_MAX_HANDLERS_PER_GROUP];
} AliEventGroup;

bool event_watch(const char *event_name, AliEventHandler *handler);
bool event_trigger(const char *event_name, void *data);

#endif
