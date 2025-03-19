#include "../headers/saveload.h"

// Função para salvar as informações das trotinetes em um arquivo .dat
int saveScooters(trotinete *estrotinete)
{
    FILE *file = fopen("scooters.dat", "wb"); // Abre o arquivo para escrita binária
    if (!file)
    {
        printf("Error in saving the file. Please try again.\n");
        return 0; // Retorna 0 se ocorrer erro ao abrir o arquivo
    }

    size_t result = fwrite(estrotinete, sizeof(trotinete), 4, file); // Escreve as 4 trotinetes
    if (result != 4)
    {
        printf("Error in saving the file.\n");
        fclose(file);
        return 0;
    }

    fclose(file); // Fecha o arquivo
    return 1;     // Retorna 1 indicando sucesso
}

// Função para carregar as informações das trotinetes de um arquivo .dat
trotinete *loadScooters(int *count)
{
    FILE *file = fopen("scooters.dat", "rb"); // Abre o arquivo para leitura binária
    if (!file)
    {
        *count = 0;
        return NULL; // Retorna NULL se o arquivo não for encontrado
    }

    trotinete *estrotinete = malloc(4 * sizeof(trotinete)); // Aloca memória para as trotinetes
    if (!estrotinete)
    {
        printf("Error in alocating memory.\n");
        fclose(file);
        return NULL;
    }

    size_t result = fread(estrotinete, sizeof(trotinete), 4, file); // Lê as 4 trotinetes do arquivo
    if (result != 4)
    {
        printf("Error in reading the logs.\n");
        free(estrotinete);
        fclose(file);
        return NULL;
    }

    *count = 4;         // Define que temos 4 trotinetes carregadas
    fclose(file);       // Fecha o arquivo
    return estrotinete; // Retorna o ponteiro para as trotinetes
}