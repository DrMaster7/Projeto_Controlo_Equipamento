#include "../headers/logs.h"

// Function to log a message to a log file.
void logAction(const char *action)
{
    FILE *logfile = fopen("logs.txt", "a"); // Open the log file in append mode.
    if (logfile == NULL)
    {
        printf("Error opening log file.\n");
        return;
    }

    // Get the current time
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    // Write the log entry with timestamp
    fprintf(logfile, "[%s] %s\n", timestamp, action);

    fclose(logfile);
}

void viewLogs()
{
    FILE *logfile = fopen("logs.txt", "r");
    if (logfile == NULL)
    {
        printf("No logs available.\n");
        return;
    }

    // Find the number of lines in the log file.
    char line[256];
    int lineCount = 0;
    while (fgets(line, sizeof(line), logfile) != NULL)
    {
        lineCount++;
    }

    // If there are more than 30 lines, enable paging.
    int linesPerPage = 30;
    int pages = (lineCount / linesPerPage) + (lineCount % linesPerPage != 0);

    // Go back to the beginning of the file to read it again in reverse order.
    rewind(logfile);

    // Store the lines in an array to reverse them.
    char *lines[lineCount];
    int i = 0;
    while (fgets(line, sizeof(line), logfile) != NULL)
    {
        lines[i] = strdup(line); // Allocate and store each line
        i++;
    }

    printf(WHITE "\n-+-+- LOGS -+-+-\n" RESET);

    // If there are more than 30 lines, ask the user which page they want to see.
    if (pages > 1)
    {
        int pageNum;
        do
        {
            // Request user input for the page number.
            printf("There are %d pages of logs. Enter the page number to view (1-%d): ", pages, pages);
            scanf("%d", &pageNum);

            // Ensure the page number is valid.
            if (pageNum < 1 || pageNum > pages)
            {
                printf("Invalid page number. Please try again.\n");
            }

        } while (pageNum < 1 || pageNum > pages); // Repeat if the user inputs an invalid page number

        // Calculate the range of lines for the requested page.
        int startLine = (pageNum - 1) * linesPerPage;
        int endLine = startLine + linesPerPage;
        if (endLine > lineCount)
            endLine = lineCount;

        // Print the requested page of logs.
        for (int j = startLine; j < endLine; j++)
        {
            printf("%s", lines[j]);
        }
    }
    else
    {
        // If there's only one page, simply print all lines in reverse order.
        for (int j = lineCount - 1; j >= 0; j--)
        {
            printf("%s", lines[j]);
        }
    }

    // Free allocated memory
    for (int i = 0; i < lineCount; i++)
    {
        free(lines[i]);
    }

    fclose(logfile);
}
