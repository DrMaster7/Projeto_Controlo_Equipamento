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
    while (1) {
        printf("\nChoose a scooter to ride (1-4): ");
        if (scanf("%d", &option) != 1) { // Limpar entrada inválida
            while(getchar() != '\n'); 
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (option < 1 || option > 4) { // Se a entrada for menor que 1 e maior que 4.
            printf("Invalid option. Please choose a number between 1 and 4.\n");
            continue;
        }
        option--;  // Ajusta para índice do array (0-3)
        
        if (strcmp(estrotinete[option].locked, "Yes") == 0) // Se a trotinete estiver trancada.
        {
            if (estrotinete[option].battery <= 2) // Se a trotinete estiver com 20% bateria ou menos.
            {
                printf("Low scooter charge. Please wait for charging.\n");
            }
            else if (estrotinete[option].battery <= 5) // Se a trotinete estiver com 50% bateria ou menos.
            {
                estrotinete[option].locked = "No"; // Destranca a trotinete.
                printf("WARNING: Battery at %d%%, long journeys can completely drain the battery.\n", estrotinete[option].battery);
            }
            else
            {
                estrotinete[option].locked = "No"; // Destranca a trotinete.
                printf("Scooter unlocked. Have a nice travel.\n");
                logEvents(estrotinete[option].id, EVENT_UNLOCKED, estrotinete[option].battery); // Ligação à função "logs()" para registar que foi desbloqueada.
            }
        }
        else if (strcmp(estrotinete[option].locked, "Yes") != 0) // Se a trotinete já estiver destrancada.
        {
            printf("The scooter has been unlocked and is in use. Please use another scooter.\n");
        }
        else
        {
            printf("Invalid option.");
            option = 0;
        }
    };
}

// Função para devolver as trotinetes à base.
void returnScooters(trotinete *estrotinete)
{
    int option;

    while(1)
    {
        printf("\nChoose a scooter to deliver (1-4): ");
        if (scanf("%d", &option) != 1) { // Limpar entrada inválida
            while(getchar() != '\n'); 
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (option < 1 || option > 4) { // Se a entrada for menor que 1 e maior que 4.
            printf("Invalid option. Please choose a number between 1 and 4.\n");
            continue;
        }
        option--;  // Ajusta para índice do array (0-3)

        if (strcmp(estrotinete[option].locked, "No") == 0) // Se a trotinete estiver destrancada.
        {
            estrotinete[option].locked = "Yes"; // Tranca a trotinete.
            printf("Scooter has been locked.\n");
            logEvents(estrotinete[option].id, EVENT_LOCKED, estrotinete[option].battery); // Ligação à função "logs()" para registar que foi bloqueada.
        }
        else if (strcmp(estrotinete[option].locked, "No") != 0) // Se a trotinete já estiver trancada.
        {
            printf("Scooter was already locked.\n");
        }
        break;
    }
}
