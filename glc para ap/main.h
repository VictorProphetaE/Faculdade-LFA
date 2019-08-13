/**
Biblioteca das estruturas, classes e union usado na main

*/
#ifndef __main_h__
#define __main_h__

#define TAM_MAX 10
#define TAM_DOBRO 25

struct estado_ap;
class autom_pi;

/**Declaração da estrutura da AP*/
struct estado_ap
{
    int tipo;
    char simbolo;
    int transn;
    int transm[TAM_DOBRO];
    char transs[TAM_DOBRO];
};

/**Declaração classe da AP*/
class autom_pi
{
    public:
        int n;
        estado_ap estados[TAM_DOBRO];
    autom_pi(void)
    {
        n=0;/**Zerando a AP*/
    }
    void mostrar(void);
};

union prod;

/**Declaração do union para segurar a produção*/
union prod
{
    char a;
    char b[2];
};

struct produc;

/**Estrutura da produção*/
struct produc
{
    int tipo;
    union prod p;
};

class glc;

/**Classe para a glc*/
class glc
{
    private:
        char vec[TAM_MAX],tam[TAM_MAX];
        int vno,tno,n,vpr[TAM_MAX];
        struct produc p[TAM_MAX];
    public:
        glc(void);
        autom_pi construtor(void);
};

#endif
