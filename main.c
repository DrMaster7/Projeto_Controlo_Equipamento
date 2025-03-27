#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "./headers/main.h"
#include "./src/menu.c"
#include "./src/logs.c"
#include "./src/scooters.c"

int main()
{
    // Inicializa as trotinetes manualmente
    trotinete estrotinete[4] = {
        {1, 8, "Yes"},
        {2, 10, "No"},
        {3, 5, "No"},
        {4, 1, "No"}};

    // Chama o menu para visualizar as informações das trotinetes
    menu(estrotinete);
    return 0;
}
