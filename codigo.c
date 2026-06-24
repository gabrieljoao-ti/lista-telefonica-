#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 150
#define ARQUIVO_DADOS "contatos.dat"

typedef struct {
    char nome[50];
    char email[50];
    char telefone[20];
    char tipo[20];
} Contato;

// A função cadastrar fica aqui em cima da main
void cadastrar(Contato vet[], int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("\n[ERRO] Memoria cheia! Nao e possivel cadastrar novos contatos.\n");
        return;
    }

    printf("\n--- CADASTRAR NOVO CONTATO ---\n");

    printf("Nome: ");
    fgets(vet[*total].nome, 50, stdin);
    vet[*total].nome[strcspn(vet[*total].nome, "\n")] = '\0';

    printf("E-mail: ");
    fgets(vet[*total].email, 50, stdin);
    vet[*total].email[strcspn(vet[*total].email, "\n")] = '\0';

    printf("Telefone: ");
    fgets(vet[*total].telefone, 20, stdin);
    vet[*total].telefone[strcspn(vet[*total].telefone, "\n")] = '\0';

    printf("Tipo (Pessoal, Trabalho, Familia, Cliente, Outro): ");
    fgets(vet[*total].tipo, 20, stdin);
    vet[*total].tipo[strcspn(vet[*total].tipo, "\n")] = '\0';

    (*total)++;
    printf("\n[SUCESSO] Contato cadastrado com sucesso!\n");
}

int main() {
    Contato contatos[MAX_CONTATOS];
    int totalContatos = 0;
    int opcao;

    do {
        system("cls");
        printf("=========================================\n");
        printf("      SISTEMA DE GERENCIAMENTO DE CONTATOS\n");
        printf("=========================================\n");
        printf("1. Cadastrar contato\n");
        printf("2. Alterar contato\n");
        printf("3. Apagar contato\n");
        printf("4. Procurar contato\n");
        printf("5. Listar contatos\n");
        printf("6. Sair\n");
        printf("=========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                cadastrar(contatos, &totalContatos);
                system("pause");
                break;
            case 2:
                printf("\n[Opcao 2: Alterar - Em breve]\n");
                system("pause");
                break;
            case 3:
                printf("\n[Opcao 3: Apagar - Em breve]\n");
                system("pause");
                break;
            case 4:
                printf("\n[Opcao 4: Procurar - Em breve]\n");
                system("pause");
                break;
            case 5:
                printf("\n[Opcao 5: Listar - Em breve]\n");
                system("pause");
                break;
            case 6:
                printf("\nSaindo do sistema... Ate logo!\n");
                system("pause");
                break;
            default:
                printf("\nOpcao invalida! Tente um numero de 1 a 6.\n");
                system("pause");
        }

    } while(opcao != 6);

    return 0;
}
