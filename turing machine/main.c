/**
Maquina de Turing
Nome: Victor Propheta Erbano
RGM: 021052
Matéria: Linguagens Formais e Autômatos
Prof:Osvaldo Vargas Jaques
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserT(char alf[50], char est[50], char func[50][50], char estin[3], char estfi[50], char simbIn[2],int *quant);
int Est_At_Conj_Fim(char estat[3], char estfi[50]);
void recon_palavra(char func[50][50], char estIn[3], char estFi[50], char simbIn[2], int *quant, char word[100]);


/**Função Main*/
int main()
{
    char alf[50],est[50],fun[50][50],estini[3],estfi[50],simbin[2];
    int quant=0,resp=0,resp2=0;
    char word[100];
    do{
    inserT (alf, est, fun, estini, estfi, simbin,&quant);
    do{
        printf("Entre com o alfabeto a ser testado: \n");
        scanf("%s", word);
        printf("\n");
        fflush(stdin);
        recon_palavra( fun, estini, estfi, simbin, &quant, word);
        system("cls");
        printf("Deseja tentar outro alfabeto\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d",&resp);
    }while(resp == 1);
        system("cls");
        printf("Deseja tentar outra maquina de turing\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d",&resp2);
    }while(resp2==1);
return 0;
}

/**Função para o usuário entrar com as palavras*/
void inserT(char alf[50], char est[50], char func[50][50], char estin[3], char estfi[50], char simbIn[2],int *quant)
{
    int i = 0;

    printf("\nInsira os simbolos do Alfabeto\n");
    printf("O caracter 'Q' ou 'q' representa branco de final da palavra\n");
    printf("FORMATO: a,b,c ou 0,1\n");
    scanf("%s", alf);
    fflush(stdin);
    system("cls");

    printf("\nEntre com conjunto de estados possiveis\n");
    printf("FORMATO: q0,q1,q2\n");
    scanf("%s", est);
    fflush(stdin);
    system("cls");

    printf("Entre com a quantidade de transicoes:\n");
    scanf("%d",&(*quant));
    for(i=0; i<*quant; i++)
    {
        printf("Entre com a transicao %d\n", i+1);
        printf("FORMATO: q0,a,A,D,q1 (Isso equivale a (q0,a)=(q1,A,D))\n");
        scanf("%s", func[i]);
        fflush(stdin);
        system("cls");
    }
    printf("Entre com o estado inicial:\n");
    scanf("%s", estin);
    fflush(stdin);
    system("cls");

    printf("Entre com o conjunto de estado final:\n");
    scanf("%s", estfi);
    fflush(stdin);
    system("cls");

    printf("Entre com o alfabeto de inicio onde nao pode ser igual a ao alfabeto utilizado\n");
    scanf("%s",simbIn);
    fflush(stdin);
    system("cls");

}

/**Função para fazer as trocas*/
int Est_At_Conj_Fim(char estat[3], char estfi[50])
{
    char aux[3];
    int i=0;
    int j=0;

    while(i<strlen(estfi))
    {
        i++;
        if(estfi[i]==',')
        {
            j=0;
            continue;
        }
    aux[j] = estfi[i];
    j++;
        if(j==2)
        {
        aux[2] = '\0';
            if(strcmp(estat,aux)==0)
                return 1;
        }
    }
    return 0;
}

/**Função para reconhecer as palavras e visualizar*/
void recon_palavra(char func[50][50], char estIn[3], char estFi[50], char simbIn[2],  int *quant, char word[100])
{
    int flag = 0;
    int i = 0;
    char wordaux[100];
    wordaux[0] = simbIn[0];
    char estatl[3];
    char estaaux[3];
    int j = 0;
    int flag3 = 0;

    for(i=0; i<49;i++)
        wordaux[i] = 'Q';
        wordaux[49] = '\0';
        wordaux[0] = simbIn[0];
    for(i=1; i<=strlen(word); i++)
    {
        wordaux[i] = word[j];
        j++;
    }
    j=1;


    printf("\n %s \n %s \n", wordaux, word);
    printf("\n");
    strcpy(estatl, estIn);

    while(Est_At_Conj_Fim(estatl, estFi)==0)
        {
            flag3 = 0;
            for(i=0; i<*quant; i++){
                estaaux[0] = func[i][0];
                estaaux[1] = func[i][1];
                estaaux[2] = '\0';
                if(strcmp(estatl, estaaux)==0){
                        printf("%c %c\n",wordaux[j], func[i][3]);
                        if(wordaux[j]==func[i][3]){
                            printf("entrou\n%c %c\n",wordaux[j], func[i][3]);
                            flag3 = 1;
                            wordaux[j] = func[i][5];
                            if(func[i][7]=='D'){
                                j++;
                            }
                            else{
                                j--;
                            }
                            estatl[0] = func[i][9];
                            estatl[1] = func[i][10];
                            estatl[2] = '\0';
                            if(j<0){
                                flag = 1;
                                break;
                            }
                            break;
                        }
                }
            }
            if(flag==1)
                break;
            if(flag3==0)
                break;
    }
    if(flag==1||flag3==0||(Est_At_Conj_Fim(estatl, estFi)==0))
    {
        printf("A palavra %s nao e reconhecida!\n", word);
    }
    else{
        if((Est_At_Conj_Fim(estatl, estFi)==1))
        {
            printf("A palavra %s e reconhecida\n", word);
        }
    }
}
