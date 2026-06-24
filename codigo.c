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

void listar(Contato vet[], int total) {
    if (total == 0) {
        printf("\nA agenda esta vazia. Nenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE CONTATOS CADASTRADOS (%d/%d) ---\n", total, MAX_CONTATOS);
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("#%d - Nome: %s\n", i + 1, vet[i].nome);
        printf("     Telefone: %s | E-mail: %s\n", vet[i].telefone, vet[i].email);
        printf("     Tipo: %s\n", vet[i].tipo);
        printf("-------------------------------------------------------------------\n");
    }
}

void procurar(Contato vet[], int total) {
    if (total == 0) {
        printf("\nNenhum contato cadastrado para busca.\n");
        return;
    }

    char nomeBusca[50];
    int encontrado = 0;

    printf("\n--- PROCURAR CONTATO ---\n");
    printf("Digite o nome (ou parte dele) para buscar: ");
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    printf("\nResultados encontrados:\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        if (strstr(vet[i].nome, nomeBusca) != NULL) {
            printf("Nome: %s | Tel: %s | E-mail: %s | Tipo: %s\n", 
                   vet[i].nome, vet[i].telefone, vet[i].email, vet[i].tipo);
            encontrado = 1;
        }
    }
    printf("-------------------------------------------------------------------\n");

    if (!encontrado) {
        printf("[AVISO] Nenhum contato corresponde a pesquisa.\n");
    }
}

void alterar(Contato vet[], int total) {
    if (total == 0) {
        printf("\nNenhum contato cadastrado para alterar.\n");
        return;
    }

    char nomeBusca[50];
    int encontrado = 0;

    printf("\n--- ALTERAR CONTATO ---\n");
    printf("Digite o nome exato do contato que deseja alterar: ");
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(vet[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("\nContato encontrado! Insira os novos dados:\n");

            printf("Novo Nome: ");
            fgets(vet[i].nome, 50, stdin);
            vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0';

            printf("Novo E-mail: ");
            fgets(vet[i].email, 50, stdin);
            vet[i].email[strcspn(vet[i].email, "\n")] = '\0';

            printf("Novo Telefone: ");
            fgets(vet[i].telefone, 20, stdin);
            vet[i].telefone[strcspn(vet[i].telefone, "\n")] = '\0';

            printf("Novo Tipo: ");
            fgets(vet[i].tipo, 20, stdin);
            vet[i].tipo[strcspn(vet[i].tipo, "\n")] = '\0';

            printf("\n[SUCESSO] Contato atualizado com sucesso!\n");
            break; 
        }
    }

    if (!encontrado) {
        printf("\n[AVISO] Contato '%s' nao encontrado.\n", nomeBusca);
    }
}

void apagar(Contato vet[], int *total) {
    if (*total == 0) {
        printf("\nNenhum contato cadastrado para remover.\n");
        return;
    }

    char nomeBusca[50];
    int encontrado = 0;

    printf("\n--- APAGAR CONTATO ---\n");
    printf("Digite o nome exato do contato que deseja remover: ");
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < *total; i++) {
        if (strcmp(vet[i].nome, nomeBusca) == 0) {
            encontrado = 1;

            for (int j = i; j < (*total) - 1; j++) {
                vet[j] = vet[j + 1];
            }

            (*total)--;
            printf("\n[SUCESSO] Contato removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\n[AVISO] Contato '%s' nao encontrado.\n", nomeBusca);
    }
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
                alterar(contatos, totalContatos);
                system("pause");
                break;
            case 3:
                apagar(contatos, &totalContatos);
                system("pause");
                break;
            case 4:
                procurar(contatos, totalContatos);
                system("pause");
                break;
            case 5:
                listar(contatos, totalContatos);
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
