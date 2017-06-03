#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define TAM 50

int funcaoHash(int chave, char nome[50])
{
    int i;
    int hash = chave;
    for(i = 0; nome[i] != '\0'; i++)
    {
        ///A hash é a soma dos caracteres da tabela
        ///ASCII da palavracom um MOD do tamanho da tabela
        hash = hash + (int)nome[i];
    }
    hash = hash%TAM;
    return hash;
}

void insere(int chave, char nome[50], itemTabela* TabelaHash[TAM])
{
    ///Idx guarda o índice onde o elemento será inserido
    int idx = funcaoHash(chave, nome);

    ///ItemAux recebe a chave e o nome passados na função
    itemTabela* ItemAux = (itemTabela*)malloc(sizeof(itemTabela));
    ItemAux->ptr = NULL;
    itemTabela* ptrAux = NULL;
    ItemAux->chave = chave;
    strcpy(ItemAux->nome, nome);

    ///Se não ocorre uma colisão o elemento é inserido na tabela
    if(TabelaHash[idx] == NULL)
    {
        TabelaHash[idx] = ItemAux;
    }

    ///Se ocorre colisão
    else
    {
        ptrAux = TabelaHash[idx];

        ///Percorre a lista encadiada até o elemento não nulo
        while(ptrAux->ptr != NULL)
        {
            ptrAux = ptrAux->ptr;
        }
        ptrAux->ptr = ItemAux;
    }
}

void inicializaTabela(itemTabela* TabelaHash[TAM])
{
    int i;

    for(i = 0; i < TAM; i++)
        TabelaHash[i] = NULL;
}

int busca(int chave, char nome[50], itemTabela* TabelaHash[TAM])
{
    ///Idx guarda o índice da tabela hash
    int idx = funcaoHash(chave, nome);
    itemTabela *ptrAux = NULL;

    ///Se o índice for nulo o elemento não existe
    if(TabelaHash[idx] == NULL)
        return 0;

    ///Se encontrou o elemento
    if(TabelaHash[idx]->chave == chave)
    {
        return 1;
    }


    ptrAux = TabelaHash[idx];

    ///Navega a lista encadiada em busca do elemento
    while(ptrAux->ptr != NULL)
    {
        if(ptrAux->ptr->chave == chave)
            return 1;
        else
            ptrAux = ptrAux->ptr;
    }

    ///Se não encontrou o elemento retorna 0
    return 0;
}

void deleta(int chave, char nome[50], itemTabela* TabelaHash[TAM])
{
    ///Idx guarda o índice da tabela hash
    int idx = funcaoHash(chave, nome);
    itemTabela *ptrAux = NULL;
    itemTabela *ptrAux2 = NULL;

    ///Se o índice for nulo o elemento não existe
    if(TabelaHash[idx] == NULL)
        return;

    ///Se encontrou o elemento a ser deletado
    if(TabelaHash[idx]->chave == chave)
    {
        if(TabelaHash[idx]->ptr != NULL)
        {
            ptrAux = TabelaHash[idx]->ptr;
            TabelaHash[idx] = ptrAux;
        }
        else
            TabelaHash[idx] = NULL;
        return;
    }

    ptrAux = TabelaHash[idx]->ptr;
    ptrAux2 = TabelaHash[idx];

    if(ptrAux->chave == chave)
    {
        ptrAux2 = ptrAux->ptr;
        TabelaHash[idx]->ptr = ptrAux2;
    }

    ///Navega a lista encadiada em busca do elemento
    while(ptrAux->ptr != NULL)
    {
        if(ptrAux->ptr->chave == chave)
        {
            if(ptrAux->ptr->ptr != NULL)
            {
                ptrAux2 = ptrAux;
                ptrAux->ptr = ptrAux2->ptr->ptr;
            }
            else
                ptrAux->ptr = NULL;
            break;
        }
        else
        {
            ptrAux2 = ptrAux2->ptr;
            ptrAux = ptrAux->ptr;
        }
    }
}

void imprimeTabela(itemTabela *TabelaHash[TAM])
{
    int i;

    for(i = 0; i < TAM; i++)
    {
        itemTabela *ptrAux;

        printf("%d\t", i);

        if(TabelaHash[i] == NULL)
            printf("~\n");

        else
        {
            printf("%d  %s\t", TabelaHash[i]->chave, TabelaHash[i]->nome);
            ptrAux = TabelaHash[i]->ptr;
            while(ptrAux != NULL)
            {
                printf("-> %d  %s\t", ptrAux->chave, ptrAux->nome);
                ptrAux = ptrAux->ptr;
            }
            printf("\n");
        }
    }
}
