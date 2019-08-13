/** Descrição e read me :
    Funciona com char
    Programa para converter GLC para AP
    Primeiro entre com a quantidade de estados iniciais e qual letra ele é
    Segundo entre com a quantidade de estados terminais e suas letras
    Terceiro entre com a quantidade de producoes
    A -> BC (um não-terminal a dois não terminais) ou
    A -> a (um não-terminal a um terminal) ou
    S -> e (não-terminal começando a cadeia vazia).

*/
/**
Nome: Victor Propheta Erbano
RGM: 021052
Matéria: LINGUAGENS FORMAIS E AUTOMATOS
Prof:Osvaldo Vargas Jaques
*/

#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define TAM_MAX 10
#define TAM_DOBRO 25

using namespace std;

/**Entrada da GLC*/
glc::glc(void)
{
    int i,j,cont=0;
    cout<<"Entre com o numero de nao terminais ou Vn"<<endl;
    cin>>vno;
    for(i=0;i<vno;i++)
    {
        cout<<"Entre com os simbolos nao termiais ou simbolo inicial"<<endl;
        cin>>vec[i];
    }
    cout<<"Entre com o numero de terminais ou Vt"<<endl;
    cin>>tno;
    for(i=0;i<tno;i++)
    {
        cout<<"Entre com os simbolos terminais"<<endl;
        cin>>tam[i];
    }
    cout<<"Entre com o numero de producoes ou P"<<endl;
    cin>>n;
    for(i=0;i<vno;i++)
    {
        cout<<"Entre com o numero de produtos correspondentes ao nao terminais"<<endl;
        cin>>vpr[i];
        for(j=0;j<vpr[i];j++)
        {
            cout<<"Entre com o tipo de producao"<<endl;;
            cout<<"Ex: 1 A-->b ou 2 a-->BC"<<endl;
            cin>>p[cont].tipo;
            if(p[cont].tipo==1)
            {
                cout<<" "<<vec[i];
                cin>>p[cont].p.a;
            }
            else
            {
                cout<<" "<<vec[i];
                cin>>p[cont].p.b[0];
                cin>>p[cont].p.b[1];
            }
            cont++;
        }
    }
}

/**Impressão do resultado da conversão*/
void autom_pi::mostrar(void)
{
    int i,j;
    estado_ap p;
    system("cls");
    for(i=0;i<n;i++)
    {
        p=estados[i];
        cout<<"Numero de estados:"<<endl;
        cout<<i<<endl;
        if(p.tipo==0)
            cout<<"Estado inicial:\n"<<endl;
        else
            if(p.tipo==1)
                cout<<"Empilha:\n"<<endl;
        else
            if(p.tipo==2)
                cout<<"Desempilha Estado:\n"<<endl;
        else
            if(p.tipo==3)
                cout<<"Le estado:\n"<<endl;
        else
            if(p.tipo==4)
                cout<<"Estado de parada:\n"<<endl;
        for(j=0;j<p.transn;j++)
        {
            cout<<"Transicao de estado: "<<endl;
            cout<<p.transm[j]<<endl;
            if(p.transs[j]!=0)
            {
                cout<<"De simbolo: "<<endl;
                cout<<p.transs[j]<<endl;
            }
            else
                cout<<""<<endl;
        }
        getch();
        if(i==5)
            system("cls");
    }
}

/**Construtor do automato de pilha*/
autom_pi glc::construtor(void)
{
    int i,j;
    autom_pi pa;
    pa.estados[pa.n].tipo=0;
    pa.estados[pa.n].transn=1;
    pa.estados[pa.n].transm[0]=1;
    pa.estados[pa.n].transs[0]=0;
    pa.n++;
    pa.estados[pa.n].tipo=1;
    pa.estados[pa.n].simbolo=vec[0];
    pa.estados[pa.n].transn=1;
    pa.estados[pa.n].transm[0]=2;
    pa.estados[pa.n].transs[0]=0;
    pa.n++;
    pa.estados[pa.n].tipo=2;
    pa.estados[pa.n].transn=1;
    pa.estados[pa.n].transm[0]=3;
    pa.estados[pa.n].transs[0]=238;
    pa.n++;
    pa.estados[pa.n].tipo=3;
    pa.estados[pa.n].transn=1;
    pa.estados[pa.n].transm[0]=4;
    pa.estados[pa.n].transs[0]=238;
    pa.n++;
    pa.estados[pa.n].tipo=4;
    pa.estados[pa.n].transn=0;
    pa.n++;
    int contad=pa.estados[2].transn;
    int cont1=0;
    produc tempo;
    for(i=0;i<vno;i++)
    {
        for(j=0;j<vpr[i];j++)
        {
            tempo=p[cont1++];
            if(tempo.tipo==1)
            {
                pa.estados[2].transm[contad]=pa.n;
                pa.estados[2].transs[contad]=vec[i];
                pa.estados[pa.n].tipo=3;
                pa.estados[pa.n].transn=1;
                pa.estados[pa.n].transm[0]=2;
                pa.estados[pa.n].transs[0]=tempo.p.a;
                pa.n++;
                contad++;
            }
            else
            {
                pa.estados[2].transm[contad]=pa.n;
                pa.estados[2].transs[contad]=vec[i];
                pa.estados[pa.n].tipo=1;
                pa.estados[pa.n].simbolo=tempo.p.b[1];
                pa.estados[pa.n].transn=1;
                pa.estados[pa.n].transm[0]=(pa.n)+1;
                pa.estados[pa.n].transs[0]=0;
                pa.n++;
                contad++;
                pa.estados[pa.n].tipo=1;
                pa.estados[pa.n].simbolo=tempo.p.b[0];
                pa.estados[pa.n].transn=1;
                pa.estados[pa.n].transm[0]=2;
                pa.estados[pa.n].transs[0]=0;
                pa.n++;
            }
        }
        pa.estados[2].transn=contad;
    }

return(pa);
}

/**Menu principal e de repetição*/
int main()
{
    int option = 0;
    glc ca;/**ca=criação do automato*/
    autom_pi pa;/**pa= automato pilha*/
    pa=ca.construtor();
    getch();
    pa.mostrar();
    getch();
    {
        system("cls");
        cout<<" Deseja entrar com um novo glc"<<endl;
        cout<<" 1 - Sim "<<endl;
        cout<<" 2 - Nao"<<endl;
        cout<<"  Opcao:  "<<endl;
        cin>> option;
        switch (option)
        {
            case 1:
                main();
            break;
            case 2:
                system("cls");
            break;
            default:
                system("cls");
                cout<<"Opcao  invalida!"<<endl;
                system("pause");
            break;
        }
    }while(option  !=  2);

return 0;
}
