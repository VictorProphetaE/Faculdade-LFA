/**
Descrição: Este programa foi feito para verificar se um automato finito deterministico
funciona ou não baseando nos estados q(n) ou no alfabeto 0'1' para rodar


Nota: foi feito e compilado  no
GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)
caso de algum erro por problema de compilação

Metodo de funcionamento:
coloque a quantidade de estados 1 a 1000
a quantidade de estados finais de 1 a 1000

nos estados entre com q0 para o inicial até a q (n-1)

o alfabeto de 0' e 1'

e a entrada da string de 1101101

qualquer perguntar ao criador do programa

Nome: Victor Propheta Erbano
RGM: 021052
Matéria: LINGUAGENS FORMAIS E AUTOMATOS
Prof:Osvaldo Vargas Jaques
Data de Criação: 25/06/2014
Data Modificação: 06/08/2014
*/

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#define NOS 1000
using namespace std;

class Transition{
    public:
    string str;
    int cnt;
    string * list;

    /**uma função para indexar a string e armazená-lo na lista*/
    void strTokenize() {
        comma ();
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        char *p = strtok(cstr, ",");/** em strtok () primeiro parâmetro tem t0 ser um array de caracteres*/
        int i = 0;
        list = new string[cnt];
        /** tokenizar a corda e criar uma lista de estados para esse símbolo*/
        while (p != 0) {
            list[i] = p;
            i++;
            p = strtok(NULL, ",");
        }
    }

    void showList(){
        for (int i=0; i < cnt; i++)
            cout << list[i] << " ";
    }

    private:
    /** função para contar a vírgula (',') no conjunto dos estados inseridos*/
    void comma() {
        cnt = 1;
	size_t found = str.find(',');
        while (found != string::npos) {
            cnt++;
            found = str.find(',', found + 1);
    	}
     }

};

int main() {
    Transition **trans;
    string *states, *final, str, input, temp[NOS], current[NOS];
    char *alf;
    int nos, nofs, noa, i, j, k, x, y, z, f, flag, cnt, temp_last, curr_last;

    cout << " Entre com o numero total de estados "
    << "quantidade de estados finais :\n";
    cin >> nos >> nofs;
    states = new string[nos];
    final = new string[nofs];
    cout << "Entre com os estados(entre com estado inicial primeiro) \n";
    for (i = 0; i < nos; i++)
        cin >> states[i];
	cout << "Entre com o estado final\n";
    for (i = 0; i < nofs; i++)
        cin >> final[i];

    cout << "Digite o numero de simbolos do alfabeto: ";
    cin >> noa;
    alf = new char[noa];
    cout << "Entre os simbolos para o alfabeto:\n";
    for (i = 0; i < noa; i++)
        cin >> alf[i];

    /** alocação de espaço para a tabela de transição*/
    trans = new Transition*[nos];
    for (j = 0; j < nos; j++)
        trans[j] = new Transition[noa];

    /** recuperar as informações para a tabela de transição*/
    cout << "Digite as informacoes para a tabela de transicao"
         << " (digite t quando nenhum movimento é possivel a partir do estado dado) :\n";
    for (i = 0; i < nos; i++) {
	cout << "Escrever as transicoes para o estado " << states[i] << endl;
        for (j = 0; j < noa; j++){
       	    cout << "No simbolo de entrada " << alf[j] << ": ";
	    cin >> trans[i][j].str;
            trans[i][j].strTokenize();
	}
    }
    cout << endl << "tabela de transicao digitada pelo usuário e :\n";
    for (i = 0; i < nos; i++) {
        for (j = 0; j < noa; j++) {
            trans[i][j].showList();
            cout << "\t\t";
        }
        cout<<endl;
    }

    /** esta matriz de strings conterá os estados que estão sendo consideradas*/
    while (true) {
        cout << "\nDigite a s para parar o programa : ";
        cin >> input;
        if (input == "s")
            exit(0);

        curr_last = 0;
        current[curr_last] = states[0];/** inicializa o estado atual com o estado inicial*/
        for (i = 0; i < input.length(); i++){
        /** obtem o índice do símbolo do alfabeto*/
            for (j = 0; j < noa; j++)
                if (alf[j] == input[i])
                    break;



        /** Para obter o estado actual, número estados digitaliza [k]*/

            temp_last = 0;

	    for (k = 0; k <= curr_last; k++) { /**laço para digitalizar as transições de todos os estados atual*/
                if (current[k] == "t")
                    continue;
	        for (x = 0; x < nos; x++)
                    if (states[x] == current[k])
                        break;
                cnt = trans[x][j].cnt;
                for (y = 0; y < cnt; y++){/** interação da lista de transições*/
                    str = trans[x][j].list[y];
                    flag = 0;
                    for (z = 0; z < temp_last; z++){ /** verificar se o estado já está presente no temp[]*/
                        if (str == "t") {
                            flag = 1;
                            break;
                        }
                        if (temp[z] == str) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                        temp[temp_last++] = str;
                }
                /** atualiza current e curr_last*/

            }

            for (y = 0; y <= temp_last; y++)
                current[y] = temp[y];
            curr_last = temp_last - 1; /** como o último incremento não foi necessária*/
        }

        f = 0;
        /** loop de verificação de aceitação*/
        for (i = 0; i <= curr_last; i++) {
            for(j = 0; j < nofs; j++)
                if (final[j] == current[i]) {
                    cout<<"\n----A sequencia foi aceita----\n";
                    f = 1;
                    break;
                }
            if (f == 1) break;
        }

    if (f == 0)
        cout<<"\n----A sequencia foi rejeitada----\n";
}
return 0;
}
