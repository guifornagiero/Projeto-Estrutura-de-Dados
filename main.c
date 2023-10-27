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

ElementoLista *consultarPacienteCadastrado(Lista *lista, char *RG)
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

void mostrarListaCompleta(Lista *lista)
{
    ElementoLista *atual = lista->inicio;

    printf("\n-------------------------------------------------------\n");
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

        if (escolha == 1)
            cadastrarNovoPaciente(lista);

        if (escolha == 2)
        {
            limpaConsole();

            char RG[TAMANHO_RG];

            printf("Digite o RG do paciente: ");
            scanf("%s", RG);

            ElementoLista *paciente = consultarPacienteCadastrado(lista, RG);

            if (paciente != NULL)
            {
                printf("\n-PACIENTE ENCONTRADO-\n");
                printf("Nome: %s\n", paciente->dados.nome);
                printf("RG: %s\n\n", paciente->dados.RG);
            }
            else
            {
                printf("\nPaciente com RG %s nao encontrado.\n\n", RG);
            }
        }

        if (escolha == 3)
            mostrarListaCompleta(lista);

        if (escolha == 0)
            sair = 1;
    }
}

int main()
{
    int sair = 0;

    Lista *lista = iniciaLista();

    while (sair != 1)
    {
        int escolha = menuPrincipal();

        switch (escolha)
        {
        case 1:
            cadastro(lista);
            break;
        case 0:
            sair = 1;
            break;
        };
    }

    printf("\nObrigado por utilizar o aplicativo!!\n\n");

    return 0;
}