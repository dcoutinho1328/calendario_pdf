#define inicio 0
#define TAM_MAX 500
#define MAX_DESC 30

typedef int Dia;
typedef int Mes;
typedef int Ano;
typedef char Tipo;

typedef struct
{
    Tipo t;
    Dia d;
    Mes m;
    Ano a;
    char Desc[MAX_DESC];
} Evento;
typedef struct Celula_str *Apontador;
typedef struct Celula_str
{
    Evento e;
    Apontador prox;
} Celula;
typedef struct
{
    Apontador Primeiro, Ultimo;
} TipoLista;

void cria_TAD_mensal(Mes mes, Ano ano, char aux[], int b, int idioma);

void GeraPDF(int m, int ano, TipoLista L, int idioma);

void pesquisa_eventos(int idioma, char aux[]);
