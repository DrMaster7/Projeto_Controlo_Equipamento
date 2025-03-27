#include "../headers/menu.h"

// Função para o menu.
void menu(trotinete *estrotinete)
{
    int option;
    do
    {
        printf(WHITE "\n-+-+-+-+- SCOOTY CHARGER -+-+-+-+-\n\n" RESET);
        printf(RED "0 - Exit\n" RESET);                   // Sair do programa.
        printf(YELLOW "1 - See Scooters Status\n" RESET); // Permite visualizar as trotinetes.
        printf(GREEN "2 - Logs\n" RESET);                 // Verifica os logs das trotinetes.
        printf(BLUE "3 - Reset Status\n" RESET);          // Reinicia os estados das trotinetes.
        printf(WHITE "\nChoose an option: " RESET);
        scanf("%d", &option); // Lê a opção que o utilizador escolheu.

        if (option == 1)
        {                                                             // Se o utilizador escolheu a opção 1.
            logAction("1: Utilizador viu os Estados das Trotinetes"); // Log the action
            infoScooters(estrotinete);                                // Exibe as informações das trotinetes.
        }
        else if (option == 2)
        {
            logAction("2: Utilizador Verificou os Logs"); // Log the action
            viewLogs();                                   // Mostrar Logs
        }
        else if (option == 3)
        {                               // Se o utilizador escolheu a opção 2.
            ResetScooters(estrotinete); // Exibe os logs registrados.
        }
        else if (option == 0)
        {
            logAction("0: O utilizador saiu do Programa"); // Log the action
            printf("\nFIM DO PROGRAMA\n\nProjeto Realizado pelo Grupo 03\n");
        }
        else
        { // Se o utilizador escolher outra opção fora 0,1,2.

            printf("Invalid option, choose an option between 0-2.\n");
        }
    } while (option != 0); // Enquanto o utilizador não escolher a opção "0".
}
