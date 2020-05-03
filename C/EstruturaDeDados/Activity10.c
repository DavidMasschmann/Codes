/*
Ajuste o exemplo apresentado para que a lista trabalhe com um
cadastro de clientes que contenha o nome, telefone, email e cidade.

Para isto modifique o tipo TDADOS e as seguites fuções:

    int Inclui_Esquerda (TDESCRITOR *d, TDADOS dado);
    int Inclui_Direita (TDESCRITOR *d, TDADOS dado);
    int Consulta_Ultimo(TDESCRITOR d,TDADOS *dado);
    void Imprime_Lista(TDESCRITOR d);
*/

// Lista Encadeada com Descritor

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

// ------------------------------------ Definições
#define SUCESSO 0
#define FALTA_DE_MEMORIA 1
#define LISTA_VAZIA 2

// ------------------------------------ Tipos de Dados
typedef struct dados {
    char nome[30];
    char email[50];
    char cidade[25];
    int telefone[11];
} TDADOS;

typedef struct nodo {
    TDADOS dado;
    struct nodo *elo;
    } TNODO;

//--------------------------------- Descritor
typedef struct {
    TNODO *primeiro;
    int n;
    TNODO *ultimo;
    } TDESCRITOR;

// ------------------------------------ Prototypes
void Cria_Lista (TDESCRITOR *d);
int Inclui_Esquerda (TDESCRITOR *d, TDADOS dado);
int Inclui_Direita (TDESCRITOR *d, TDADOS dado);
int Consulta_Ultimo (TDESCRITOR d,TDADOS *dado);
void Imprime_Lista (TDESCRITOR d);
void Imprime_Erro (int erro);

// ------------------------------------ Programa Principal
int main() {
    TDESCRITOR d;
    TDADOS* dado;
    char tecla;
    int erro;

    Cria_Lista(&d);
    do {
        Imprime_Lista(d);
        printf("\nNome: ");
        gets(dado -> nome);
        printf("\nEmail: ");
        gets(dado -> email);
        printf("\nCidade: ");
        gets(dado -> cidade);
        printf("\nTelefone: ");
        scanf("%i", &dado -> telefone);

        if (dado != 0) {
            printf("[E]squerda ou [D]ireita: ");

            do {
                tecla = toupper(getchar());
            } while (!strchr("ED", tecla));

            switch (tecla) {
                case 'E':
                    erro = Inclui_Esquerda(&d, dado);
                    break;
                case 'D':
                    erro = Inclui_Direita(&d, dado);
                    break;
            }

            if (erro) {
                Imprime_Erro(erro);
                break;
            }
        }
    } while (dado != 0);

    erro = Consulta_Ultimo(d, &dado);

    if (erro == SUCESSO) {
        printf("Ultimo Elemento: %d\n", dado);
    } else {
        Imprime_Erro(erro);
    }

    getche();
}

// ------------------------------------ Cria_Lista
void Cria_Lista (TDESCRITOR *l) {
    l -> primeiro = NULL;
    l -> n = 0;
    l -> ultimo = NULL;
}

// ------------------------------------ Inclui_Esquerda
int Inclui_Esquerda (TDESCRITOR *d, TDADOS dado) {
    TNODO *p;

    p = (TNODO *) malloc(sizeof(TNODO));

    if (p == NULL) {
        return(FALTA_DE_MEMORIA);
    } else {
        p -> dado = dado;
        p -> elo = d -> primeiro;
        d -> primeiro = p;

        if (d -> n == 0) {
            d -> ultimo = p;
        }

        (d -> n)++;

        return(SUCESSO);
    }
}

// ------------------------------------ Inclui_Direita
int Inclui_Direita (TDESCRITOR *d, TDADOS dado) {
    TNODO *p;

    p = (TNODO *) malloc(sizeof(TNODO));

    if (p == NULL) {
        return(FALTA_DE_MEMORIA);
    }
    else {
        p -> dado = dado;
        p -> elo = NULL;

        if (d -> n == 0) {
            d -> primeiro = p;
        } else {
            d -> ultimo -> elo = p;
        }

        d -> ultimo = p;
        (d -> n)++;

        return(SUCESSO);
    }
}

// ------------------------------------ Consulta_Ultimo
int Consulta_Ultimo(TDESCRITOR d,TDADOS *dado) {
    TNODO *p;

    if (d.primeiro == NULL) {
        return(LISTA_VAZIA);
    } else {
        p = d.primeiro;

        while (p -> elo != NULL) {
            p = p -> elo;
        }

        *dado = p -> dado;

        return(SUCESSO);
    }
}

// ------------------------------------ Imprime_Erro
void Imprime_Erro(int erro) {
    switch (erro) {
        case FALTA_DE_MEMORIA:
            printf("ERRO: Falta de Memoria\n");
            break;

        case LISTA_VAZIA:
            printf("ERRO: Lista Vazia\n");
            break;
    }
}

// ------------------------------------ Imprime_Lista
void Imprime_Lista(TDESCRITOR l) {
    TNODO *p;

    printf("\nLista Encadeada: ");

    if (l.primeiro == NULL) {
        printf("VAZIA");
    } else {
        p = l.primeiro;

        while (p != NULL) {
            printf("%02d", p -> dado);
            p = p -> elo;
        }
    }
}
