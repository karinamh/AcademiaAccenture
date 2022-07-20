/*

    ***********************************************************

    FILE                        funcao.c
    AUTHOR:                     KARINA MIYUKI HITAKA
    EMAIL:                      karina.hitaka@gmail.com
    DATA DE CRIAÇÃO:            01/08/2021
    BRIEF:                      Arquivo contendo todas as funcoes
                                do programa utilizadas no main.c

    ***********************************************************

*/


#include "funcao.h"

void fc_validacao_senha (int *argc, char *argv[], int **nValidador)
{
    **nValidador = 1;                               // Validador com retorno true (1)
    if (*argc >= VALIDACAO_TOTAL_PARAMETRO)
    {
        if (strcmp (argv[1], "-valida") == 0)       // Caso o argumento [1] seja "-valida", eh necessario validar senha
        {
            if (strcmp (argv[2], VALIDACAO_SENHA) != 0)
            {
                printf("\n>>> Senha de validação incorreta! <<<\n");
                **nValidador = 0;                  // Retorno do programa com falha na validacao de senha
            }
        }
    }
}

void fc_data_hora (struct tm *stDataHora)
{
    // Manipulação de Data e Hora do Sistema com a biblioteca <time.h>
    // Exemplo de uso:
    // printf("Data: %d/%d/%d ", dataHora.tm_mday, dataHora.tm_mon + 1, dataHora.tm_year + 1900);

    time_t tempoAtual;
    tempoAtual = time(NULL);
    *stDataHora = *localtime(&tempoAtual);
}

void fc_permitir_digitar_apenas_numeros (int **pptrValorDigitado, int nMaxDigitos)
{
    int i = 0;

    char cVetorCaracteres[nMaxDigitos];                 // Vetor contendo o maximo de digitos que o usuario pode digitar
    char cCaractere;                                    // Variavel auxiliar para receber cada caractere digitado

    int *ptrValor = (int *) malloc (sizeof(int));       // Alocacao de memoria para o ponteiro

    *pptrValorDigitado = ptrValor;                      // Atribuicao de ponteiro para ponteiro

    fflush(stdin);

    do
    {
        cCaractere = getch();                           // Captura o caractere inserido pelo usuario
        if (cCaractere == 8 && i > 0)                   // Caso seja pressionado a tecla BACKSPACE (8 em ASCII) e tenha caracteres digitados
        {
            cVetorCaracteres[i] = '\0';                 // Indice atual recebe o delimitador de string
            i--;                                        // Voltar a posicao do indice do vetor
            printf("\b \b");                            // O caractere digitado eh apagado da tela
        }
        else if (i >= nMaxDigitos)                      // Caso ultrapasse o tamanho do vetor impedir o usuario de inserir novo digito
        {
            continue;
        }
        else if (isdigit(cCaractere) != 0)              // Caso seja um numero
        {
            cVetorCaracteres[i] = cCaractere;           // Armazenar o caractere digitado no vetor
            i++;                                        // Ir para a proxima posicao do vetor
            printf ("%c", cCaractere);                  // Exibe na tela o caractere digitado
        }

    }
    while (cCaractere != 13);                           // Loop ate o usuario pressionar ENTER (13 em tabela ASCII)

    cVetorCaracteres[i] = '\0';                         // Indice atual recebe o delimitador de string
    **pptrValorDigitado = atoi(cVetorCaracteres);       // Converter a vetor de string para int
}

void fc_exibir_descricao_programa()
{
    struct tm stDataHora;                       // Estrutura para manipular data e hora
    fc_data_hora (&stDataHora);                 // Receber data e hora atual do sistema

    printf(LINHA_SEPARADORA);
    printf("%s - ACADEMIA ACCENTURE BRM\n", NOME_PROGRAMA);
    printf("\nAUTHOR: %s", AUTOR_PROGRAMA);
    printf("\nE-MAIL: %s", EMAIL_AUTOR);
    printf("\nÚLTIMA ATUALIZAÇÃO: %s", DATA_ULTIMA_ATUALIZACAO);
    printf("\nVERSÃO ATUAL: %s", VERSAO_ATUAL);
    printf("\nDATA DE HOJE: %d/%d/%d - %02d:%02dh", stDataHora.tm_mday, stDataHora.tm_mon + 1,
           stDataHora.tm_year + 1900, stDataHora.tm_hour, stDataHora.tm_min);
    printf(LINHA_SEPARADORA);
}

