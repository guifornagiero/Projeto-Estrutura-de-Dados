#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.c"

void limpaConsole()
{
    system("cls");
}

void menuPrincipal()
{
    printf("\nPROJETO - ESTRUTURA DE DADOS\n");
    printf("- Aplicativo de gerenciamento de servico de saude -\n\n");
    printf("Menu principal:\n");
    printf("1 - Cadastro\n");
    printf("2 - Atendimento\n");
    printf("3 - Pesquisa\n");
    printf("4 - Carregar / Salvar\n");
    printf("5 - Sobre\n\n");
}

void cadastro()
{
    limpaConsole();

    printf("\n\nOPCAO 1 - CADASTRO\n\n");
    printf("1 - Cadastrar novo paciente\n");
    printf("2 - Consultar paciente cadastrado\n");
    printf("3 - Mostrar lista completa\n");
    printf("4 - Atualizar dados de paciente\n");
    printf("5 - Remover paciente\n");
}

int main()
{
    int escolha = 1;
    menuPrincipal();

    do
    {
        printf("Digite a opcao escolhida: ");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 5);

    printf("escolha: %d", escolha);

    switch (escolha)
    {
    case 1:
        cadastro();
        break;
    }

    return 0;
}