#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Implementacao_Automato.h"

/* Implementação AFD
   Alunos: Victor Propheta
*/

/* Para compilar utilizar o comando no terminal: gcc main.c Implementacao_Automato.c -o Automato -I. */

int main() {

    int Numero_Estados, Numero_Caracteres_Alfabeto;
    char *Estados, *Alfabeto, *Estado_Final, Estado_Inicial, **Delta, Palavra[100000], Opcao[6];

    do {
        system("cls");
        Leitura_Valores_Automato(&Numero_Estados, &Numero_Caracteres_Alfabeto);
        Estados = Alocar_Vetor_Caracter(Numero_Estados); /* Alocação de espaço para  Estados */
        Alfabeto = Alocar_Vetor_Caracter(Numero_Caracteres_Alfabeto); /*Alocação de espaço para Alfabeto */
        Estado_Final = Alocar_Vetor_Caracter(Numero_Estados); /* Alocação para Estado(s) Final (is) */
        Leitura_Alfabeto(Alfabeto); /* Leitura do Alfabeto do Automato */
        Leitura_Estados(Estados, Estado_Final, &Estado_Inicial); /* Leitura dos Estados do Automato */
        Eliminar_Virgulas(Estados, Numero_Estados);
        Eliminar_Virgulas(Alfabeto, Numero_Caracteres_Alfabeto);
        Eliminar_Virgulas(Estado_Final, Numero_Estados);
        Delta = Alocar_Matriz_Caracter(Numero_Estados); /* Alocação da matriz delta */
        Leitura_Delta(Delta, Estados, Alfabeto, Numero_Estados, Numero_Caracteres_Alfabeto);
        do {
            printf("Digite a Palavra a ser verificada, ou Digite Sair para terminar \n");
            fflush(stdin);
            gets(Palavra);
            if (strcmp(Palavra, "Sair")) {
                Verifica_Palavra(Delta, Palavra, Alfabeto, Estados, Estado_Final, Estado_Inicial, Numero_Estados, Numero_Caracteres_Alfabeto);

            }
        } while ((strcmp(Palavra, "Sair")));

        system("cls");
        printf("Deseja Inserir um novo Automato ? \n");
        printf(" 1 - Sim     2 - Nao\n");
        gets(Opcao);
    } while ((strcmp(Opcao, "2")));
    /* Liberar variaveis alocadas */
    Liberar_Matriz_Caracter(Numero_Estados,Delta);
    Liberar_Vetor_Caracter(Numero_Estados,Estados);
    Liberar_Vetor_Caracter(Numero_Caracteres_Alfabeto,Alfabeto);
    Liberar_Vetor_Caracter(Numero_Estados,Estado_Final);
    return 0;

}
