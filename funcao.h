/*

    ***********************************************************

    FILE                        funcao.h
    AUTHOR:                     KARINA MIYUKI HITAKA
    EMAIL:                      karina.hitaka@gmail.com
    DATA DE CRIAÇÃO:            01/08/2021
    BRIEF:                      Header da funcao.c

    ***********************************************************

*/

#ifndef FUNCAO_H_INCLUDED

#define FUNCAO_H_INCLUDED


/*****************************************************
 * BIBLIOTECAS
 *****************************************************/

#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


/*****************************************************
 * DEFINES
 *****************************************************/

// VALIDACAO DE SENHA
#define VALIDACAO_SENHA             "cringe"
#define VALIDACAO_TOTAL_PARAMETRO   3

// DESCRICAO DO PROGRAMA
#define NOME_PROGRAMA               "PROJETO KH"
#define AUTOR_PROGRAMA              "Karina Miyuki Hitaka"
#define EMAIL_AUTOR                 "karina.hitaka@gmail.com"
#define DATA_ULTIMA_ATUALIZACAO     "08/08/2021"
#define VERSAO_ATUAL                "3.0"

// RETURN
#define SAIDA_COM_SUCESSO           0
#define ERRO_SENHA_INCORRETA        1
#define ERRO_MEMORIA                2

// ARQUIVO
#define ARQUIVO_TABUADA             "Tabuada.txt"
#define MODO_W                      "w"
#define MODO_A                      "a"

// FORMATACAO DE STRING
#define TAM_NOME_ARQ                30
#define TAM_BUFFER                  800

// NOME DAS FUNCOES PARA ARQUIVO LOG
#define MENU_1                      "CADASTRO"
#define MENU_2                      "CALCULADORA"
#define MENU_3                      "TEMPERATURA"
#define MENU_4                      "FATORIAL"
#define MENU_5                      "TURNO"
#define MENU_6                      "MEDIA"
#define MENU_7                      "TABUADA"
#define MENU_8                      "MATRIZ"
#define MENU_9                      "HELLOWORLD"

// OPCAO DO MENU 6
#define DIA                         1
#define TARDE                       2
#define NOITE                       3

// OPCAO DO MENU 6
#define TAMANHO_VETOR               10

// OPCAO DO MENU 7
#define TABUADA_TAMANHO             10
#define TABUADA_IGNORAR_NUMERO      5

// OPCAO DO MENU 8
#define TAM_COLUNA_MATRIZ           3
#define TAM_LINHA_MATRIZ            5

// COMANDOS PARA EXIBICAO VISUAL
#define LINHA_SEPARADORA            "\n\n******************************************************\n\n"


/*****************************************************
 * TYPEDEF
 *****************************************************/

// TYPEDEF PARA O MENU
typedef enum
{
    MENU_SAIR = 0,
    MENU_NOME_IDADE = 1,
    MENU_CALCULADORA_CIENTIFICA = 2,
    MENU_CONVERSOR_TEMPERATURA = 3,
    MENU_CALCULADORA_FATORIAL = 4,
    MENU_TURNO_DO_DIA = 5,
    MENU_CALCULADORA_MEDIA = 6,
    MENU_TABUADA_COM_NUM_IGNORADO = 7,
    MENU_COLUNA_PAR_LINHA_IMPAR = 8,
    MENU_HELLO_WORLD = 9,
} MENU;

// TYPEDEF PARA A OPCAO DO MENU 2
typedef struct
{
    float a_Soma;
    float b_Produto;
    float c_Quadrado;
    float d_Raiz;
    float e_Seno;
    int f_modulo;
} CALCULADORA;

// TYPEDEF PARA A OPCAO DO MENU 1
typedef struct
{
    char cPrimeiroNome[80];
    char cUltimoNome[80];
    int nAnoNascimento;
    int nIdade;
    int nQtdCaracterNome;
} PESSOA;

typedef void FUNCAO (char[], char[]);

