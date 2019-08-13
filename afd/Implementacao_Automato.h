
/****************************************************************************************************************/
/*                                INÍCIO DAS DECLARAÇÕES DOS PROTÓTIPOS DAS FUNÇÕES                             */
/****************************************************************************************************************/

 /*****************************************************************************************************************
  Descrição: Faz a leitura do numero de estados e alfabetos do Automato
  Parâmetros de entrada:
   -> Variável do tipo *int: Um ponteiro de inteiro para passagem por referência.
   -> Variável do tipo *int: Um ponteiro de inteiro para passagem por referência.
  Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Valores_Automato( int *, int *);


 /*****************************************************************************************************************
  Descrição: Aloca um Vetor de Caracteres
  Parâmetros de entrada:
   -> Variável do tipo int: O Numero de Elementos a ser alocados.
 Retorno da função:
   -> Variável do tipo char*: Um ponteiro apontando para o início do vetor alocado.
 *****************************************************************************************************************/
char *Alocar_Vetor_Caracter( int );

/*****************************************************************************************************************
  Descrição: Aloca uma matriz de Caracteres
  Parâmetros de entrada:
   -> Variável do tipo int: O Numero de Elementos a ser alocados.
 Retorno da função:
   -> Variável do tipo char*: Um ponteiro apontando para o início da matriz alocado.
 *****************************************************************************************************************/
char **Alocar_Matriz_Caracter ( int Numero_Elementos);

/*****************************************************************************************************************
  Descrição: Faz a leitura do alfabeto do Automato
  Parâmetros de entrada:
   -> Variável do tipo char []: Um vetor de caracteres.
 Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Alfabeto(char  []);


/*****************************************************************************************************************
  Descrição: Faz a leitura dos estados do Automato
  Parâmetros de entrada:
   -> Variável do tipo char []: Um vetor de caracteres.
 Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Estados(char [], char [], char *);


/*****************************************************************************************************************
  Descrição: Faz a leitura das transiçôes no automato
  Parâmetros de entrada:
   -> Variável do tipo char **: Ponteiro para início da matriz;
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo int: Numero de Estados do Automato
   -> Variável do tipo int: Número de Caracteres do Alfabeto
 Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Delta ( char ** , char [], char  [], int , int );


/*****************************************************************************************************************
  Descrição: Elimina as vírgulas de determinada string
  Parâmetros de entrada:
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo int: Número de Elementos da String
 Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
void Eliminar_Virgulas ( char Cadeia [], int);

/*****************************************************************************************************************
  Descrição: Função que faz a verificação se determinada palavra pertence ao Automato
  Parâmetros de entrada:
  -> Variável do tipo char **: Ponteiro para início da matriz;
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo int: Numero de Estados do Automato
   -> Variável do tipo int: Número de Caracteres do Alfabeto
 Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
void Verifica_Palavra(char **, char [], char [], char [], char [], char , int , int );

/*****************************************************************************************************************
  Descrição: Faz a leitura das transiçôes no automato
  Parâmetros de entrada:
   -> Variável do tipo char **: Ponteiro para início da matriz;
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo char []: Um vetor de caracteres
   -> Variável do tipo int: Numero de Estados do Automato
   -> Variável do tipo int: Número de Caracteres do Alfabeto
 Retorno da função:
   -> Nenhum.
 *****************************************************************************************************************/
char Transicao(char **, char , char , char [], char [], int , int );

int Pertence(char , char *);



char **Liberar_Matriz_Caracter(int , char **);

float *Liberar_Vetor_Caracter(int , char  *);