void fc_exibir_menu_opcao ()
{
    printf("\n******************* MENU DE OPÇÕES *******************\n");
    printf("\n1) Verificador de Nome e Idade");
    printf("\n2) Calculadora Científica");
    printf("\n3) Conversor de Temperatura");
    printf("\n4) Calculadora de Fatorial");
    printf("\n5) Verificador de Turno do Dia");
    printf("\n6) Calculadora de Média");
    printf("\n7) Tabuada com Número Ignorado");
    printf("\n8) Média de Colunas Pares e Linhas Ímpares");
    printf("\n9) Exibir Hello World em dois idiomas");
    printf("\n\n0) SAIR DO PROGRAMA");
    printf(LINHA_SEPARADORA);
    printf("Escolha uma opção (digite apenas o número):");
    printf("\n>>> ");
}

void fc_nome_idade (PESSOA *stUsuario)
{
    int *ptrValorDigitado = NULL;                                           // Ponteiro para receber apenas numeros do usuario

    // Struct de data e hora do sistema
    struct tm stDataHora;
    fc_data_hora(&stDataHora);

    printf("\n\nInsira seu primeiro nome: ");
    scanf("%s", stUsuario->cPrimeiroNome);                                 // Receber primeiro nome do usuario

    printf("\nInsira seu sobrenome: ");
    scanf("%s", stUsuario->cUltimoNome);                                   // Receber o sobrenome do usuario

    printf("\nInsira seu ano de nascimento: ");
    fc_permitir_digitar_apenas_numeros(&ptrValorDigitado, 4);              // Digitar apenas numeros com maximo de 4 casas
    stUsuario->nAnoNascimento = *ptrValorDigitado;                         // Armazenar o ano digitado

    stUsuario->nIdade = (stDataHora.tm_year + 1900) - stUsuario->nAnoNascimento;                     // Calcular idade
    stUsuario->nQtdCaracterNome = strlen(stUsuario->cPrimeiroNome) + strlen(stUsuario->cUltimoNome); // Quantidade de caracteres do nome completo

    free (ptrValorDigitado);                                               // Liberar a memoria alocada na funcao fc_permitir_digitar_apenas_numeros
}

void fc_nome_idade_imprimir (PESSOA *stUsuario, char *cResultado)
{
    printf(LINHA_SEPARADORA);
    printf("============ VERIFICADOR DE NOME E IDADE =============\n");

    printf("\n>>> Nome completo: %s %s", stUsuario->cPrimeiroNome, stUsuario->cUltimoNome);
    printf("\n>>> Idade: %d", stUsuario->nIdade);
    printf("\n>>> Idade + Tamanho do nome: %d", stUsuario->nIdade + stUsuario->nQtdCaracterNome);
    sprintf (cResultado, "%d", stUsuario->nIdade + stUsuario->nQtdCaracterNome);

    printf(LINHA_SEPARADORA);
}

void fc_calculadora_cientifica (CALCULADORA *stCalc)
{
    double dValorOperando_1 = 0;                        // Primeiro valor informado pelo usuario
    double dValorOperando_2 = 0;                        // Segundo valor informado pelo usuario

    printf("\n\nInsira o 1º valor: ");
    fflush(stdin);
    scanf("%lf", &dValorOperando_1);                    // Ler o primeiro operando
    printf("\nInsira o 2º valor: ");
    fflush(stdin);
    scanf("%lf", &dValorOperando_2);                    // Ler o segundo operando

    // Resultados das operacoes utilizando biblioteca <math.h>
    stCalc->a_Soma = dValorOperando_1 + dValorOperando_2;                       // a) Soma dos numeros
    stCalc->b_Produto = dValorOperando_1 * (pow(dValorOperando_2, 2));          // b) Produto do primeiro numero pelo quadrado do segundo
    stCalc->c_Quadrado = pow(dValorOperando_1, 2);                              // c) Quadrado do primeiro número
    stCalc->d_Raiz = sqrt(pow(dValorOperando_1, 2) + pow(dValorOperando_2, 2)); // d) Raiz quadrada da soma dos quadrados
    stCalc->e_Seno = sin(dValorOperando_1 - dValorOperando_2);                  // e) Seno da diferença do primeiro numero pelo segundo
    stCalc->f_modulo = abs(dValorOperando_1);                                   // f) Modulo do primeiro número
}

