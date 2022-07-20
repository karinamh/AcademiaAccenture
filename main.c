/*
*
*    ***********************************************************
*
*    ATIVIDADE DA ACADEMIA ORACLE BRM - ACCENTURE
*
*    PROGRAMA:                   PROJETO_KH
*    AUTHOR:                     KARINA MIYUKI HITAKA
*    EMAIL:                      karina.hitaka@gmail.com
*    DATA DE CRIACAO:            28/07/2021
*    DATA ULTIMA ATUALIZACAO:    08/08/2021
*    VERSAO ATUAL:               3.0
*    OBS:

*
*    ***********************************************************
*
*    DESCRICAO: Atividade de avaliacao da ACADEMIA ORACLE BRM
*    realizada pela Accenture. Sistema de Menu contendo varias
*    opcoes de selecao pelo usuario, e cada opcao possui uma
*    atividade proposta pelo Instrutor Mario Muniz.
*
*    ***********************************************************
*/


/*****************************************************
 * BIBLIOTECAS
 *****************************************************/
#include "funcao.h"


/*****************************************************
 * PROGRAMA PRINCIPAL
 *****************************************************/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"portuguese");                                 // Configurar o idioma para PT-BR

    // DECLARACAO DE VARIAVEL LOCAL:
    MENU nOpcaoMenu;                                                // Opcao do Menu utilizando typedef enum

    CALCULADORA stCalculadora;                                      // Struct de calculadora para a opcao 2 do menu

    PESSOA stUsuario;                                               // Struct de dados do usuario para a opcao 1 do menu

    char *cVetor = NULL;                                            // Ponteiro de vetor tipo char
    char cResultado[TAM_BUFFER];                                    // String para receber resultado formatado em texto
    char cNomeArquivo[TAM_NOME_ARQ];                                // String para receber o nome do arquivo log formatado
    //char cTextoArquivo[TAM_BUFFER];                               // String com o resultado formatado para gravar no arquivo

    bool bStatusRetorno;                                            // Verificador para retorno com erros

    int nValidador = 0;                                             // Validador de resultado
    int nValor1 = 0;                                                // Variavel generica para receber valor de funcao do tipo int
    int nValor2 = 0;                                                // Variavel generica para receber valor de funcao do tipo int
    int *ptrValorDigitado = NULL;                                   // Ponteiro para receber valor digitado pelo usuario
    int *ptrArgc = NULL;                                            // Ponteiro para receber parametro de validacao
    int *ptrValidador = NULL;                                       // Ponteiro auxiliar de validacao
    int **pptrMatrizTabuada = NULL;                                 // Ponteiro para receber matriz do tipo int

    double **pptrMatrizDouble = NULL;                               // Ponteiro para receber matriz do tipo double


    // ATRIBUICAO DE PONTEIROS
    ptrArgc = &argc;                                                // Ponteiro apontando para int argc (parametro do main)
    ptrValidador = &nValidador;                                     // Ponteiro auxiliar de validacao


    // VALIDACAO DE SENHA DO EXECUTAVEL
    fc_validacao_senha (ptrArgc, argv, &ptrValidador);              // Chamada de funcao de validacao de senha ao executar o programa pelo terminal

    if (!*ptrValidador)                                             // FALSE -> falha na validacao de senha
    {
        return ERRO_SENHA_INCORRETA;                                // Retorno do programa com falha na validacao de senha
    }


    // MENU DE OPÇÕES:
    do
    {

        fc_exibir_descricao_programa ();                            // Exibir descricao ao iniciar o programa
        fc_exibir_menu_opcao ();                                    // Exibir a lista de menu de opcoes
        fflush(stdin);                                              // Limpar o buffer do teclado

        // Receber valor do usuario com limite de UM digito e verificar se a memoria foi alocada
        fc_permitir_digitar_apenas_numeros (&ptrValorDigitado, 1);  // Funcao para receber apenas numeros
        nOpcaoMenu = *ptrValorDigitado;                             // Atribuir o valor ao ENUM
        free(ptrValorDigitado);                                     // Liberar a memoria alocada
        fflush(stdin);                                              // Limpar o buffer do teclado

        switch (nOpcaoMenu)                                         // Escolha conforme a opcao do menu informada pelo usuario
        {
        case MENU_SAIR:                                             // OPCAO 0

            fc_sair_programa();                                     // Exibicao de finalizacao do sistema em contagem regressiva
            break;

        case MENU_NOME_IDADE:
            // OPCAO 1
            fc_nome_idade (&stUsuario);
            fc_nome_idade_imprimir (&stUsuario, cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_1);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_CALCULADORA_CIENTIFICA:
            // OPCAO 2
            fc_calculadora_cientifica(&stCalculadora);
            fc_calculadora_cientifica_imprimir (&stCalculadora, cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_2);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_CONVERSOR_TEMPERATURA:
            // OPCAO 3
            fc_conversor_temperatura(&nValor1, &nValor2);
            fc_conversor_temperatura_imprimir(&nValor1, &nValor2, cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_3);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_CALCULADORA_FATORIAL:
            // OPCAO 4
            fc_calculadora_fatorial(&nValor1, &nValor2);
            fc_calculadora_fatorial_imprimir (&nValor1, &nValor2, cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_4);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_TURNO_DO_DIA:
            // OPCAO 5
            nValor1 = fc_turno_do_dia ();
            fc_turno_do_dia_imprimir (&nValor1, cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_5);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_CALCULADORA_MEDIA:
            // OPCAO 6
            cVetor = fc_calculadora_media (TAMANHO_VETOR, &nValor1, &bStatusRetorno);
            if (!bStatusRetorno)        // Verificar a alocacao de memoria
            {
                return ERRO_MEMORIA;
            }
            fc_calculadora_media_imprimir (cVetor, &nValor1, cResultado);
            free (cVetor);              // Liberar memoria alocada

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_6);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_TABUADA_COM_NUM_IGNORADO:
            // OPCAO 7
            pptrMatrizTabuada = fc_tabuada_alocar_memoria (TABUADA_TAMANHO, &bStatusRetorno);
            if (!bStatusRetorno)        // Verificar a alocacao de memoria
            {
                return ERRO_MEMORIA;
            }
            fc_tabuada_preencher (pptrMatrizTabuada, TABUADA_TAMANHO, TABUADA_IGNORAR_NUMERO);
            fc_tabuada_imprimir (pptrMatrizTabuada, TABUADA_TAMANHO, TABUADA_IGNORAR_NUMERO, cResultado);
            fc_tabuada_liberar_memoria (pptrMatrizTabuada, TABUADA_TAMANHO);

            // Criar arquivo de txt com a tabuada
            fc_criar_arquivo (ARQUIVO_TABUADA, MODO_W, cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_7);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_COLUNA_PAR_LINHA_IMPAR:
            // OPCAO 8
            pptrMatrizDouble = fc_matriz_double_alocar_memoria (TAM_LINHA_MATRIZ, TAM_COLUNA_MATRIZ, &bStatusRetorno);
            if (!bStatusRetorno)        // Verificar a alocacao de memoria
            {
                return ERRO_MEMORIA;
            }
            fc_matriz_double_preencher (pptrMatrizDouble, TAM_LINHA_MATRIZ, TAM_COLUNA_MATRIZ, cResultado);
            fc_matriz_double_imprimir(pptrMatrizDouble, TAM_LINHA_MATRIZ, TAM_COLUNA_MATRIZ, cResultado);
            fc_matriz_double_liberar_memoria(pptrMatrizDouble, TAM_LINHA_MATRIZ);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_8);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        case MENU_HELLO_WORLD:
            // OPCAO 9
            fc_hello_world(cResultado);

            // Criar arquivo de log
            fc_formatar_texto_arquivo (cResultado, cNomeArquivo, MENU_9);
            fc_criar_arquivo(cNomeArquivo, MODO_A, cResultado);

            break;

        default:                                                    // DEFAULT -> caso nenhuma opcao acima seja atendida

            fc_imprimir_valor_invalido(FALSE);                      // Chamada de funcao para imprimir valor invalido
            break;

        };  // Fim do switch case

        fc_pausar_limpar_tela();                                    // Pausar e limpar a tela para o usuario ler
    }
    while (nOpcaoMenu != MENU_SAIR);                                // Continuar no loop ate o usuario digitar ZERO para sair do programa

    return SAIDA_COM_SUCESSO;                                       // Retorno do programa com exito

} // Fim da int main()

