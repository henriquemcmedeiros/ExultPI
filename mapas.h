#include <stdio.h>
#include <stdlib.h>

int **geraMapas(int mapa);

// Declaração da altura e largura fixas com o padrão 32bits
const int altura = 15;
const int largura = 20;

int** geraMapas(int mapa) {
    FILE* file;
    errno_t err;

    if (mapa == 1) {
        err = fopen_s(&file, "mapa1.txt", "r");

        if (err == NULL) {
            fprintf(stderr, "Nao foi possivel abrir o arquivo\n");
            exit(0);
        }

        // ------ Alocando Mapa 1 ------
        // Aloca na memória as linhas da tabela
        int** mapa1 = (int**)malloc(altura * sizeof(int*));

        // Aloca para cada linha uma coluna
        for (int row = 0; row < altura; row++) {
            mapa1[row] = (int*)malloc(largura * sizeof(int));
        }

        // Coloca o conteudo do arquivo TXT dentro da matriz mapa1
        for (int row = 0; row < altura; row++) {
            for (int col = 0; col < largura; col++) {
                if (fscanf_s(err, "%d", &mapa1[row][col]) != 1) {
                    fprintf(stderr, "error reading mapa1[%d][%d]\n", row, col);
                    return 0;
                }
            }
        }
        return mapa1;
        fclose("mapa1.txt");

        // ------ Limpando Memória ------
        // Limpando memória do mapa1 
        for (int row = 0; row < altura; row++) {
            free(mapa1[row]);
        }
        free(mapa1);
    }
    if (mapa == 2) {
        file = fopen_s(&file, "mapas/mapa2.txt", "r");

        if (file == NULL) {
            fprintf(stderr, "Não foi possível abrir o arquivo\n");
            exit(0);
        }

        // ------ Alocando Mapa 2 ------
        // Aloca na memória as linhas da tabela
        int** mapa2 = (int**)malloc(altura * sizeof(int*));

        // Aloca para cada linha uma coluna
        for (int row = 0; row < altura; row++) {
            mapa2[row] = (int*)malloc(largura * sizeof(int));
        }

        // Coloca o conteudo do arquivo TXT dentro da matriz mapa2
        for (int row = 0; row < altura; row++) {
            for (int col = 0; col < largura; col++) {
                if (fscanf_s(file, "%d", &mapa2[row][col]) != 1) {
                    fprintf(stderr, "error reading mapa2[%d][%d]\n", row, col);
                    return 0;
                }
            }
        }
        return mapa2;
        fclose("mapas/mapa2.txt");

        // Limpando memória do mapa2 
        for (int row = 0; row < altura; row++) {
            free(mapa2[row]);
        }
        free(mapa2);
    }
    if (mapa == 3) {
        file = fopen_s(&file, "mapas/mapa3.txt", "r");

        if (file == NULL) {
            fprintf(stderr, "Não foi possível abrir o arquivo\n");
            exit(0);
        }

        // ------ Alocando Mapa 3 ------
        // Aloca na memória as linhas da tabela
        int** mapa3 = (int**)malloc(altura * sizeof(int*));

        // Aloca para cada linha uma coluna
        for (int row = 0; row < altura; row++) {
            mapa3[row] = (int*)malloc(largura * sizeof(int));
        }

        // Coloca o conteudo do arquivo TXT dentro da matriz mapa3
        for (int row = 0; row < altura; row++) {
            for (int col = 0; col < largura; col++) {
                if (fscanf_s(file, "%d", &mapa3[row][col]) != 1) {
                    fprintf(stderr, "error reading mapa3[%d][%d]\n", row, col);
                    return 0;
                }
            }
        }
        return mapa3;
        fclose("mapas/mapa3.txt");

        // Limpando memória do mapa3 
        for (int row = 0; row < altura; row++) {
            free(mapa3[row]);
        }
        free(mapa3);
    }
    if (mapa == 4) {
        file = fopen_s(&file, "mapas/mapa4.txt", "r");

        if (file == NULL) {
            fprintf(stderr, "Não foi possível abrir o arquivo\n");
            exit(0);
        }

        // ------ Alocando Mapa 4 ------
        // Aloca na memória as linhas da tabela
        int** mapa4 = (int**)malloc(altura * sizeof(int*));

        // Aloca para cada linha uma coluna
        for (int row = 0; row < altura; row++) {
            mapa4[row] = (int*)malloc(largura * sizeof(int));
        }

        // Coloca o conteudo do arquivo TXT dentro da matriz mapa4
        for (int row = 0; row < altura; row++) {
            for (int col = 0; col < largura; col++) {
                if (fscanf_s(file, "%d", &mapa4[row][col]) != 1) {
                    fprintf(stderr, "error reading mapa4[%d][%d]\n", row, col);
                    return 0;
                }
            }
        }
        return mapa4;
        fclose("mapas/mapa4.txt");

        // Limpando memória do mapa4
        for (int row = 0; row < altura; row++) {
            free(mapa4[row]);
        }
        free(mapa4);
    }
}

/*void limparMapas() {
    // ------ Limpando Memória ------
    // Limpando memória do mapa1 
    for (int row = 0; row < altura; row++) {
        free(mapa1[row]);
    }
    free(mapa1);

    // Limpando memória do mapa1 
    for (int row = 0; row < altura; row++) {
        free(mapa2[row]);
    }
    free(mapa2);

    // Limpando memória do mapa1 
    for (int row = 0; row < altura; row++) {
        free(mapa3[row]);
    }
    free(mapa3);

    // Limpando memória do mapa1 
    for (int row = 0; row < altura; row++) {
        free(mapa4[row]);
    }
    free(mapa4);

    // Printando o mapa
    /*for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (mapa1[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("%i ", mapa1[i][j]);
            }
        }
        for (int j = 0; j < largura; j++) {
            if (mapa2[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("%i ", mapa2[i][j]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (mapa4[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("%i ", mapa4[i][j]);
            }
        }
        for (int j = 0; j < largura; j++) {
            if (mapa3[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("%i ", mapa3[i][j]);
            }
        }
        printf("\n");
    }
}*/