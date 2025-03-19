#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\e[1;35m"
#define CYAN "\e[1;36m"
#define WHITE "\e[1;37m"
#define RESET "\033[0m"

#ifndef MAIN_H
#define MAIN_H

int option;
int *count;

typedef struct
{
    int id;
    int battery;
    char *locked;
} trotinete;

typedef struct {
    int id;
    char eventType;
    int battery;
    unsigned long timestamp;
    struct log *next;
} log;

log *logs_head = NULL;
log *logs_tail = NULL;

#include "logs.h"
#include "menu_scooters.h"
#include "menu.h"
#include "saveload.h"
#include "scooters.h"

#endif