void fc_calculadora_cientifica_imprimir (CALCULADORA *stCalc, char *cResultado)
{
    printf(LINHA_SEPARADORA);
    printf("=============== CALCULADORA CIENTÍFICA ===============\n");

    printf("\n\n a) Soma dos números:");
    printf("\n>>> %f", stCalc->a_Soma);

    printf("\n\n b) Produto do primeiro número pelo quadrado do segundo:");
    printf("\n>>> %f", stCalc->b_Produto);

    printf("\n\n c) Quadrado do primeiro número:");
    printf("\n>>> %f", stCalc->c_Quadrado);

    printf("\n\n d) Raiz quadrada da soma dos quadrados:");
    printf("\n>>> %f", stCalc->d_Raiz);

    printf("\n\n e) Seno da diferença do primeiro número pelo segundo:");
    printf("\n>>> %f", stCalc->e_Seno);

    printf("\n\n f) Módulo do primeiro número:");
    printf("\n>>> %d", stCalc->f_modulo);

    printf(LINHA_SEPARADORA);

    // Formatar string de retorno para o arquivo de log
    sprintf(cResultado, "\na) %f\nb) %f\nc) %f\nd) %f\ne) %f\nf) %d",
            stCalc->a_Soma, stCalc->b_Produto, stCalc->c_Quadrado, stCalc->d_Raiz, stCalc->e_Seno, stCalc->f_modulo);

}

void fc_conversor_temperatura (int *nValorFahrenheit, int *nValorCelsius)
{
    printf("\n\nInsira o valor em Fahrenheit: ");
    fflush(stdin);
    scanf("%d", nValorFahrenheit);                      // Receber valor em Fahrenheit

    *nValorCelsius = (*nValorFahrenheit - 32) * 5 / 9;  // Formula de conversao Fahrenheit para Celsius
}

void fc_conversor_temperatura_imprimir (int *nValorFahrenheit, int *nValorCelsius, char *cResultado)
{
    printf(LINHA_SEPARADORA);
    printf("\n======== CONVERSOR DE FAHRENHEIT PARA CELSIUS ========\n");
    printf("\n>>> %d ºF = %d ºC\n", *nValorFahrenheit, *nValorCelsius);
    printf(LINHA_SEPARADORA);

    // Formatar string de retorno para o arquivo de log
    sprintf(cResultado, "%d ºF = %d ºC", *nValorFahrenheit, *nValorCelsius);
}

void fc_calculadora_fatorial (int *nValorFatorialInicial, int *nValorFatorialFinal)
{
    int nCountFatorial = 0;                         // Contador para calculo do fatorial

    fflush(stdin);
    printf("\n\nInsira um valor para calcular o fatorial: ");
    scanf("%d", nValorFatorialInicial);             // Fatorial inserido pelo usuario a ser calculado

    nCountFatorial = *nValorFatorialInicial;        // Receber o valor inserido pelo usuario

    // Calculo do Fatorial inserido ate chegar em 1
    // Exemplo: 4! = 4 x 3 x 2 x 1
    for (*nValorFatorialFinal = 1; nCountFatorial > 1; nCountFatorial -= 1)
    {
        *nValorFatorialFinal *= nCountFatorial;
    }
}

void fc_calculadora_fatorial_imprimir (int *nValorFatorialInicial, int *nValorFatorialFinal, char *cResultado)
{
    printf(LINHA_SEPARADORA);
    printf("\n============== CALCULADORA DE FATORIAL ===============\n");
    printf("\n>>> Fatorial de %d! = %d\n", *nValorFatorialInicial, *nValorFatorialFinal);
    printf(LINHA_SEPARADORA);

    // Formatar string de retorno para o arquivo de log
    sprintf(cResultado, "%d! = %d", *nValorFatorialInicial, *nValorFatorialFinal);
}

