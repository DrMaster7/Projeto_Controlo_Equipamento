#include "../headers/logs.h"

// Função para os logs
void logEvents(int id, char eventType, int battery) {
    log *newLog = (log*) malloc(sizeof(log));
    if (newLog == NULL) {
        perror("Error in alocating memory to log.");
        return;
    }
    newLog->id = id;
    newLog->eventType = eventType;
    newLog->battery = battery;
    newLog->timestamp = time(NULL);
    newLog->next = NULL;
    logCount++;

    if (logs_head == NULL) {
        logs_head = newLog;
        logs_tail = newLog;
    } else {
        logs_tail->next = newLog;
        logs_tail = newLog;
    }
}

void saveLogs() {
    FILE *file = fopen("logs.dat", "wb");
    if (file == NULL) {
        perror("Error in opening the logs file.");
        return;
    }
    
    char timeStr[26];
    log *current = logs_head;
    while (current != NULL) {
        struct tm *tm_info = localtime(&current->timestamp);
        strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        
        char *eventDesc;
        switch (current->eventType) {
            case EVENT_BATTERY:
                eventDesc = "Battery changed.";
                break;
            case EVENT_UNLOCKED:
                eventDesc = "Scooter unlocked and being used";
                break;
            case EVENT_LOCKED:
                eventDesc = "Scooter locked and free to be used";
                break;
            default:
                eventDesc = "Unknown event";
        }
        fprintf(file, "Trotinete %d | %s | %s | Battery: %d\n", 
        current->id, timeStr, *eventDesc, current->battery);
        current = current->next;
    }
    fclose(file);
}

void printLogs() {
    char timeStr[26];
    log *current = logs_head;
    while (current != NULL) {
        struct tm *tm_info = localtime(&current->timestamp);
        strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Trotinete %d | %s | Battery: %d\n",
            current->id, timeStr, current->battery);
        current = current->next;
    }
}

void freeLogs() {
    log *current = logs_head;
    while (current != NULL) {
        log *temp = current;
        current = current->next;
        free(temp);
    }
    logs_head = NULL;
    logs_tail = NULL;
    logCount = 0;
}