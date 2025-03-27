// #include "../headers/menu_scooters.h"

// // Função para o menu relacionado às trotinetes.
// void menuScooters(trotinete *estrotinete)
// {
//     int option = 0;
//     do
//     {
//         printf(WHITE "\n---------- SCOOTERS ----------\n" RESET);
//         printf(CYAN "0 - Exit\n" RESET);                  // Sair do programa.
//         printf(MAGENTA "1 - See Scooters Status\n" RESET);  // Verifica as informações da trotinete.
//         printf(GREEN "2 - Get Scooter\n" RESET);         // Utilização de uma trotinete.
//         printf(YELLOW "3 - Return Scooter\n" RESET);  // Retorno de uma trotinete.
//         printf(RED "4 - Reset Settings\n\n" RESET);      // Reseta os dados das trotinetes.
//         printf(WHITE "Choose an option: " RESET);
//         scanf("%d", &option); // Lê a opção que o utilizador escolheu.

//         if (option == 1)
//         {                              // Se o utilizador escolheu a opção 1.
//             infoScooters(estrotinete); // Iniciação da função "infoScooters()".
//         }
//         else if (option == 2)
//         {                             // Se o utilizador escolheu a opção 2.
//             useScooters(estrotinete); // Iniciação da função "useScooters()".
//         }
//         else if (option == 3)
//         {                                // Se o utilizador escolheu a opção 3.
//             returnScooters(estrotinete); // Iniciação da função "returnScooters()".
//         }
//         else if (option == 4)
//         {           // Se o utilizador escolheu a opção 4.
//             printf("WARNING: You are about to delete all configurations.\n");
//             printf("0 - Return back\n");
//             printf("1 - Reset Configurations\n");
//             printf("Proceed with the operation? ");
//             scanf("%d", &option);

//             if (option == 1)
//             {
//                 FILE *file = fopen("scooters.dat", "rb"); // Abre o ficheiro "scooters.dat" em modo de leitura binária.
//                 if (file)
//                 {
//                     fclose(file);              // Fecha o ficheiro antes de removê-lo (caso contrário não irá deletar).
//                     if (remove("scooters.dat") == 0) {
//                         printf("Configurations reset.");
//                     } else {
//                         printf("Error: Configurations not reset.");
//                     }
//                 }
//                 else
//                 {
//                     printf("Error: Configurations not reset.");
//                     break;
//                 }
//             }
//             else if (option == 0)
//             {
//                 menu(estrotinete); // Retorno ao menu das scooters.
//             }
//             else
//             {
//                 printf("Invalid option, choose an option between 0-1.\n");
//             }
//         }
//         else if (option == 0)
//         {
//             menu(estrotinete);
//         }
//         else if (option != 0)
//         { // Se o utilizador escolher outra opção fora do eixo 0-4.
//             printf("Invalid option, choose an option between 0-4.\n");
//         }
//     } while (option != 0); // Enquanto o utilizador não escolher a opção "0".
// }