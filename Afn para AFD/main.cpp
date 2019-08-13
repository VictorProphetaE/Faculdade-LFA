/** Descrição e read me :
    Funciona com char o com numero, na impressão somente char
    Programa para converter AFN para AFD

    N -> N º de estados (estados são numerados 0 ... N-1), 0 é o estado inicial
    M -> Tamanho de entrada alfabeto
    F -> No. de estados finais, seguido por F estados ( 0 <= ai <= N-1)
    a1 a2 ... af
    T -> Número de transições, seguido por linhas T
    Ex: n transicoes = n-1
    s1 -> estado anterior( 0 <= si <= N-1)
    y1  -> Símbolo de entrada ou epsilon ( 0 <= yi <= M)
    T1 -> N º de membros da AFN se move de si em yi entrada, seguido por Ti estados
    t1 t2 ... tt1
    s1 y1 T1 t1 t2 ... tt1
    s2 y2 T2 t1 t2 ... tt2
    :
    :
*/
/**
Nome: Victor Propheta Erbano
RGM: 021052
Matéria: LINGUAGENS FORMAIS E AUTOMATOS
Prof:Osvaldo Vargas Jaques
*/
#include <cstdio>
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
#include <stdlib.h>
#define TAM_MAX 10

using namespace std;

/** Representação de um estado AFN*/
class estado_AFN {
    public:
        int transicao[TAM_MAX][TAM_MAX];
        estado_AFN()  {
            for(int i=0; i<TAM_MAX; i++)
                for(int j=0; j<TAM_MAX; j++)
                    transicao[i][j] = -1;
        }
} *estados_AFN;

/** Representação de um estado AFD*/
struct estado_AFD {
    bool estados_final;
    bitset<TAM_MAX> constituente_estados_AFN;
    bitset<TAM_MAX> transicao[TAM_MAX];
    int transicao_simbolica[TAM_MAX];
};

set <int> AFN_estados_finais;
vector <int> AFD_estados_finaias;
vector <estado_AFD*> estados_AFD;
queue <int> incompleteestados_AFD;
int N, M;   /** N -> N º de estados, M -> Tamanho do alfabeto de entrada*/

/** encontra o fechamento epsilon do Estado "estado" AFN e armazena-la em "fechamento"*/
void epsilonClosure(int state, bitset<TAM_MAX> &closure )    {
    for(int i=0; i<N && estados_AFN[state].transicao[0][i] != -1; i++)
        if(closure[estados_AFN[state].transicao[0][i]] == 0)    {
            closure[estados_AFN[state].transicao[0][i]] = 1;
            epsilonClosure(estados_AFN[state].transicao[0][i], closure);
        }
}

/** encontra o fechamento epsilon de um conjunto de AFN declara "estado" e armazena-la em "fechamento"*/
void epsilonClosure(bitset<TAM_MAX> state, bitset<TAM_MAX> &closure) {
    for(int i=0; i<N; i++)
        if(state[i] == 1)
            epsilonClosure(i, closure);
}

/** retorna um bitset que representa o conjunto de estados do AFN poderia estar em depois de se mudar*/
/** de estado X na entrada símbolo A*/
void AFN_movimento(int X, int A, bitset<TAM_MAX> &Y)   {
    for(int i=0; i<N && estados_AFN[X].transicao[A][i] != -1; i++)
        Y[estados_AFN[X].transicao[A][i]] = 1;
}

/** retorna um bitset que representa o conjunto de estados do AFN poderia estar em depois de se mudar*/
/** do conjunto de estados X na entrada símbolo A*/
void AFN_movimento(bitset<TAM_MAX> X, int A, bitset<TAM_MAX> &Y)   {
    for(int i=0; i<N; i++)
        if(X[i] == 1)
            AFN_movimento(i, A, Y);
}

/**Zera os vetores e o set*/
void limpeza()
{
    AFD_estados_finaias.clear();
    AFN_estados_finais.clear();
    estados_AFD.clear();
}

/**Zera o queue*/
void clear( std::queue<int> &incompleteestados_AFD )
{
   std::queue<int> empty;
   std::swap( incompleteestados_AFD, empty );
}

/**Escreve o AFD correspondente contando o estado sumidouro*/
void impressao(int D,int M,int j)
{
    int i=0;
    cout<<endl;
    cout<<"AFD"<<endl;
    cout<<"Numero de estados"<<" "<<"Alfabeto "<<endl;
    cout<< " " << D << " " << M << "\n" << AFD_estados_finaias.size();
    cout<<"\n"<<"Qntida de estados finais"<<endl;
    for(vector<int>::iterator it=AFD_estados_finaias.begin(); it!=AFD_estados_finaias.end(); it++)
        cout << " " << *it;
    cout << "\n";
    cout<<"Estados e suas transicoes"<<endl;
    for(i=0; i<D; i++)
    {
        for(j=1; j<=M; j++)
        {
            if(j=1)
            {
                cout << " " <<"Q"<< i << " " << "a" << " "<<"Q"<< estados_AFD[i]->transicao_simbolica[j] << "\n";
            }
            if(j=2)
            {
                cout << " " <<"Q"<< i << " " << "b" << " "<<"Q"<< estados_AFD[i]->transicao_simbolica[j] << "\n";
            }
        }
    }
    system("pause");
}

