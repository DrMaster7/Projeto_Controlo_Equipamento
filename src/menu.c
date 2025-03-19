#include "../headers/menu.h"

// Função para o menu.
int menu(trotinete *estrotinete)
{
    int option = 0;
    do
    {
        printf(WHITE "\n----- SCOOTY CHARGER -----\n" RESET);
        printf(RED "0 - Exit\n" RESET);      // Sair do programa.
        printf(GREEN "1 - Scooters\n" RESET); // Verifica as trotinetes.
        printf(BLUE "2 - Logs\n" RESET);   // Verifica os logs das trotinetes.
        printf(WHITE "Choose an option: " RESET);
        scanf("%d", &option); // Lê a opção que o utilizador escolheu.

        if (option == 1)
        {                              // Se o utilizador escolheu a opção 1.
            menuScooters(estrotinete); // Iniciação da função "menuScooters()".
        }
        else if (option == 2)
        { // Se o utilizador escolheu a opção 2.
            printLogs(); // Iniciação da função "printLogs()".
        }
        else if (option != 0)
        { // Se o utilizador escolher outra opção fora 0, 1 e 2.
            printf("Invalid option, choose an option between 0-2.\n");
        }
    } while (option != 0); // Enquanto o utilizador não escolher a opção "0".

    saveScooters(estrotinete); // Salva as trotinetes ao sair

    return option; // Retorna o valor de `option` (0 para sair)
}