int fc_turno_do_dia ()
{
    int nHorarioTurnoDoDia = 0;                                     // Receber o horario de 0 as 23
    int *ptrValorDigitado = NULL;                                   // Ponteiro para receber apenas numeros do usuario

    do
    {
        printf("\n\nDigite um horário válido (0 a 23): ");

        fc_permitir_digitar_apenas_numeros(&ptrValorDigitado, 2);   // Digitar apenas numeros com maximo de 2 casas
        nHorarioTurnoDoDia = *ptrValorDigitado;                     // Receber o horario informado pelo usuario
        free (ptrValorDigitado);                                    // Liberar memoria alocada na funcao anterior

        // Dia: 0 as 11
        // Tarde: 12 as 17
        // Noite: 18 as 23
        if (nHorarioTurnoDoDia >= 0 && nHorarioTurnoDoDia < 12)
        {
            return DIA;
        }
        else if (nHorarioTurnoDoDia < 18)
        {
            return TARDE;
        }
        else if (nHorarioTurnoDoDia <= 23)
        {
            return NOITE;
        }
        else
        {
            printf("\n>>> Horário inválido. Digite novamente.\n");
        }
    }
    while (nHorarioTurnoDoDia < 0 || nHorarioTurnoDoDia > 23);
    // Realizar o loop enquanto o horario for invalido (horario valido: entre 0 e 23h)

    return 0;
}

void fc_turno_do_dia_imprimir (int *nTurno, char *cResultado)
{
    printf(LINHA_SEPARADORA);
    printf("\n============ VERIFICADOR DE TURNO DO DIA =============\n");

    if (*nTurno == DIA)
    {
        printf("\n>>> Bom dia!");
        sprintf(cResultado, "%s", "Bom dia");
    }
    else if (*nTurno == TARDE)
    {
        printf("\n>>> Boa tarde!");
        sprintf(cResultado, "%s", "Boa tarde");
    }
    else if (*nTurno == NOITE)
    {
        printf("\n>>> Boa noite!");
        sprintf(cResultado, "%s", "Boa noite");
    }

    printf(LINHA_SEPARADORA);
}

char *fc_calculadora_media (int nTamVetor, int *nMediaVetor, bool *bStatus)
{
    int nSomaElementosDoVetor = 0;                                          // Receber a soma dos elementos do vetor convertidos em inteiro
    int i = 0;
    *bStatus = TRUE;

    // Vetor de char com N posições para receber apenas caracteres do tipo número + 1 do delimitador'\0'
    char * cVetorDeNumero = (char *) malloc ((nTamVetor + 1) * sizeof(char));
    // Verificar memoria alocada
    if (cVetorDeNumero == NULL)
    {
        printf("\n\n>>> Falha na alocação de memória! <<<\n\n");
        *bStatus = FALSE;
        return NULL;
    }

    // Realizar o loop até preencher com numeros de acordo com o valor do TAMANHO_VETOR
    while (i < nTamVetor)
    {
        printf("\n\nInsira o %dº número: ", i + 1);
        fflush(stdin);
        scanf("%c", &cVetorDeNumero[i]);                                    // Ler apenas o primeiro caractere digitado

        // Caso o valor nao seja NUMERO pedira novamente um valor para a posicao do vetor
        if (!isdigit(cVetorDeNumero[i]))
        {
            printf(">>>>> VALOR INVÁLIDO! Digite apenas números. <<<<<\n");
            continue;
        }
        i++;                                                                // Incrementador caso seja NUMERO
    }

    cVetorDeNumero[i] = '\0';                                               // Inserir delimitador ao final do vetor

    // Percorrer o vetor para somar os elementos de cada indice
    for (i = 0; i < nTamVetor; i++)
    {
        nSomaElementosDoVetor += (cVetorDeNumero[i] - '0');                 // Converter para int e somar os elementos do vetor
    }

    *nMediaVetor = nSomaElementosDoVetor / nTamVetor;                      // Calcular a media dos valores digitados

    return cVetorDeNumero;
}

void fc_calculadora_media_imprimir (char *cVetorDeNumero, int *nMediaVetor, char *cResultado)
{
    printf(LINHA_SEPARADORA);
    printf("\n=============== CALCULADORA DE MÉDIA =================\n");

    printf("\n\n>>> Valores inseridos (1º dígito): %s", cVetorDeNumero);
    printf("\n\n>>> Média dos valores: %d", *nMediaVetor);
    printf(LINHA_SEPARADORA);

    // Formatar string de retorno para o arquivo de log
    sprintf(cResultado, "%d", *nMediaVetor);
}