/*****************************************************
 * FUNCOES
 *****************************************************/

/**
* VALIDACAO DE SENHA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 02/08/2021
* @DESCRICAO: VALIDACAO DE SENHA AO EXECUTAR O PROGRAMA
* @PARAMETROS:        int *argc - quantidade de parametros recebido pelo executavel
*                  char *argv[] - vetor de string com os parametros para comparacao
*               int *nValidador - retorno com status de validacao da senha
* @RETORNO:
**/
void fc_validacao_senha (int *argc, char *argv[], int **nValidador);


/**
* DATA E HORA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 02/08/2021
* @DESCRICAO: MANIPULACAO DE DATA E HORA ATUAL DO SISTEMA LOCAL
* @PARAMETROS:      struct tm *stDataHora - estrutura de data e hora
* @RETORNO:
**/
void fc_data_hora (struct tm *stDataHora);


/**
* DIGITAR APENAS NUMEROS
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 04/08/2021
* @DESCRICAO: FUNCAO PARA PERMITIR QUE O USUARIO DIGITE APENAS NUMEROS.
* A ENTRA DE OUTROS CARACTERES NAO SERA RECEBIDO.
* @PARAMETROS:    int **pptrValorDigitado - ponteiro de retorno com valor digitado pelo usuario
*                         int nMaxDigitos - receber a quantidade maxima de digitos que o usuario pode digitar na tela
* @RETORNO:
**/
void fc_permitir_digitar_apenas_numeros (int **pptrValorDigitado, int nMaxDigitos);



/////////////////////////////////////////////////////////////////////////////////////////////

/*****************************************************
 * FUNCOES DO MENU DE OPCOES
 *****************************************************/

/**
* MENU OPCAO 1 - NOME E IDADE
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: RECEBER DO USUARIO NOME, SOBRENOME E ANO DE NASCIMENTO. EXIBIR A QUANTIDADE
* DE CARACTERES DO NOME E SOBRENOME + IDADE.
* @PARAMETROS:          PESSOA *stUsuario - struct contendo dados do usuario
* @RETORNO:
**/
void fc_nome_idade (PESSOA *stUsuario);

/**
* MENU OPCAO 1 - NOME E IDADE - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 06/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO NOME E IDADE
* @PARAMETROS:         PESSOA *stUsuario - struct contendo dados do usuario
*                       char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_nome_idade_imprimir (PESSOA *stUsuario, char *cResultado);


/**
* MENU OPCAO 2 - CALCULADORA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: RECEBER DOIS OPERANDOS DO USUARIO E REALIZAR DIVERSOS CALCULOS MATEMATICOS
* @PARAMETROS:       CALCULADORA *stCalc - receber o registro de calculadora
* @RETORNO:
**/
void fc_calculadora_cientifica (CALCULADORA *stCalc);

/**
* MENU OPCAO 2 - CALCULADORA IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO CALCULADORA
* @PARAMETROS:       CALCULADORA *stCalc - receber o registro de calculadora
*                       char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_calculadora_cientifica_imprimir (CALCULADORA *stCalc, char *cResultado);


/**
* MENU OPCAO 3 - CONVERSOR DE TEMPERATURA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: CONVERTER A TEMPERATURA EM FAHRENHEIT (F) PARA CELSIUS (C) UTILIZANDO VALORES INTEIROS
* @PARAMETROS:     int *nValorFahrenheit - valor em Fahrenheit a receber do usuario
*                       char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_conversor_temperatura (int *nValorFahrenheit, int *nValorCelsius);

/**
* MENU OPCAO 3 - CONVERSOR DE TEMPERATURA - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 06/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO CONVERSOR DE TEMPERATURA
* @PARAMETROS:     int *nValorFahrenheit - valor em Fahrenheit
*                     int *nValorCelsius - valor em Celsius
*                       char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_conversor_temperatura_imprimir (int *nValorFahrenheit, int *nValorCelsius, char *cResultado);


/**
* MENU OPCAO 4 - FATORIAL
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: RECEBER UM VALOR DO USUARIO E CALCULAR SEU FATORIAL
* @PARAMETROS: int *nValorFatorialInicial - valor inserido pelo usuario
*                int *nValorFatorialFinal - valor do fatorial calculado
* @RETORNO:
**/
void fc_calculadora_fatorial (int *nValorFatorialInicial, int *nValorFatorialFinal);


