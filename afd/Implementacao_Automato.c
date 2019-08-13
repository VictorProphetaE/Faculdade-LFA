#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include "Implementacao_Automato.h"

/* Função da Leitura do Numero de Estados e alfabetos */
void Leitura_Valores_Automato(int *Numero_Estados, int *Numero_Alfabeto) {


    printf("Digite o numero de Estados \n");
    scanf("%d", &(*Numero_Estados));
    printf("Digite o numero de caracteres do Alfabeto\n");
    scanf("%d", &(*Numero_Alfabeto));

}

/* Função para alocação de caracteres*/
char *Alocar_Vetor_Caracter(int Numero_Elementos) {

    char *Ponteiro_String;

    if (Numero_Elementos < 1) {
        printf("Numero de elementos a ser alocado invalido \n");
        exit(0);

    }
    /* aloca o vetor */
    Ponteiro_String = (char *) calloc(Numero_Elementos * 2, sizeof (char)); /* Para alocar vírgulas */
    if (Ponteiro_String == NULL) {
        printf("** Erro: Memoria Insuficiente **");
        return (NULL);
    }

    return (Ponteiro_String);
}

/*Função para alocação de matriz quadrada para caracteres */
char **Alocar_Matriz_Caracter(int Numero_Elementos) {

    char **Ponteiro_Matriz;
    int i;

    if (Numero_Elementos < 1) {
        printf("Numero de elementos a ser alocado invalido \n");
        exit(0);


    }
    /* aloca as linhas da matriz */
    Ponteiro_Matriz = (char **) calloc(Numero_Elementos, sizeof (char *));
    if (Ponteiro_Matriz == NULL) {
        printf("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    /* aloca as colunas da matriz */
    for (i = 0; i < Numero_Elementos; i++) {
        Ponteiro_Matriz[i] = (char *) calloc(Numero_Elementos, sizeof (char));
        if (Ponteiro_Matriz[i] == NULL) {
            printf("** Erro: Memoria Insuficiente **");
            return (NULL);
        }
    }
    return (Ponteiro_Matriz); /* retorna o ponteiro para a matriz */

}

/* Função para leitura do alfabeto do Autômato */
void Leitura_Alfabeto(char Alfabeto []) {
    system("cls");
    printf("___________________\n");
    printf("Leitura Alfabeto \n \n");
    printf("___________________\n");
    printf("Digite o Alfabeto do Automato, separado por virgulas \n");
    fflush(stdin); /* Limpeza Buffer */
    gets(Alfabeto);

}

/* Função para leitura dos estados do Autômato */
void Leitura_Estados(char Estados [], char Estado_Final[], char *Estado_Inicial) {
    printf("\n___________________\n");
    printf("Leitura Estados \n \n");
    printf("___________________\n");
    printf("Digite os Estados do Automato, separado por virgulas \n");
    fflush(stdin); /* Limpeza Buffer */
    gets(Estados);
    printf("\nDigite o(s) Estado(s) Final(is) separados por virgula se maior que 1\n");
    gets(Estado_Final);
    printf("\nDigite o Estado Inicial\n");
    scanf("%c", &(*Estado_Inicial));

}

/* Leitura de Transicoes */
void Leitura_Delta(char **Delta, char Estados[], char Alfabeto[], int Numero_Estados, int Numero_Caracteres_Alfabeto) {

    int i, j;
    system("cls");
    printf("_____________________________________\n");
    printf("Leitura de transicoes\n");
    printf("_____________________________________\n");
    for (i = 0; i < Numero_Estados; i++) {
        for (j = 0; j < Numero_Caracteres_Alfabeto; j++) {
            printf("\nTransicao[%c,%c] = ", Estados[i], Alfabeto[j]);
            fflush(stdin);
            scanf("%c", &Delta[i][j]);
        }
    }

}

/* Função para eliminar virgulas */
void Eliminar_Virgulas(char Cadeia [], int Numero_Elementos) {

    int i, j, Tamanho_String;
    Tamanho_String = strlen(Cadeia);
    char *Cadeia_Auxiliar;

    Cadeia_Auxiliar = Alocar_Vetor_Caracter(Numero_Elementos);
    j = 0;
    for (i = 0; i < Tamanho_String; i++) {
        if ((Cadeia[i] != ',') && (Cadeia[i] != ' ')) {
            Cadeia_Auxiliar[j] = Cadeia[i];
            j++;
        }
    }

    Cadeia_Auxiliar[j + 1] = '\0';
    strcpy(Cadeia, Cadeia_Auxiliar);
}

/* Verificar */
void Verifica_Palavra(char **Delta, char Palavra [], char Alfabeto[], char Estados[], char Estado_Final[], char Estado_Inicial, int Numero_Estados, int Numero_Alfabeto) {

    int i, Tamanho_Palavra;
    char Caracter, Caracter_Auxiliar;
    Tamanho_Palavra = strlen(Palavra);
    Caracter_Auxiliar = Estado_Inicial;
    system("cls");
    printf(" Caminho da Palavra %s  no Automato \n", Palavra);
    printf("%c -> ", Estado_Inicial);
    for (i = 0; i < Tamanho_Palavra; i++) {
        Caracter = Palavra[i];

        if (Pertence(Caracter, Alfabeto)) {
            Caracter_Auxiliar = Transicao(Delta, Caracter_Auxiliar, Caracter, Alfabeto, Estados, Numero_Estados, Numero_Alfabeto);
            printf("%c", Caracter_Auxiliar);

        } else {
            printf("Simbolo invalido");
            exit(1);
        }
        if (i != Tamanho_Palavra - 1) {
            printf("-> ");

        }
    }

    if (Pertence(Caracter_Auxiliar, Estado_Final)) {
        printf("\nSucesso, palavra aceita\n");
        printf("Pressione ENTER pra continuar\n");
        getchar();
    } else {
        printf("\nErro, palavra nao aceita\n");
        printf("Pressione ENTER pra continuar\n");
        getchar();
    }


}

/* Função Verificação */
char Transicao(char **Delta, char Caracter_Auxiliar, char Caracter, char Alfabeto[], char Estados[], int Numero_Estados, int Numero_Alfabeto) {
    int i, j;

    for (i = 0; i < Numero_Estados; i++) {
        if (Caracter_Auxiliar == Estados[i]) {
            break;
        }
    }

    for (j = 0; j < Numero_Alfabeto; j++) {
        if (Caracter == Alfabeto[j]) {
            break;
        }
    }

    return Delta[i][j];
}

/* Função Transição */
int Pertence(char Caracter, char *Conjunto) {
    int Tamanho_Conjunto = strlen(Conjunto);
    int i;

    for (i = 0; i < Tamanho_Conjunto; i++) {
        if (Caracter == Conjunto[i]) {
            return 1;
        }

    }
    return 0;
}

/* Função para Liberar Matriz */
char **Liberar_Matriz_Caracter(int Numero_Elementos, char **Ponteiro_Arquivo) {
    int i; /* variavel auxiliar */
    if (Ponteiro_Arquivo == NULL) return (NULL);
    if (Numero_Elementos < 1 || Numero_Elementos < 1) { /* verifica parametros recebidos */
        printf("** Erro: Parametro invalido **\n");
        return (Ponteiro_Arquivo);
    }
    for (i = 0; i < Numero_Elementos; i++) {
        free(Ponteiro_Arquivo[i]); /* libera as linhas da matriz */
        free(Ponteiro_Arquivo); /* libera a matriz * */
    }
    return (NULL); /* retorna um ponteiro nulo */
}

/* Função para Liberar Matriz */
float *Liberar_Vetor_Caracter(int Numero_Elementos, char *Ponteiro_Vetor) {
    if (Ponteiro_Vetor == NULL) return (NULL);
    if (Numero_Elementos < 1) { /* verifica parametros recebidos */
        printf("** Erro: Parametro invalido **\n");
        return (NULL);
    }
    free(Ponteiro_Vetor); /* libera o vetor */
    return (NULL); /* retorna o ponteiro */
}