int ** fc_tabuada_alocar_memoria (int nTamanhoTab, bool *bStatus)
{
    int i = 0;                                                          // Incrementador
    *bStatus = TRUE;                                                    // Status da alocacao de memoria

    // Alocacao de memoria dinamica
    int **pptrTabuada = (int **) malloc (nTamanhoTab * sizeof(int*));   // Alocar um vetor de linhas do tipo int

    // Verificar se a memoria foi alocada
    if (pptrTabuada == NULL)
    {
        printf("\n\n>>> Falha na alocação de memória! <<<\n\n");
        *bStatus = FALSE;
    }

    for (i = 0; i < nTamanhoTab; i++)
    {
        pptrTabuada[i] = (int*) malloc (nTamanhoTab * sizeof(int));     // Alocar uma coluna para cada linha do vetor

        // Verificar se a memoria foi alocada
        if (pptrTabuada[i] == NULL)
        {
            printf("\n\n>>> Falha na alocação de memória! <<<\n\n");
            *bStatus = FALSE;
        }
    }

    return pptrTabuada;                                                 // Retornar a memoria da matriz alocada
}

void fc_tabuada_preencher (int **pptrTabuada, int nTamanhoTab, int nNumIgnorado)
{
    int i = 0;                                                  // Incrementador
    int j = 0;                                                  // Incrementador

    // Preencher a matriz com a tabuada
    for (i = 0; i < nTamanhoTab; i++)
    {
        if (i == (nNumIgnorado - 1))                            // Pular a tabuada do valor ignorado
        {
            continue;
        }
        for (j = 0; j < nTamanhoTab; j++)
        {
            if (j != (nNumIgnorado - 1))                        // Pular a tabuada do valor ignorado
            {
                pptrTabuada[i][j] = (i + 1) * (j + 1);          // Atribuindo o resultado na matriz de tabuada
            }
        }
    }
}

void fc_tabuada_imprimir (int **pptrTabuada, int nTamanhoTab, int nNumIgnorado, char *cResultado)
{
    char cBuffer[TAM_BUFFER];                                   // Buffer para formatar a string de retorno do resultado
    char cBufAux[30];                                           // Buffer Auxiliar
    int i = 0;                                                  // Incrementador
    int j = 0;                                                  // Incrementador

    memset (cBuffer, '\0', TAM_BUFFER);                         // Colocar toda a string com '\0'
    memset (cBufAux, '\0', 30);                                 // Colocar toda a string com '\0'

    printf(LINHA_SEPARADORA);
    printf("\n================== TABUADA SEM O %d ===================\n\n", nNumIgnorado);

    for (j = 0; j < nTamanhoTab; j++)
    {
        if (j != (nNumIgnorado - 1))                            // Pular a tabuada do valor ignorado
        {
            printf("\n");
            strcat (cBuffer, "\n");

            for (i = 0; i < nTamanhoTab; i++)
            {
                if (i != (nNumIgnorado - 1))                    // Pular a tabuada do valor ignorado
                {
                    printf("%dx%d=%d\t", i + 1, j + 1, pptrTabuada[i][j]);
                    sprintf(cBufAux, "%dx%d=%d\t", i + 1, j + 1, pptrTabuada[i][j]);
                    strcat (cBuffer, cBufAux);
                }
            }
        }
    }
    printf(LINHA_SEPARADORA);

    // Formatar string de retorno para o arquivo de log
    strncpy (cResultado, cBuffer, strlen(cBuffer) + 1);         // Copiar para o ponteiro de retorno
}

void fc_tabuada_liberar_memoria (int **pptrTabuada, int nTamanhoTab)
{
    int i = 0;

    // Liberacao de memoria alocada
    for (i = 0; i < nTamanhoTab; i++)
    {
        free (pptrTabuada[i]);                                  // Liberar memoria alocada do vetor de colunas da matriz
    }
    free (pptrTabuada);                                         // Liberar a memoria alocado do vetor de linhas da matriz
}

