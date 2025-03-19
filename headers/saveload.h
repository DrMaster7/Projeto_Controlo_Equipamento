#ifndef SAVELOAD_H
#define SAVELOAD_H

// Inicialização das funções do ficheiro saveload.c

#include "main.h"

int saveScooters(trotinete *estrotinete);
trotinete *loadScooters(int *count);

#endif