/**
* MENU OPCAO 4 - FATORIAL - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 06/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO FATORIAL
* @PARAMETROS: int *nValorFatorialInicial - valor inserido pelo usuario
*                int *nValorFatorialFinal - valor do fatorial calculado
*                        char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_calculadora_fatorial_imprimir (int *nValorFatorialInicial, int *nValorFatorialFinal, char *cResultado);


/**
* MENU OPCAO 5 - TURNO DO DIA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: FUNCAO PARA RECEBER O HORARIO INSERIDO PELO USUARIO E VERIFICAR O
* TURNO DO DIA (0 A 11 - DIA | 12 A 17 - TARDE | 18 A 23 - NOITE)
* @PARAMETROS:
* @RETORNO:                          int - retornar o turno (DIA (1), TARDE (2) ou NOITE (3)
**/
int fc_turno_do_dia ();


/**
* MENU OPCAO 5 - TURNO DO DIA - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 06/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO TURNO DO DIA
* @PARAMETROS:               int *nTurno - valor do turno (DIA (1), TARDE (2) ou NOITE (3)
*                       char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_turno_do_dia_imprimir (int *nTurno, char *cResultado);


/**
* MENU OPCAO 6 - MEDIA DO VETOR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 05/08/2021
* @DESCRICAO: FUNCAO PARA CALCULAR MEDIA A PARTIR DE UM VETOR DE STRING (de nTamVetor),
* ARMAZENAR APENAS NUMEROS E EXIBIR A MEDIA DA SOMA DOS ELEMENTOS DO VETOR.
* @PARAMETROS:            int nTamVetor - tamanho do vetor
*                      int *nMediaVetor - calculo da media dos elementos do vetor
*                         bool *bStatus - status de alocacao de memoria | FALSE = Memoria nao alocada
* @RETORNO:                      char * - retorno do vetor
**/
char *fc_calculadora_media (int nTamVetor, int *nMediaVetor, bool *bStatus);

/**
* MENU OPCAO 6 - MEDIA DO VETOR - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 05/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO MEDIA DO VETOR
* @PARAMETROS:     char *cVetorDeNumero - vetor tipo char com numeros
*                      int *nMediaVetor - calculo da media dos elementos do vetor
*                      char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_calculadora_media_imprimir (char *cVetorDeNumero, int *nMediaVetor, char *cResultado);


/**
* MENU OPCAO 7 - TABUADA - ALOCAR MEMORIA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: ALOCAR MEMORIA DA MATRIZ PARA A FUNCAO TABUADA
* @PARAMETROS:          int nTamanhoTab - tamanho da tabuada
*                         bool *bStatus - status da alocacao de memoria | FALSE = Memoria nao alocada
* @RETORNO:                      int ** - retorno da matriz
**/
int ** fc_tabuada_alocar_memoria (int nTamanhoTab, bool *bStatus);


/**
* MENU OPCAO 7 - TABUADA - PREENCHER
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: FUNCAO PARA CRIAR UMA TABUADA IGNORANDO UM DETERMINADO NUMERO
* @PARAMETROS:        int **pptrTabuada - matriz da tabuada
*                       int nTamanhoTab - tamanho da tabuada
*                      int nNumIgnorado - valor a ser ignorado na tabuada
* @RETORNO:
**/
void fc_tabuada_preencher (int **pptrTabuada, int nTamanhoTab, int nNumIgnorado);

