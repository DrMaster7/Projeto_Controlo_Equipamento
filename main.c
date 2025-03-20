#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "./headers/main.h"
#include "./src/menu.c"
#include "./src/menu_scooters.c"
#include "./src/logs.c"
#include "./src/saveload.c"
#include "./src/scooters.c"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex para garantir acesso seguro às trotinetes
int end_program = 1;

// Função para atualizar as baterias
void *updateBatteries(void *arg)
{
    trotinete *estrotinete = (trotinete *)arg;
    do
    {
        pthread_mutex_lock(&mutex);

        for (int i = 0; i < 4; i++)
        {
            if (estrotinete[i].locked == "Yes")
            {
                estrotinete[i].battery = estrotinete[i].battery < 10 ? estrotinete[i].battery + 1 : 10;
                logEvents(estrotinete[i].id, EVENT_LOCKED, estrotinete[i].battery); // Ligação à função "logs()" para registar que houve mudança de bateria.
            }
            else
            {
                estrotinete[i].battery = estrotinete[i].battery > 0 ? estrotinete[i].battery - 1 : 0;
                logEvents(estrotinete[i].id, EVENT_UNLOCKED, estrotinete[i].battery); // Ligação à função "logs()" para registar que houve mudança de bateria.
            }
            if (estrotinete[i].battery == 0)
            {
                estrotinete[i].locked = "Yes"; // Tranca a trotinete.
                logEvents(estrotinete[i].id, EVENT_LOCKED, estrotinete[i].battery); // Ligação à função "logs()" para registar que foi bloqueada.
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(10);
    } while (end_program != 0);

    return NULL;
}

int main()
{
    // Carregar as trotinetes ou alocar novo conjunto
    int count = 0;
    trotinete *estrotinete = loadScooters(&count);
    if (!estrotinete)
    {
        estrotinete = malloc(4 * sizeof(trotinete));
        if (!estrotinete)
        {
            printf("Error in alocating memory.\n");
            return 1;
        }
        estrotinete[0] = (trotinete){1, 8, "Yes"};
        estrotinete[1] = (trotinete){2, 10, "No"};
        estrotinete[2] = (trotinete){3, 5, "No"};
        estrotinete[3] = (trotinete){4, 1, "No"};
    }

    // Criar thread para atualização das baterias
    pthread_t batteryThread;
    if (pthread_create(&batteryThread, NULL, updateBatteries, estrotinete) != 0)
    {
        printf("Error in creating thread.\n");
        return 1;
    }

    end_program = menu(estrotinete);

    // Aguardar término da thread e libertar recursos
    pthread_join(batteryThread, NULL);
    free(estrotinete);
    pthread_mutex_destroy(&mutex);

    saveLogs();
    return 0;
}
