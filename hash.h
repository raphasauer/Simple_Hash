#ifndef _HASH_H_
#define _HASH_H_
#define TAM 50

typedef struct itemTabela
{
    ///Dado armazenado
    char nome[50];
    ///Chave do dado
    int chave;
    ///Em caso de colisão esse ponteiro
    ///aponta pro próximo item nesse índice
    struct itemTabela* ptr;
}itemTabela;

///Gera o índice do elemento na tabela hash
int funcaoHash(int chave, char nome[50]);

///Busca o índice na tabela hash
int busca(int chave, char nome[50], itemTabela* TabelaHash[TAM]);

///Insere o elemento na tabela hash
void insere(int chave, char nome[50], itemTabela* TabelaHash[TAM]);

///Exclui um elemento da tabela hash
void deleta(int chave, char nome[50], itemTabela* TabelaHash[TAM]);

///Inicializa setando tudo com NULL
void inicializaTabela(itemTabela* TabelaHash[TAM]);

///Imprime a tabela na tela
void imprimeTabela(itemTabela *TabelaHash[TAM]);

#endif // _HASH_H_
