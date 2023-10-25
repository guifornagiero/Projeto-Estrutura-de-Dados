#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.c"

void limpaConsole()
{
    system("cls");
}

Lista *iniciaLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->quantidade = 0;

    return lista;
}

ElementoLista *iniciaElementoLista(Registro paciente)
{
    ElementoLista *novo = malloc(sizeof(ElementoLista));
    novo->dados = paciente;
    novo->proximo = NULL;

    return novo;
}

int menuPrincipal()
{
    printf("\nPROJETO - ESTRUTURA DE DADOS\n");
    printf("- Aplicativo de gerenciamento de servico de saude -\n\n");
    printf("Menu principal:\n");
    printf("1 - Cadastro\n");
    printf("2 - Atendimento\n");
    printf("3 - Pesquisa\n");
    printf("4 - Carregar / Salvar\n");
    printf("5 - Sobre\n\n");

    int escolha = 0;

    do
    {
        printf("Digite a opcao escolhida: ");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 5);

    return escolha;
}

void cadastrarNovoPaciente(Lista *lista, Registro paciente)
{
    ElementoLista *novo = iniciaElementoLista(paciente);

    if (lista->inicio == NULL)
        lista->inicio = novo;
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->quantidade++;
}

void mostrarListaCompleta(Lista *lista)
{
    ElementoLista *atual = lista->inicio;

    while (atual != NULL)
    {
        printf("\nNome -> %s\n", atual->dados.nome);
        printf("Idade -> %d\n", atual->dados.idade);
        printf("RG -> %s\n", atual->dados.RG);
        printf("Entrada -> %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        atual = atual->proximo;
    }
    printf("\nQuantidade -> %d", lista->quantidade);
}

void cadastro(Lista *lista)
{
    limpaConsole();

    printf("OPCAO 1 - CADASTRO\n\n");
    printf("1 - Cadastrar novo paciente\n");
    printf("2 - Consultar paciente cadastrado\n");
    printf("3 - Mostrar lista completa\n");
    printf("4 - Atualizar dados de paciente\n");
    printf("5 - Remover paciente\n\n");

    int escolha = 0;

    do
    {
        printf("Digite a opcao escolhida: ");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 5);

    if (escolha == 1)
    {
        char nome[TAMANHO_NOME];
        int idade;
        char RG[TAMANHO_RG];
        char entradaData[12];

        Registro novoPaciente;

        limpaConsole();

        printf("OPCAO 1 - CADASTRAR NOVO PACIENTE\n\n");
        printf("Nome: ");
        getchar();
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        strcpy(novoPaciente.nome, nome);

        printf("Idade: ");
        scanf("%d", &idade);
        novoPaciente.idade = idade;

        printf("RG: ");
        getchar();
        fgets(RG, sizeof(RG), stdin);
        RG[strcspn(RG, "\n")] = '\0';
        strcpy(novoPaciente.RG, RG);

        int dia, mes, ano;

        printf("Digite a data (dd/mm/AAAA): ");
        fgets(entradaData, sizeof(entradaData), stdin);

        sscanf(entradaData, "%d/%d/%d", &dia, &mes, &ano);

        novoPaciente.entrada.dia = dia;
        novoPaciente.entrada.mes = mes;
        novoPaciente.entrada.ano = ano;

        cadastrarNovoPaciente(lista, novoPaciente);

        strcpy(novoPaciente.nome, "aaaaa");
        cadastrarNovoPaciente(lista, novoPaciente);

        strcpy(novoPaciente.nome, "bbbbbbb");
        cadastrarNovoPaciente(lista, novoPaciente);

        mostrarListaCompleta(lista);
    }
}

int main()
{
    Lista *lista = iniciaLista();

    int escolha = menuPrincipal();

    switch (escolha)
    {
    case 1:
        cadastro(lista);
        break;
    }

    return 0;
}