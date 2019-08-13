/**
Nome: Victor Propheta Erbano
RGM: 021052
Profº: Osvaldo Vargas Jaques
Materia: Linguagens Formais e Autômatos
Nome do Algoritmo: Trabalho
**/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;//variaveis globais**/

char Alfa[20][20];
char **deelta;
char alfabeto[15], estados[15],palavra[30], f[15], a, q0, q;
char tamalfa, tamestados, tamf, tampalavra, p;
int i,j;

char transicao (char q, char a)/**essa funação vai faze com q anda dentro da matrix**/
{
    int i, j;

    for( i = 0; i < tamestados; i++)/**vai pega os estados**/
    {
        if( q == estados[i])
        {
            break;
        }
    }

    for( j = 0; j < tamalfa; j++)/**vai pega o alfabeto**/
    {
        if ( a == alfabeto[j])
        {
            break;
        }
    }

    return Alfa[i][j];/**vai retorna o estado e o alfabeto atual dentro da matrix**/
}

int pertence(char e, char *conj)/**ele verefica se as palavras q vc digito estão na matrix**/
{
    int tamconj = strlen (conj);
    int i;

    for( i = 0; i < tamconj; i++)
    {
        if( e == conj[i])
        {
            return 1;
        }

    }
    return 0;
}

int main()
{
    int sim,k;
    char opcao;
    opcao = 's';

    while(opcao == 's')
    {
        sim = 2;

        while( sim == 2)
        {
            fflush(stdin);
            cout << " Digite uma letra de a-z: ";
            gets (alfabeto);
            cout <<" Voce digitou as seguintes letra."<<alfabeto<<"\n\n Digite 1 para confirmar e 2 para entrar com novas letras.\n\n";
            cin >> sim;
        }

        system("cls");

        sim = 2;

        while( sim == 2)
        {
            fflush(stdin);
            cout << " Entre com os estados: ";
            gets (estados);
            cout << "\n Voce digitou o seguinte(s) Estado(s)"<<estados<<"\n\n Digite 1 para confirmar o estados informado ou 2 para entrar com novos estado.\n\n";
            cin >> sim;
        }

        system("cls");

        tamalfa = strlen(alfabeto); /**Verefica o tamanho do alfabeto**/
        tamestados = strlen(estados); /**Verefica o tamanho dos estados**/

        sim = 2;

        while(sim == 2)
        {
            fflush(stdin);
            cout << " Estado final: ";
            gets(f);
            cout << " Voce digitou o seguinte(s) Estado(s) Final\n"<<f<<"\n\n Digite 1 para confirmar e 2 para entrar com outro estado.\n\n";
            cin >> sim;
        }

        system("cls");

        tamf = strlen(f);

        sim = 2;

        while(sim == 2)
        {
            fflush(stdin);
            cout << " Estado inicial: ";
            cin >> q0;
            cout << " Voce digitou o seguinte(s) Estado(s) Inicial\n"<<f<<"\n\n Digite 1 para confirmar e 2 para entrar com outro estado.\n\n";
            cin >> sim;
        }

        system("cls");

        deelta = new char*[tamestados];

        for(k = 0; k < tamestados; k++)
        {
            deelta[k] = new char[tamalfa];

        }

        for(i = 0; i < tamestados; i++)/**Mostra onde está na Matrix**/
        {
            for(j = 0; j < tamalfa; j++)
            {
                cout << "Alfa: (" << estados[i] << " , "<< alfabeto[j] <<") =";
                cin >> Alfa[i][j];
            }
        }
        while(opcao== 's')
        {
            cout << "Palavra: ";
            fflush(stdin);
            gets(palavra);
            tampalavra = strlen(palavra);
            q = q0;

            for( p = 0; p < tampalavra; p++)
            {
                a = palavra[p];

                if ( pertence(a, alfabeto))/**Verefica se as palavras existem mandando para a função**/
                {
                    q = transicao(q, a);
                }
                else
                {
                    cout <<"Simbolo invalido";
                    exit(1);
                }
            }

            if(pertence (q , f))
            {
                cout << "Sucesso, palavra aceita"<<endl;
            }
            else
            {
                cout << "Erro, palavra naum aceita "<<endl;
            }

            cout<<"Deseja entrar com uma nova palavra \n s-sim \n n-nao \n";
            cin>>opcao;
        }
        system("cls");

        cout<<"Deseja entrar com um novo AFD \n s-sim \n n-nao \n";
        cin>>opcao;

        system("cls");
        for( k = 0; k < tamestados; k++)
        {
            delete(Alfa [k] );

            if(Alfa[k] == 0)
            {
                cout<<"OK";
            }
        }
    }
}
