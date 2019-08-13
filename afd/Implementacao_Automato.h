
/****************************************************************************************************************/
/*                                IN�CIO DAS DECLARA��ES DOS PROT�TIPOS DAS FUN��ES                             */
/****************************************************************************************************************/

 /*****************************************************************************************************************
  Descri��o: Faz a leitura do numero de estados e alfabetos do Automato
  Par�metros de entrada:
   -> Vari�vel do tipo *int: Um ponteiro de inteiro para passagem por refer�ncia.
   -> Vari�vel do tipo *int: Um ponteiro de inteiro para passagem por refer�ncia.
  Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Valores_Automato( int *, int *);


 /*****************************************************************************************************************
  Descri��o: Aloca um Vetor de Caracteres
  Par�metros de entrada:
   -> Vari�vel do tipo int: O Numero de Elementos a ser alocados.
 Retorno da fun��o:
   -> Vari�vel do tipo char*: Um ponteiro apontando para o in�cio do vetor alocado.
 *****************************************************************************************************************/
char *Alocar_Vetor_Caracter( int );

/*****************************************************************************************************************
  Descri��o: Aloca uma matriz de Caracteres
  Par�metros de entrada:
   -> Vari�vel do tipo int: O Numero de Elementos a ser alocados.
 Retorno da fun��o:
   -> Vari�vel do tipo char*: Um ponteiro apontando para o in�cio da matriz alocado.
 *****************************************************************************************************************/
char **Alocar_Matriz_Caracter ( int Numero_Elementos);

/*****************************************************************************************************************
  Descri��o: Faz a leitura do alfabeto do Automato
  Par�metros de entrada:
   -> Vari�vel do tipo char []: Um vetor de caracteres.
 Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Alfabeto(char  []);


/*****************************************************************************************************************
  Descri��o: Faz a leitura dos estados do Automato
  Par�metros de entrada:
   -> Vari�vel do tipo char []: Um vetor de caracteres.
 Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Estados(char [], char [], char *);


/*****************************************************************************************************************
  Descri��o: Faz a leitura das transi��es no automato
  Par�metros de entrada:
   -> Vari�vel do tipo char **: Ponteiro para in�cio da matriz;
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo int: Numero de Estados do Automato
   -> Vari�vel do tipo int: N�mero de Caracteres do Alfabeto
 Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
void Leitura_Delta ( char ** , char [], char  [], int , int );


/*****************************************************************************************************************
  Descri��o: Elimina as v�rgulas de determinada string
  Par�metros de entrada:
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo int: N�mero de Elementos da String
 Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
void Eliminar_Virgulas ( char Cadeia [], int);

/*****************************************************************************************************************
  Descri��o: Fun��o que faz a verifica��o se determinada palavra pertence ao Automato
  Par�metros de entrada:
  -> Vari�vel do tipo char **: Ponteiro para in�cio da matriz;
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo int: Numero de Estados do Automato
   -> Vari�vel do tipo int: N�mero de Caracteres do Alfabeto
 Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
void Verifica_Palavra(char **, char [], char [], char [], char [], char , int , int );

/*****************************************************************************************************************
  Descri��o: Faz a leitura das transi��es no automato
  Par�metros de entrada:
   -> Vari�vel do tipo char **: Ponteiro para in�cio da matriz;
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo char []: Um vetor de caracteres
   -> Vari�vel do tipo int: Numero de Estados do Automato
   -> Vari�vel do tipo int: N�mero de Caracteres do Alfabeto
 Retorno da fun��o:
   -> Nenhum.
 *****************************************************************************************************************/
char Transicao(char **, char , char , char [], char [], int , int );

int Pertence(char , char *);



char **Liberar_Matriz_Caracter(int , char **);

float *Liberar_Vetor_Caracter(int , char  *);