/**
* MENU OPCAO 7 - TABUADA - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: IMPRIMIR OS RESULTADOS DA FUNCAO TABUADA
* @PARAMETROS:        int **pptrTabuada - matriz da tabuada
*                       int nTamanhoTab - tamanho da tabuada
*                      int nNumIgnorado - valor a ser ignorado na tabuada
*                      char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_tabuada_imprimir (int **pptrTabuada, int nTamanhoTab, int nNumIgnorado, char *cResultado);

/**
* MENU OPCAO 7 - TABUADA - LIBERAR MEMORIA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: LIBERAR A MEMORIA ALOCADA DA MATRIZ DA FUNCAO TABUADA
* @PARAMETROS:        int **pptrTabuada - matriz da tabuada
*                       int nTamanhoTab - tamanho da tabuada
* @RETORNO:
**/
void fc_tabuada_liberar_memoria (int **pptrTabuada, int nTamanhoTab);

/**
* MENU OPCAO 8 - MATRIZ DOUBLE- ALOCAR MEMORIA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: CRIAR UMA MATRIZ COM ALOCACAO DINAMICA DE MEMORIA PARA A FUNCAO MATRIZ DOUBLE
* @PARAMETROS:               int nLinha - Qtd de Linhas da matriz
*                           int nColuna - Qtd de Colunas da matriz
*                         bool *bStatus - status da memoria alocada | FALSE = Memoria nao alocada
* @RETORNO:                   double ** - retorno da memoria alocada da matriz
**/
double **fc_matriz_double_alocar_memoria (int nLinha, int nColuna, bool *bStatus);

/**
* MENU OPCAO 8 - MATRIZ DOUBLE - PREENCHER
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: FUNCAO PARA CRIAR UMA MATRIZ, CALCULAR A MEDIA DOS ELEMENTOS DAS COLUNAS PARES,
* A MEDIA DE ELEMENTOS DAS LINHAS IMPARES, E EXIBIR A DIFERENCA ENTRE AS DUAS MEDIAS*
* @PARAMETROS:      double **pptrMatriz - ponteiro de ponteiro da matriz
*                            int nLinha - Qtd de Linhas da matriz
*                           int nColuna - Qtd de Colunas da matriz
*                      char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_matriz_double_preencher (double **pptrMatriz, int nLinha, int nColuna, char *cResultado);

/**
* MENU OPCAO 8 - MATRIZ DOUBLE - IMPRIMIR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: IMPRIMIR RESULTADO DA FUNCAO MATRIZ DOUBLE
* @PARAMETROS:      double **pptrMatriz - ponteiro de ponteiro da matriz
*                            int nLinha - Qtd de Linhas da matriz
*                           int nColuna - Qtd de Colunas da matriz
*                      char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_matriz_double_imprimir (double **pptrMatriz, int nLinha, int nColuna, char *cResultado);

/**
* MENU OPCAO 8 - MATRIZ DOUBLE - LIBERAR MEMORIA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 07/08/2021
* @DESCRICAO: LIBERAR MEMORIA ALOCADA DA FUNCAO MATRIZ DOUBLE
* @PARAMETROS:      double **pptrMatriz - ponteiro de ponteiro da matriz
*                            int nLinha - Qtd de Linhas da matriz
* @RETORNO:
**/
void fc_matriz_double_liberar_memoria (double **pptrMatriz, int nLinha);

/**
* MENU OPCAO 9 - HELLO WORLD
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 08/08/2021
* @DESCRICAO: EXIBIR HELLO WORLD DE DUAS FORMAS UTILIZANDO METODO DE PONTEIRO PARA FUNCAO
* @PARAMETROS:         char *cResultado - retorno do resultado
* @RETORNO:
**/
void fc_hello_world (char *cResultado);

/**
* MENU OPCAO 9 - HELLO WORLD - PRINT BR
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 08/08/2021
* @DESCRICAO: EXIBIR OLA MUNDO
* @PARAMETROS:           char *cIdioma - sigla do idioma
*                     char *cResultado - retorno do resultado
* @RETORNO:
**/
void printBR(char *cIdioma, char *cResultado);