double **fc_matriz_double_alocar_memoria (int nLinha, int nColuna, bool *bStatus)
{
    int i = 0;                                                              // Incrementador
    *bStatus = TRUE;                                                        // Status da memoria alocada

    // Alocacao de memoria dinamica
    double **pptrMatriz = (double **) malloc (nLinha * sizeof(double*));    // Alocar um vetor de linhas do tipo double

    // Verificar se a memoria foi alocada
    if (pptrMatriz == NULL)
    {
        printf("\n\n>>> Falha na alocação de memória! <<<\n\n");
        *bStatus = FALSE;
    }

    for (i = 0; i < nLinha; i++)
    {
        pptrMatriz[i] = (double *) malloc (nColuna * sizeof(double));       // Alocar uma coluna para cada linha do vetor

        // Verificar se a memoria foi alocada
        if (pptrMatriz[i] == NULL)
        {
            printf("\n\n>>> Falha na alocação de memória! <<<\n\n");
            *bStatus = FALSE;
        }
    }

    return pptrMatriz;                                                      // Retornar a memoria da matriz alocada
}

void fc_matriz_double_preencher (double **pptrMatriz, int nLinha, int nColuna, char *cResultado)
{
    char cBuffer[TAM_BUFFER];                                   // Buffer para formatar a string de retorno do resultado
    double dSomaColunaPar = 0;                                  // Receber a soma dos elementos das colunas pares da matriz
    double dSomaLinhaImpar = 0;                                 // Receber a soma dos elementos das linhas ímpares da matriz
    double dDiferencaMedia = 0;                                 // Resultado a diferenca entre as medias da coluna par e linha impar
    int nContadorColuna = 0;                                    // Receber a quantidade de elementos somados nas colunas
    int nContadorLinha = 0;                                     // Receber a quantidade de elementos somados nas linhas
    int i = 0;                                                  // Incrementador
    int j = 0;                                                  // Incrementador

    // Preencher a matriz com os valores inseridos pelo usuario
    for (i = 0; i < nLinha; i++)
    {
        for (j = 0; j < nColuna; j++)
        {
            printf("\nInsira o valor da Matriz[%d][%d]: ", i, j);
            fflush(stdin);
            scanf("%lf", &pptrMatriz[i][j]);                    // Receber valor e armazenar na matriz

            if((j % 2) == 0)                                    // Caso a coluna seja par:
            {
                dSomaColunaPar += pptrMatriz[i][j];             // Somar no acumulador
                nContadorColuna++;                              // Contar a quantidade de elementos somados
            }
            if((i % 2) != 0)                                    // Caso a linha seja impar:
            {
                dSomaLinhaImpar += pptrMatriz[i][j];            // Somar no acumulador
                nContadorLinha++;                               // Contar a quantidade de elementos somados
            }
        }
    }

    // Resultado = (Media das colunas pares) - (Media das linhas impares)
    dDiferencaMedia = (dSomaColunaPar / nContadorColuna) - (dSomaLinhaImpar / nContadorLinha);

    // Formatacao do resultado para retorno
    memset (cBuffer, '\0', TAM_BUFFER);                         // Colocar toda a string com '\0'
    sprintf (cBuffer, "%lf", dDiferencaMedia);                  // Converter o valor para string
    strncpy (cResultado, cBuffer, strlen(cBuffer) + 1);         // Copiar para o ponteiro de retorno

}

void fc_matriz_double_imprimir (double **pptrMatriz, int nLinha, int nColuna, char *cResultado)
{
    int i = 0;
    int j = 0;

    printf(LINHA_SEPARADORA);
    printf("\n======= MÉDIA COLUNAS PARES E LINHAS ÍMPARES ========\n\n");

    // Impressao da matriz
    for (i = 0; i < nLinha; i++)
    {
        printf("\n");
        for (j = 0; j < nColuna; j++)
        {
            printf("\t%lf", pptrMatriz[i][j]);
        }
    }

    printf("\n\n\n>>> Diferença entre a média da coluna par e média da linha ímpar:");
    printf("\n>>> %s", cResultado);
    printf(LINHA_SEPARADORA);

}

void fc_matriz_double_liberar_memoria (double **pptrMatriz, int nLinha)
{
    int i = 0;

    // Liberacao de memoria alocada
    for (i = 0; i < nLinha; i++)
    {
        free (pptrMatriz[i]);                                   // Liberar memoria alocada do vetor de colunas da matriz
    }
    free (pptrMatriz);                                          // Liberar a memoria alocado do vetor de linhas da matriz
}

