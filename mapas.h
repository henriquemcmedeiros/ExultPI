#include <../../../../../header.h>

int** geraMapas(int mapa);
void loadMap();
void limparMapas(int** mapa);
void trocarMapas(mapa* ptr);
int colisao(mapa* ptr, int mapa, int minigameAtual);

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

int colisao(mapa* ptr, int mapa, int minigameAtual) {
	// ------ Colisão ------
	// ------ MAPA  1 ------
	if (ptr->escolhaMapa == 1) {
		// Parede direita
		if (ptr->pos_y <= 280) {
			ptr->pos_x = min(480, ptr->pos_x);
		}
		// Parede esquerda
		ptr->pos_x = max(96, ptr->pos_x);
		// Parede superior e inferior
		ptr->pos_y = max(96, min(352, ptr->pos_y));
		// Parede superior corredor
		if (ptr->pos_x >= 484) {
			ptr->pos_y = max(288, ptr->pos_y);
		}
	}
	// ------ MAPA  2 ------
	else if (ptr->escolhaMapa == 2) {
		// Parede direita
		ptr->pos_x = min(512, ptr->pos_x);
		// Parede esquerda corredor
		if (ptr->pos_y >= 358) {
			ptr->pos_x = max(448, ptr->pos_x);
		}
		// Parede superior
		ptr->pos_y = max(96, ptr->pos_y);
		if (ptr->pos_x != 96 && ptr->pos_y >= 288 && ptr->pos_y <= 288) {
			ptr->pos_y = max(32 * 9, ptr->pos_y);
		}
		// Parede inferior
		if (ptr->pos_x < 448) {
			ptr->pos_y = min(352, ptr->pos_y);
		}
		// Parede superior portas e atualizações
		switch (minigameAtual)
		{
		case 0:
			ptr->map[8][3] = 64;
			if (ptr->pos_x != 96) {
				ptr->pos_y = max(288, ptr->pos_y);
			}
			break;
		case 1:
			ptr->map[8][8] = 64;
			if (ptr->pos_x != 256) {
				ptr->pos_y = max(288, ptr->pos_y);
			}
			break;
		case 2:
			ptr->map[8][13] = 64;
			if (ptr->pos_x != 416) {
				ptr->pos_y = max(288, ptr->pos_y);
			}
			break;
		default:
			ptr->pos_y = max(288, ptr->pos_y);
			break;
		}
		if (ptr->pos_x == 96 && ptr->pos_y == 256) {
			// MINIGAME 1
			ptr->map[8][3] = 65;
			minigameAtual++;
		}
		if (ptr->pos_x == 256 && ptr->pos_y == 256) {
			// MINIGAME 2
			ptr->map[8][8] = 65;
			minigameAtual++;
		}
		if (ptr->pos_x == 416 && ptr->pos_y == 256) {
			// MINIGAME 3
			ptr->map[8][13] = 65;
			minigameAtual++;
		}
	}
	// ------ MAPA  3 ------
	else if (ptr->escolhaMapa == 3) {
		// Parede Esquerda e direita principais
		if (ptr->pos_y < 10 * 32 - 4) {
			ptr->pos_x = max(5 * 32, min(16 * 32, ptr->pos_x));
		}
		// Parede Superior e inferior principais
		if (ptr->pos_x < 14 * 32 - 4) {
			ptr->pos_y = max(4 * 32, min(12 * 32, ptr->pos_y));
		}
		// Parede superior corredor esquerda
		if (ptr->pos_x < 5 * 32) {
			ptr->pos_y = max(10 * 32, ptr->pos_y);
		}
		// Parede esquerda corredor BOSS
		if (ptr->pos_y < 4 * 32) {
			ptr->pos_x = max(14 * 32, ptr->pos_x);
		}
		// Parede Superior BOSS
		if (ptr->pos_x > 9 * 32 + 4) {
			ptr->pos_y = min(7 * 32, ptr->pos_y);
		}
		// Parede Direita BOSS
		if (ptr->pos_y > 7 * 32) {
			ptr->pos_x = min(9 * 32, ptr->pos_x);
		}
	}
	// ------ MAPA  4 ------
	else if (ptr->escolhaMapa == 4) {
		// Parede direita
		if (ptr->pos_y <= 32 * 10 - 6) {
			ptr->pos_x = min(17 * 32, ptr->pos_x);
		}
		// Parede esquerda
		if (ptr->pos_y != 160) {
			ptr->pos_x = max(32 * 8, ptr->pos_x);
		}
		// Parede superior e inferior
		ptr->pos_y = max(96, min(12 * 32, ptr->pos_y));
		// Parede superior corredor
		if (ptr->pos_x >= 18 * 32 - 24) {
			ptr->pos_y = max(320, ptr->pos_y);
		}
		// Fechar mapa
		if (ptr->pos_x == 32 * 7 && ptr->pos_y == 32 * 5) {
			ptr->done = true;
		}
	}
	return max(minigameAtual, 0);
}
