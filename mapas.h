#include <../../../../../header.h>

int** geraMapas(int mapa);
void loadMap();
void limparMapas(int** mapa);
void trocarMapas(mapa* ptr);

// Declaração da altura e largura fixas com o padrão 32bits
const int altura = 15;
const int largura = 20;

FILE* mapa1, *mapa2, *mapa3, *mapa4;

void trocarMapas(mapa* ptr) {
    int XMAX = 656;
    int XMIN = -16;
    int YMAX = 496;
    int YMIN = -16;

    if (ptr->escolhaMapa == 1 && ptr->pos_x >= XMAX) {
        ptr->escolhaMapa = 2;
        ptr->map = geraMapas(ptr->escolhaMapa);
        ptr->pos_x = 16;
        ptr->pos_y = 336;
    }
    if (ptr->escolhaMapa == 2 && ptr->pos_x <= XMIN) {
        ptr->escolhaMapa = 1;
        ptr->map = geraMapas(ptr->escolhaMapa);
        ptr->pos_x = 624;
        ptr->pos_y = 336;
    }
    else if (ptr->escolhaMapa == 2 && ptr->pos_y >= YMAX) {
        ptr->escolhaMapa = 3;
        ptr->map = geraMapas(ptr->escolhaMapa);
        ptr->pos_x = 496;
        ptr->pos_y = 16;
    }
    if (ptr->escolhaMapa == 3 && ptr->pos_y <= YMIN) {
        ptr->escolhaMapa = 2;
        ptr->map = geraMapas(ptr->escolhaMapa);
        ptr->pos_x = 496;
        ptr->pos_y = 464;
    }
    else if (ptr->escolhaMapa == 3 && ptr->pos_x <= XMIN) {
        ptr->escolhaMapa = 4;
        ptr->map = geraMapas(ptr->escolhaMapa);
        ptr->pos_x = 624;
        ptr->pos_y = 368;
    }
    if (ptr->escolhaMapa == 4 && ptr->pos_x >= XMAX) {
        ptr->escolhaMapa = 3;
        ptr->map = geraMapas(ptr->escolhaMapa);
        ptr->pos_x = 16;
        ptr->pos_y = 368;
    }
}

void loadMap() {
    errno_t err1 = fopen_s(&mapa1, "mapas/mapa1.txt", "r");
    errno_t err2 = fopen_s(&mapa2, "mapas/mapa2.txt", "r");
    errno_t err3 = fopen_s(&mapa3, "mapas/mapa3.txt", "r");
    errno_t err4 = fopen_s(&mapa4, "mapas/mapa4.txt", "r");

    if (err1 + err2 + err3 + err4 != 0) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo\n");
        exit(0);
    }
}

int** geraMapas(int mapa) {
    loadMap();
    // ------ Alocando Mapas ------
    // Aloca na memória as linhas da tabela
    int** mapas = (int**)malloc(altura * sizeof(int*));

    // Aloca para cada linha uma coluna
    for (int row = 0; row < altura; row++) {
        mapas[row] = (int*)malloc(largura * sizeof(int));
    }

    for (int row = 0; row < altura; row++) {
        for (int col = 0; col < largura; col++) {
            if (mapa == 1) {
                // Coloca o conteudo do arquivo TXT dentro da matriz mapa1
                errno_t err4 = fscanf_s(mapa1, "%d", &mapas[row][col]) != 1;
                if (err4) {
                    //fprintf(stderr, "error reading mapa1[%d][%d]\n", row, col);
                    return 0;
                }
            }
            else if (mapa == 2) {
                // Coloca o conteudo do arquivo TXT dentro da matriz mapa2
                if (fscanf_s(mapa2, "%d", &mapas[row][col]) != 1) {
                    //fprintf(stderr, "error reading mapa2[%d][%d]\n", row, col);
                    return 0;
                }
            }
            else if (mapa == 3) {
                // Coloca o conteudo do arquivo TXT dentro da matriz mapa3
                if (fscanf_s(mapa3, "%d", &mapas[row][col]) != 1) {
                    //fprintf(stderr, "error reading mapa3[%d][%d]\n", row, col);
                    return 0;
                }
            }
            else if (mapa == 4) {
                // Coloca o conteudo do arquivo TXT dentro da matriz mapa4
                if (fscanf_s(mapa4, "%d", &mapas[row][col]) != 1) {
                    //fprintf(stderr, "error reading mapa4[%d][%d]\n", row, col);
                    return 0;
                }
            }
            else {
                fprintf(stderr, "Nao foi possivel iniciar o mapa\n");
                return -1;
            }
        }
    }
    return mapas;
}

void limparMapas(int** mapa) {
      // ------ Limpando Memória ------
      // Limpando memória do mapa
      for (int row = 0; row < altura; row++) {
          free(mapa[row]);
      }
      free(mapa);
}

/*bool colisao(mapa* ptr) {
    int aux = (ptr->pos_x / 32);
    int auy = (ptr->pos_y / 32);

    int valU = 67;
    int valD = 67;
    int valL = 67;
    int valR = 67;

    if (ptr->pos_y > 32 && ptr->pos_y < height - 32 && auy < 14 && aux < 19) {
        valU = ptr->map[auy][aux];
        valD = ptr->map[auy + 1][aux];
    }
    if (ptr->pos_x > 32 && ptr->pos_x < width - 32 && auy < 15 && aux < 20) {
        valL = ptr->map[auy][aux];
        valR = ptr->map[auy][aux + 1];
    }

    if (valU != 67 && direcao == UP) {
        // UP
        ptr->pos_y += velocidade;
    }
    if (valD != 67 && direcao == DOWN) {
        // DOWN
        ptr->pos_y -= velocidade;
    }
    if (valL != 67 && direcao == LEFT) {
        // LEFT
        ptr->pos_x += velocidade;
    }
    if (valR != 67 && direcao == RIGHT) {
        // RIGHT
        ptr->pos_x -= velocidade;
    }

    if (ptr->escolhaMapa == 4 && ptr->pos_y == 320 && ptr->pos_x == 224) {
        ptr->done = true;
    }
}*/