void fc_hello_world (char *cResultado)
{
    FUNCAO *fc_func;                        // ponteiro de funcao
    char cBuffer[80];                       // buffer temporario para editar texto

    printf(LINHA_SEPARADORA);
    printf("\n================ EXIBIR HELLO WORLD ==================\n");

    fc_func = printBR;                      // ponteiro apontando a funcao printBR
    (*fc_func)("PT", cResultado);           // passagem de parametros
    sprintf (cBuffer, "%s", cResultado);

    fc_func = printUS;                      // ponteiro apontando a funcao printUS
    (*fc_func)("US", cResultado);           // passagem de parametros
    strcat (cBuffer, cResultado);

    printf(LINHA_SEPARADORA);

    // Formatacao do resultado para retorno
    sprintf (cResultado, "%s", cBuffer);
}

void printBR(char *cIdioma, char *cResultado)
{
    printf ("\n>>> %s - Olá Mundo!\n", cIdioma);
    sprintf (cResultado, "%s - Olá Mundo! ", cIdioma);

}

void printUS(char *cIdioma, char *cResultado)
{
    printf ("\n>>> %s - Hello World!\n", cIdioma);
    sprintf (cResultado, "%s - Hello World! ", cIdioma);

}

void fc_sair_programa ()
{
    int i = 10;

    printf(LINHA_SEPARADORA);
    printf("\n\n\t>>>>> Finalizando o Programa! <<<<<\n\n");

    // Contagem decrescente de 10 a 0
    while (i >= 0)
    {
        printf("\n\t\t\t%d", i--);
        Sleep(600);             // Funcao Sleep() de delay --> 1000 = 1 segundo // Biblioteca <windows.h>
    }
    printf ("\n\n\n\t\t>>>>> F I M ! <<<<<\n\n");
    printf(LINHA_SEPARADORA);
}

void fc_imprimir_valor_invalido (int nStatus)
{
    if (!nStatus)                         // Caso o valor seja falso(zero)
    {
        printf("\n\n>>>>> Valor inválido! <<<<<\n");

    }
}

void fc_pausar_limpar_tela ()
{
    printf("\n\n");
    system("pause");        // Pausar para o usuario ler a tela
    system("cls");          // Limpar a tela
}

void fc_imprimir_validacao_arquivo (bool bStatus, char *cNomeArquivo)
{
    if (bStatus)        // TRUE
    {
        printf("\n>>>>> Arquivo <%s> criado com sucesso. <<<<<\n", cNomeArquivo);
    }
    else                // FALSE
    {
        printf("\n>>> Falha ao criar o arquivo <%s>. <<<<<\n", cNomeArquivo);
    }
}

void fc_criar_arquivo (char *cNomeArquivo, char *cModo, char *cTexto)
{
    FILE *arquivo = NULL;                                       // Criando ponteiro para arquivo
    arquivo = fopen (cNomeArquivo, cModo);                      // Abrindo o arquivo com nome e modo de leitura / escrita

    if (arquivo != NULL)                                        // Caso o arquivo tenha sido criado
    {
        fputs (cTexto, arquivo);                                // Escrever no arquivo o texto passado no parametro
        fclose (arquivo);                                       // Fechar o arquivo
        fc_imprimir_validacao_arquivo (TRUE, cNomeArquivo);     // Confirmar arquivo criado
    }
    else                                                        // Caso o arquivo nao tenha sido criado
    {
        fc_imprimir_validacao_arquivo (FALSE, cNomeArquivo);    // Enviar mensagem de falha
    }

    printf(LINHA_SEPARADORA);
}

void fc_formatar_texto_arquivo (char *cResultado, char *cNomeArquivo, char *cMenu)
{
    char cBuffer[TAM_BUFFER];
    char cTextoFormatado[TAM_BUFFER];

    struct tm stDataHora;                                       // Estrutura para manipular data e hora
    fc_data_hora (&stDataHora);                                 // Receber data e hora atual do sistema

    // Formatar nome do arquivo log com formato: ano mês dia hora minuto segundo
    strftime (cBuffer, TAM_BUFFER, "arquivo_log_%y%m%d%H%M%S.log", &stDataHora);
    sprintf (cNomeArquivo, "%s", cBuffer);

    // Formatar texto de escrita do arquivo
    strftime (cBuffer, TAM_BUFFER, "%d_%m_%y", &stDataHora);
    sprintf (cTextoFormatado, "%s", cBuffer);
    sprintf (cBuffer, " : Menu %s : %s\n\n", cMenu, cResultado);
    strcat (cTextoFormatado, cBuffer);
    sprintf (cResultado, "%s", cTextoFormatado);
}