/**
* MENU OPCAO 9 - HELLO WORLD - PRINT US
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 08/08/2021
* @DESCRICAO: EXIBIR HELLO WORLD
* @PARAMETROS:           char *cIdioma - sigla do idioma
*                     char *cResultado - retorno do resultado
* @RETORNO:
**/
void printUS(char *cIdioma, char *cResultado);


/**
* MENU OPCAO 0 - SAIR DO PROGRAMA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: FUNCAO PARA SAIR DO PROGRAMA. EXIBE NA TELA UMA CONTAGEM REGRESSIVA
* DE 10 A 0, E "FIM" AO FINAL DA CONTAGEM*
* @PARAMETROS:
* @RETORNO:
**/
void fc_sair_programa ();


////////////////////////////////////////////////////////////////////////////////////////////////

/*****************************************************
 * FUNCOES DE IMPRESSAO
 *****************************************************/

/**
* DESCRICAO PROGRAMA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: EXIBIR A DESCRICAO DO PROGRAMA
* @PARAMETROS:
* @RETORNO:
**/
void fc_exibir_descricao_programa();


/**
* MENU DE OPCAO
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 01/08/2021
* @DESCRICAO: EXIBIR MENU DE OPCOES
* @PARAMETROS:
* @RETORNO:
**/
void fc_exibir_menu_opcao ();

/**
* IMPRIMIR VALOR INVALIDO
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 03/08/2021
* @DESCRICAO: FUNCAO DE VALIDACAO E IMPRIMIR MENSAGEM DE VALOR INVALIDO
* @PARAMETROS:      int nStatus - valor para validacao: Falso = 0
* @RETORNO:
**/
void fc_imprimir_valor_invalido (int nStatus);


/**
* PAUSAR E LIMPAR TELA
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 03/08/2021
* @DESCRICAO: FUNCAO PARA PAUSAR A TELA PARA O USUARIO LER E LIMPAR A TELA
* @PARAMETROS:
* @RETORNO:
**/
void fc_pausar_limpar_tela ();


/*****************************************************
 * FUNCOES DE MANIPULACAO DE ARQUIVO
 *****************************************************/

/**
* IMPRIMIR VALIDACAO DE ARQUIVO
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 04/08/2021
* @DESCRICAO: FUNCAO PARA EXIBIR NA TELA SE O ARQUIVO FOI CRIADO OU NAO
* @PARAMETROS:     bool bStatus - status de validacao
*            char *cNomeArquivo - nome do arquivo
* @RETORNO:
**/
void fc_imprimir_validacao_arquivo (bool bStatus, char *cNomeArquivo);

/**
* CRIAR ARQUIVO
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 06/08/2021
* @DESCRICAO: FUNCAO PARA CRIAR ARQUIVO E GRAVAR INFORMACOES
* @PARAMETROS:     char *cNomeArquivo - Nome do arquivo
*                         char *cModo - Modo de gravacao
*                        char *cTexto - Texto a ser gravado no arquivo
* @RETORNO:
**/
void fc_criar_arquivo (char *cNomeArquivo, char *cModo, char *cTexto);

/**
* FORMATAR TEXTO PARA ARQUIVO LOG
* @AUTHOR: karina.hitaka@gmail.com
* @DATA: 08/08/2021
* @DESCRICAO: FUNCAO PARA FORMATAR TEXTO PARA SER GRAVADO NO ARQUIVO LOG
* @PARAMETROS:       char *cResultado - Receber resultado da funcao do menu e devolver formatado
*                  char *cNomeArquivo - Formatar o nome do arquivo
*                         char *cMenu - Receber o nome da funcao
* @RETORNO:
**/
void fc_formatar_texto_arquivo (char *cResultado, char *cNomeArquivo, char *cMenu);


#endif // #ifndef FUNCAO_H_INCLUDED

