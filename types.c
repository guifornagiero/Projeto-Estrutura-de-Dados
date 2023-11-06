#define TAMANHO_NOME 100
#define TAMANHO_RG 15

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Registro
{
    char nome[TAMANHO_NOME];
    int idade;
    char RG[TAMANHO_RG];
    Data entrada;
} Registro;

typedef struct ElementoLista
{
    Registro dados;
    struct ElementoLista *proximo;
} ElementoLista;

typedef struct Lista
{
    ElementoLista *inicio;
    int quantidade;
} Lista;

typedef struct ElementoFila
{
    Registro dados;
    struct ElementoFila *proximo;
    struct ElementoFila *anterior;
} ElementoFila;

typedef struct Fila
{
    ElementoFila *head;
    ElementoFila *tail;
    int quantidade;
} Fila;

typedef struct ElementoArvoreBinaria
{
    Registro dados;
    struct ElementoArvoreBinaria *filho_esquerdo;
    struct ElementoArvoreBinaria *filho_direito;
} ElementoArvoreBinaria;

typedef struct ArvoreBinaria
{
    ElementoArvoreBinaria raiz;
    int quantidade;
} ArvoreBinaria;