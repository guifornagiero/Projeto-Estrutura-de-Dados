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

ElementoLista *buscaPacientePorRG(Lista *lista, char *RG)
{
    ElementoLista *atual = lista->inicio;

    while (atual != NULL)
    {
        if (strcmp(atual->dados.RG, RG) == 0)
        {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

Fila *iniciaFila()
{
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->quantidade = 0;

    return fila;
}

ElementoFila *iniciaElementoFila(Registro paciente)
{
    ElementoFila *novo = malloc(sizeof(ElementoFila));
    novo->dados = paciente;
    novo->proximo = NULL;
    novo->anterior = NULL;

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
    printf("5 - Sobre\n");
    printf("0 - Sair\n\n");

    int escolha = 0;

    do
    {
        printf("Digite a opcao escolhida: ");
        scanf("%d", &escolha);
    } while (escolha < 0 || escolha > 6);

    return escolha;
}

#pragma region CADASTRO (OPCAO 1)

void cadastrarNovoPaciente(Lista *lista)
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

    printf("\nUsuario cadastrado -> RG %s\n\n", novoPaciente.RG);

    ElementoLista *novo = iniciaElementoLista(novoPaciente);

    if (lista->inicio == NULL)
        lista->inicio = novo;
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->quantidade++;
}

void consultarPacienteCadastrado(Lista *lista)
{
    limpaConsole();

    char RG[TAMANHO_RG];

    printf("Digite o RG do paciente: ");
    scanf("%s", RG);

    ElementoLista *paciente = buscaPacientePorRG(lista, RG);

    if (paciente != NULL)
    {
        printf("\n-PACIENTE ENCONTRADO-\n");
        printf("Nome: %s\n", paciente->dados.nome);
        printf("Idade -> %d\n", paciente->dados.idade);
        printf("RG: %s\n", paciente->dados.RG);
        printf("Entrada -> %d/%d/%d\n\n", paciente->dados.entrada.dia, paciente->dados.entrada.mes, paciente->dados.entrada.ano);
    }
    else
    {
        printf("\nPaciente com RG %s nao encontrado.\n\n", RG);
    }
}

void mostrarListaCompleta(Lista *lista)
{
    limpaConsole();

    ElementoLista *atual = lista->inicio;

    printf("LISTA COMPLETA DE PACIENTES CADASTRADOS NO SISTEMA\n");

    while (atual != NULL)
    {
        printf("\nNome -> %s\n", atual->dados.nome);
        printf("Idade -> %d\n", atual->dados.idade);
        printf("RG -> %s\n", atual->dados.RG);
        printf("Entrada -> %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        atual = atual->proximo;
    }
    printf("\nQuantidade -> %d\n", lista->quantidade);
    printf("-------------------------------------------------------\n\n");
}

void atualizarDadosPaciente(Lista *lista)
{
    limpaConsole();

    char RG[TAMANHO_RG];

    printf("Digite o RG do paciente: ");
    scanf("%s", RG);

    ElementoLista *paciente = buscaPacientePorRG(lista, RG);

    if (paciente == NULL)
        printf("\nPaciente com RG %s nao encontrado.\n\n", RG);
    else
    {
        printf("\n-PACIENTE ENCONTRADO-\n");
        printf("Nome: %s\n", paciente->dados.nome);
        printf("Idade -> %d\n", paciente->dados.idade);
        printf("RG: %s\n", paciente->dados.RG);
        printf("Entrada -> %d/%d/%d\n\n", paciente->dados.entrada.dia, paciente->dados.entrada.mes, paciente->dados.entrada.ano);

        char nome[TAMANHO_NOME];
        int idade;
        char RG[TAMANHO_RG];
        char entradaData[12];

        printf("ALTERE OS DADOS DO USUARIO:\n");

        printf("Nome: ");
        getchar();
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        strcpy(paciente->dados.nome, nome);

        printf("Idade: ");
        scanf("%d", &idade);
        paciente->dados.idade = idade;

        printf("RG: ");
        getchar();
        fgets(RG, sizeof(RG), stdin);
        RG[strcspn(RG, "\n")] = '\0';
        strcpy(paciente->dados.RG, RG);

        int dia, mes, ano;

        printf("Digite a data (dd/mm/AAAA): ");
        fgets(entradaData, sizeof(entradaData), stdin);

        sscanf(entradaData, "%d/%d/%d", &dia, &mes, &ano);

        paciente->dados.entrada.dia = dia;
        paciente->dados.entrada.mes = mes;
        paciente->dados.entrada.ano = ano;

        printf("\nUsuario alterado com sucesso!\n\n");
    }
}

void removerPaciente(Lista *lista)
{
    limpaConsole();

    char RG[TAMANHO_RG];

    printf("Digite o RG do paciente que deseja remover: ");
    scanf("%s", RG);

    ElementoLista *atual = lista->inicio;
    ElementoLista *anterior = NULL;

    while (atual != NULL && strcmp(atual->dados.RG, RG) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (anterior == NULL && atual->proximo == NULL)
            lista->inicio = NULL;
        else if (anterior == NULL && atual->proximo != NULL)
            lista->inicio = atual->proximo;
        else if (anterior != NULL && atual->proximo == NULL)
            anterior->proximo = NULL;
        else if (anterior != NULL && atual->proximo != NULL)
            anterior->proximo = atual->proximo;

        free(atual);
        lista->quantidade--;

        printf("\nPaciente com RG %s removido.\n\n", RG);
    }
    else
    {
        printf("\nPaciente com RG %s nao encontrado.\n\n", RG);
    }
}

void cadastro(Lista *lista)
{
    limpaConsole();

    int sair = 0;

    while (sair != 1)
    {
        printf("OPCAO 1 - CADASTRO\n\n");
        printf("1 - Cadastrar novo paciente\n");
        printf("2 - Consultar paciente cadastrado\n");
        printf("3 - Mostrar lista completa\n");
        printf("4 - Atualizar dados de paciente\n");
        printf("5 - Remover paciente\n");
        printf("0 - Sair de cadastro\n\n");

        int escolha = 0;

        do
        {
            printf("Digite a opcao escolhida: ");
            scanf("%d", &escolha);
        } while (escolha < 0 || escolha > 5);

        switch (escolha)
        {
        case 1:
            cadastrarNovoPaciente(lista);
            break;
        case 2:
            consultarPacienteCadastrado(lista);
            break;
        case 3:
            mostrarListaCompleta(lista);
            break;
        case 4:
            atualizarDadosPaciente(lista);
            break;
        case 5:
            removerPaciente(lista);
            break;
        case 0:
            sair = 1;
            break;
        default:
            break;
        }
    }
}

#pragma endregion

#pragma region ATENDIMENTO (OPCAO 2)

void enfileirarPaciente(Lista *lista, Fila *fila)
{
    limpaConsole();

    char RG[TAMANHO_RG];

    printf("OPCAO 1 - ENFILEIRAR PACIENTE\n\n");
    printf("Digite o RG do paciente: ");
    scanf("%s", RG);

    ElementoLista *paciente = buscaPacientePorRG(lista, RG);

    if (paciente != NULL)
    {
        ElementoFila *novoPaciente = iniciaElementoFila(paciente->dados);

        if (fila->quantidade == 0)
            fila->head = novoPaciente;
        else
        {
            fila->tail->proximo = novoPaciente;
            novoPaciente->anterior = fila->tail;
        }

        fila->tail = novoPaciente;
        fila->quantidade++;

        printf("\n- Paciente com RG %s entrou para a fila de atendimento! -\n\n", RG);
    }
    else
        printf("\nPaciente com RG %s nao encontrado.\n\n", RG);
}

void desenfileirarPaciente(Fila *fila)
{
    if (fila->quantidade != 0)
    {
        ElementoFila *paciente = fila->head;
        fila->head = paciente->proximo;
        fila->quantidade--;

        printf("\n- Paciente com RG %s atendido! -\n\n", paciente->dados.RG);

        free(paciente);
    }
    else
        printf("A fila de pacientes esta vazia. Nenhum paciente para ser atendido!\n\n");
}

void mostrarFila(Fila *fila)
{
    limpaConsole();

    printf("FILA DE PACIENTES COMPLETA\n\n");

    if (fila->quantidade != 0)
    {
        ElementoFila *atual = fila->head;

        while (atual != NULL)
        {
            printf("Nome: %s\n", atual->dados.nome);
            printf("RG: %s\n", atual->dados.RG);
            printf("Idade: %d\n\n", atual->dados.idade);

            atual = atual->proximo;
        }

        printf("Quantidade -> %d\n", fila->quantidade);
        printf("-------------------------------------------------------\n\n");
    }
    else
        printf("Fila de pacientes vazia!\n\n");
}

void atendimento(Lista *lista, Fila *fila)
{
    limpaConsole();

    int sair = 0;

    while (sair != 1)
    {
        printf("OPCAO 2 - ATENDIMENTO\n\n");
        printf("1 - Enfileirar paciente\n");
        printf("2 - Desenfileirar paciente\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair de atendimento\n\n");

        int escolha = 0;

        do
        {
            printf("Digite a opcao escolhida: ");
            scanf("%d", &escolha);
        } while (escolha < 0 || escolha > 3);

        switch (escolha)
        {
        case 1:
            enfileirarPaciente(lista, fila);
            break;
        case 2:
            desenfileirarPaciente(fila);
            break;
        case 3:
            mostrarFila(fila);
            break;
        case 0:
            sair = 1;
            break;
        }
    }
}

#pragma endregion

int main()
{
    int sair = 0;

    Lista *lista = iniciaLista();
    Fila *fila = iniciaFila();

    while (sair != 1)
    {
        limpaConsole();

        int escolha = menuPrincipal();

        switch (escolha)
        {
        case 1:
            cadastro(lista);
            break;
        case 2:
            atendimento(lista, fila);
            break;
        case 0:
            sair = 1;
            break;
        };
    }

    printf("\nObrigado por utilizar o aplicativo!!\n\n");

    return 0;
}