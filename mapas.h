#include <stdio.h>
#include <stdlib.h>

int **geraMapas(int mapa);

const int altura = 15;
const int largura = 20;

int **geraMapas(int mapa) {
    // ------ Alocando Mapa 1 ------
    // allocate Rows rows, each row is a pointer to int
    int** mapa1 = (int**)malloc(altura * sizeof(int*));

    // for each row allocate Cols ints
    for (int row = 0; row < altura; row++) {
        mapa1[row] = (int*)malloc(largura * sizeof(int));
    }

    // ------ Alocando Mapa 2 ------
    // allocate Rows rows, each row is a pointer to int
    int** mapa2 = (int**)malloc(altura * sizeof(int*));

    // for each row allocate Cols ints
    for (int row = 0; row < altura; row++) {
        mapa2[row] = (int*)malloc(largura * sizeof(int));
    }

    // ------ Alocando Mapa 3 ------
    // allocate Rows rows, each row is a pointer to int
    int** mapa3 = (int**)malloc(altura * sizeof(int*));

    // for each row allocate Cols ints
    for (int row = 0; row < altura; row++) {
        mapa3[row] = (int*)malloc(largura * sizeof(int));
    }

    // ------ Alocando Mapa 4 ------
    // allocate Rows rows, each row is a pointer to int
    int** mapa4 = (int**)malloc(altura * sizeof(int*));

    // for each row allocate Cols ints
    for (int row = 0; row < altura; row++) {
        mapa4[row] = (int*)malloc(largura * sizeof(int));
    }

    // Setando todos os espaços para 0 (Chão / Nada) 
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            mapa1[i][j] = 0;
            mapa2[i][j] = 0;
            mapa3[i][j] = 0;
            mapa4[i][j] = 0;
        }
    }

    if (mapa == 1) {
        // Colocando paredes mapa1
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                if ((i == 2 && j < 15 && j > 2) || (i == 8 && j < 20 && j > 14) || (i == 12 && j < 20 && j > 1)) {
                    // Parede frontal
                    mapa1[i][j] = 1;
                }
                else if ((j == 2 && i < 12 && i > 2) || (j == 15 && i < 8 && i > 2)) {
                    // Parede lateral
                    mapa1[i][j] = 3;
                }
                else if ((j == 19 && i < 12 && i > 8)) {
                    // Portas
                    mapa1[i][j] = 5;
                }
                // Quinas de parede
                mapa1[2][2] = 2;
                mapa1[2][15] = 2;
            }
        }
        return mapa1;
    }
    else if (mapa == 2) {
        // Colocando paredes mapa2
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                if ((i == 12 && j < 13) || (i == 8 && j < 17) || (i == 2 && j < 17 && j > 2)) {
                    mapa2[i][j] = 1;
                }
                else if ((j == 2 && i < 8 && i > 2) || (j == 7 && i < 8 && i > 2) || (j == 12 && i < 8 && i > 2) || (j == 17 && i > 2) || (j == 13 && i > 12)) {
                    mapa2[i][j] = 3;
                }
                if ((j == 3 && i == 8) || (j == 8 && i == 8) || (j == 13 && i == 8) || (i == 14 && j < 17 && j > 13)) {
                    mapa2[i][j] = 5;
                }
                else if ((j == 2 && i == 2) || (j == 7 && i == 2) || (j == 17 && i == 2) || (j == 13 && i == 12)) {
                    mapa2[i][j] = 2;
                }
            }
        }
        return mapa2;
    }
    else if (mapa == 3) {
        // Colocando paredes mapa3
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                if ((i == 12 && j < 18) || (i == 11 && j > 17) || (i == 7 && j > 16) || (i == 2 && j < 14 && j > 10) || (i == 3 && j < 11 && j > 8) || (i == 4 && j < 9 && j > 6) || (i == 5 && j == 6) || (i == 6 && j < 6 && j > 3) || (i == 7 && j < 4 && j > 1) || (i == 8 && j < 2)) {
                    mapa3[i][j] = 1;
                }
                else if ((j == 13 && i < 2) || (j == 17 && i < 7)) {
                    mapa3[i][j] = 3;
                }
                else if ((i == 6 && j < 17 && j > 13) || (i == 7 && j < 15 && j > 11) || (i == 8 && j < 13 && j > 10) || (i == 9 && j < 12 && j > 8) || (i == 10 && j < 10 && j > 6) || (i == 11 && j == 7)) {
                    mapa3[i][j] = 4;
                }
                else if ((j == 1 && i == 7) || (j == 3 && i == 6) || (j == 5 && i == 5) || (j == 6 && i == 4) || (j == 8 && i == 3) || (j == 10 && i == 2) || (j == 17 && i == 11)) {
                    mapa3[i][j] = 2;
                }
                else if ((j == 0 && i < 12 && i > 8)) {
                    mapa3[i][j] = 5;
                }
            }
        }
        return mapa3;
    }
    else if (mapa == 4) {
        // Colocando paredes mapa4
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                if ((i == 1 && j < 18 && j > 8) || (i == 12 && j > 7) || (i == 8 && j > 17)) {
                    mapa4[i][j] = 1;
                }
                else if ((j == 18 && i < 8 && i > 1) || (j == 8 && i < 9 && i > 1) || (j == 8 && i < 12 && i > 9)) {
                    mapa4[i][j] = 3;
                }
                else if ((j == 8 && i == 9)) {
                    mapa4[i][j] = 5;
                }
                else if ((j == 8 && i == 1) || (j == 18 && i == 1)) {
                    mapa4[i][j] = 2;
                }
            }
        }
        return mapa4;
    }
    free(mapa1);
    free(mapa2);
    free(mapa3);
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
    }*/
}