int principal()
{
    int i=0, j, X, Y, A, T, F, D;
    char aux;

    i=0; j=0; X=0; Y=0; A=0; T=0; F=0; D=0;
    /** leitura do AFN*/
    cout<<"Entre com a quantidade de estados"<<endl;
    cin>>N;
    cout<<"Entre com a quantidade de alfabeto"<<endl;
    cin>>M;
    estados_AFN = new estado_AFN[N];
    cout<<"Entre com a qunatidade de estados finais"<<endl;
    cin>>F;
    cout<<"Entre com os estados finais"<<endl;/**Dar espaço entre eles para funcionar ou enter*/
    for(i=0; i<F; i++)
    {
        cin>>X;
        AFN_estados_finais.insert(X);
    }
    cout<<"Entre com a quantidade de transicoes"<<endl;
    cin>> T;
    cout<<"Entre com o estado \n alfabeto: 0 = epsi, 1 = a, 2 = b \n quantidade de transicoes \n suas transicoes"<<endl;/**Dar espaço entre eles para funcionar ou enter*/
    while(T--)
        {
        cin>>X>>aux>>Y;
        switch(aux)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                for(i=0; i<Y; i++)
                {
                    A = aux-'0';
                    cin>>j;
                    estados_AFN[X].transicao[A][i] = j;
                    cout<< " "<<"Q"<<X<<" "<<aux<<" "<<Y<<" "<<"Q"<<estados_AFN[X].transicao[A][i]<<endl;
                }
            break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
                for(i=0; i<Y; i++)
                {
                    A = (aux-'0')-48;
                    cin>>j;
                    estados_AFN[X].transicao[A][i] = j;
                    cout<< " "<<"Q"<<X<<" "<<aux<<" "<<Y<<" "<<"Q"<<estados_AFN[X].transicao[A][i]<<endl;
                }
            break;
        }
    }

    /**Construção do AFD correspondente*/
    D = 1;
    estados_AFD.push_back(new estado_AFD);
    estados_AFD[0]->constituente_estados_AFN[0] = 1;
    epsilonClosure(0, estados_AFD[0]->constituente_estados_AFN);
    for(j=0; j<N; j++)
        if(estados_AFD[0]->constituente_estados_AFN[j] == 1 && AFN_estados_finais.find(j) != AFN_estados_finais.end())  {
            estados_AFD[0]->estados_final = true; AFD_estados_finaias.push_back(0); break;
        }
    incompleteestados_AFD.push(0);
    while(!incompleteestados_AFD.empty()) {
        X = incompleteestados_AFD.front(); incompleteestados_AFD.pop();
        for(i=1; i<=M; i++)  {
            AFN_movimento(estados_AFD[X]->constituente_estados_AFN, i, estados_AFD[X]->transicao[i]);
            epsilonClosure(estados_AFD[X]->transicao[i], estados_AFD[X]->transicao[i]);
            for(j=0; j<D; j++)
                if(estados_AFD[X]->transicao[i] == estados_AFD[j]->constituente_estados_AFN)  {
                   estados_AFD[X]->transicao_simbolica[i] = j;    break;
                }
            if(j == D)   {
                estados_AFD[X]->transicao_simbolica[i] = D;
                estados_AFD.push_back(new estado_AFD);
                estados_AFD[D]->constituente_estados_AFN = estados_AFD[X]->transicao[i];
                for(j=0; j<N; j++)
                    if(estados_AFD[D]->constituente_estados_AFN[j] == 1 && AFN_estados_finais.find(j) != AFN_estados_finais.end())  {
                        estados_AFD[D]->estados_final = true; AFD_estados_finaias.push_back(D); break;
                    }
                incompleteestados_AFD.push(D);
                D++;
            }
        }
    }
    impressao(D,M,j);

    return 0;
}

int main()
{
    int option;

    do{
    principal();
    /**Escreve o AFD correspondente*/
    limpeza();
    system("cls");
    cout<<"************************"<<endl;
    cout<<"Deseja entrar com um novo AFN"<<endl;
    cout<<"1- Sim"<<endl;
    cout<<"2- Nao"<<endl;
    cout<<"************************"<<endl;
    cin>>option;
    system("cls");
    }while(option!=2);
}
