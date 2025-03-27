#include "../headers/scooters.h"

// Função para dar as informações da trotinete.
void infoScooters(trotinete *estrotinete)
{
    printf("Scooters Information: \n\n");

    for (int i = 0; i < 4; i++)
    { // Loop para verificar as 4 trotinetes.
        printf("Scooter %d\n", estrotinete[i].id);
        printf("Battery: %d%%\n", estrotinete[i].battery);
        printf("Locked: %s\n\n", estrotinete[i].locked);
    }
}

void ResetScooters(trotinete *estrotinete)
{

    int option = 0;

    printf("WARNING: You are about to delete all configurations.\n");
    printf("0 - Return back\n");
    printf("1 - Reset Configurations\n");
    printf("Proceed with the operation? ");
    scanf("%d", &option);

    if (option == 1)
    {
        logAction("3: Utilizador Reiniciou os Estados das Trotinetes"); // Log the action
        printf("Data Reseted\n");
    }
    else if (option != 0)
    {
        printf("Invalid option, choose an option between 0-1.\n");
    }
}