#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hash.h"


int main()
{
    int escolha = 0;
    int chave = 0;

    itemTabela *TabelaHash[TAM] = {};
    inicializaTabela(TabelaHash);
    while(escolha != 5)
    {
        char *nome = malloc(50*sizeof(char));
        printf("\t\t\t\t\t-------TABELA HASH-------\n");
        printf("[1] Inserir elemento\t[2] Buscar elemento\t[3] Deletar elemento\t[4] Imprime tabela\t [5] Sair\n>");
        scanf("%d", &escolha);
        switch(escolha)
        {
        case 1:
            printf("Indique a chave a ser inserida:\n(OBS: duas chaves nao podem ser iguais!)\n> ");
            scanf("%d", &chave);
            printf("Indique o nome da pessoa a ser inserida:\n> ");
            scanf("%s", nome);
            insere(chave, nome, TabelaHash);
            free(nome);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Indique a chave do elemento a ser buscado:\n> ");
            scanf("%d", &chave);
            printf("Indique o nome da pessoa a ser buscada:\n> ");
            scanf("%s", nome);
            escolha = busca(chave, nome, TabelaHash);
            if(escolha == 1)
                printf("A chave %d associada a pessoa %s esta presente na tabela\n", chave, nome);
            else
                printf("A chave %d associada a pessoa %s nao presente na tabela\n", chave, nome);
            free(nome);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Indique a chave a ser deletada:\n> ");
            scanf("%d", &chave);
            printf("Indique o nome da pessoa a ser deletada:\n> ");
            scanf("%s", nome);
            deleta(chave, nome, TabelaHash);
            free(nome);
            system("pause");
            system("cls");
            break;
        case 4:
            imprimeTabela(TabelaHash);
            system("pause");
            system("cls");
            break;
        case 5:
            break;
        default:
            printf("Comando invalido!\n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}
