#include "../headers/scooters.h"

// Função para dar as informações da trotinete.
void infoScooters(trotinete *estrotinete)
{
    printf("Scooters Information: \n\n");

    for (int i = 0; i < 4; i++)
    { // Loop para verificar as 4 trotinetes.
        printf("Scooter %d\n", i + 1);
        printf("Battery: %d%%\n", estrotinete[i].battery);
        printf("Locked: %s\n\n", estrotinete[i].locked);
    }
}

// Função para utilizar as trotinetes da base.
void useScooters(trotinete *estrotinete)
{
    int option;
    int index;
    do {
        printf("\nChoose a scooter to ride (1-4) (to leave, click 0): ");
        if (scanf("%d", &option) != 1) { // Limpar entrada inválida
            while(getchar() != '\n'); 
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (option < 0 || option > 4) { // Se a entrada for menor que 0 e maior que 4.
            printf("Invalid option. Please choose a number between 0 and 4.\n");
            continue;
        }
        else if (option == 0)
        {
            menuScooters(estrotinete);
            continue;
        }
        index = option - 1;  // Ajusta para índice do array (0-3)
        
        if (strcmp(estrotinete[index].locked, "Yes") == 0) // Se a trotinete estiver trancada.
        {
            if (estrotinete[index].battery <= 2) // Se a trotinete estiver com 20% bateria ou menos.
            {
                printf("Scooter's battery low. Please wait for the recharging.\n");
            }
            else if (estrotinete[index].battery <= 5) // Se a trotinete estiver com 50% bateria ou menos.
            {
                estrotinete[index].locked = "No"; // Destranca a trotinete.
                printf("Scooter unlocked. Have a nice travel.\n");
                printf("WARNING: Battery at %d%%, long journeys can completely drain the battery.\n", estrotinete[index].battery);
            }
            else
            {
                estrotinete[index].locked = "No"; // Destranca a trotinete.
                printf("Scooter unlocked. Have a nice travel.\n");
                logEvents(estrotinete[index].id, EVENT_UNLOCKED, estrotinete[index].battery); // Ligação à função "logs()" para registar que foi desbloqueada.
            }
        }
        else if (strcmp(estrotinete[index].locked, "Yes") != 0) // Se a trotinete já estiver destrancada.
        {
            printf("The scooter has been unlocked and is in use. Please use another scooter.\n");
        }
        else
        {
            printf("Invalid option.");
            option = 0;
        }
    } while (option != 0);
}

// Função para devolver as trotinetes à base.
void returnScooters(trotinete *estrotinete)
{
    int option;
    int index;
    do
    {
        printf("\nChoose a scooter to deliver (1-4) (to leave, click 0): ");
        if (scanf("%d", &option) != 1) { // Limpar entrada inválida
            while(getchar() != '\n'); 
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (option < 0 || option > 4) { // Se a entrada for menor que 0 e maior que 4.
            printf("Invalid option. Please choose a number between 0 and 4.\n");
            continue;
        }
        else if (option == 0)
        {
            menuScooters(estrotinete);
        }
        index = option - 1;  // Ajusta para índice do array (0-3)

        if (strcmp(estrotinete[index].locked, "No") == 0) // Se a trotinete estiver destrancada.
        {
            estrotinete[index].locked = "Yes"; // Tranca a trotinete.
            printf("Scooter has been locked.\n");
            logEvents(estrotinete[index].id, EVENT_LOCKED, estrotinete[index].battery); // Ligação à função "logs()" para registar que foi bloqueada.
        }
        else if (strcmp(estrotinete[index].locked, "No") != 0) // Se a trotinete já estiver trancada.
        {
            printf("Scooter was already locked.\n");
        }
        else
        {
            printf("Invalid option.");
            option = 0;
        }
    } while (option != 0);
}
