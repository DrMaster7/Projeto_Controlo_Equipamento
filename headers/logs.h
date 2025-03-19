#ifndef LOGS_H
#define LOGS_H

#define EVENT_UNLOCKED 'U'
#define EVENT_LOCKED   'L'
#define EVENT_BATTERY  'B'

int logCount = 0;

// Inicialização das funções do ficheiro logs.c

#include "main.h"

void logEvents(int id, char eventType, int battery);
void saveLogs();
void printLogs();
void freeLogs();

#endif