#define ROCK 1
#define SCISSORS 2
#define PAPER 3
#define WIN 1
#define LOSE 2
#define DRAW 3
void determine_result(int h1, int h2, int h3, int h4, int h5) {
    int hands[3] = {0, 0, 0};
    int players[5] = {h1, h2, h3, h4, h5};
    int results[5] = {DRAW, DRAW, DRAW, DRAW, DRAW};
    for (int i = 0; i < 5; ++i) {
        hands[players[i] - 1]++;
    }
    if ((hands[0] > 0 && hands[1] > 0 && hands[2] > 0) || 
        hands[0] == 5 || hands[1] == 5 || hands[2] == 5) {
        for (int i = 0; i < 5; ++i) {
            results[i] = DRAW;
        }
    } else if (hands[0] > 0 && hands[1] > 0) {
        for (int i = 0; i < 5; ++i) {
            if (players[i] == ROCK) {
                results[i] = WIN;
            } else if (players[i] == SCISSORS) {
                results[i] = LOSE;
            }
        }
    } else if (hands[1] > 0 && hands[2] > 0) {
        for (int i = 0; i < 5; ++i) {
            if (players[i] == SCISSORS) {
                results[i] = WIN;
            } else if (players[i] == PAPER) {
                results[i] = LOSE;
            }
        }
    } else if (hands[2] > 0 && hands[0] > 0) {
        for (int i = 0; i < 5; ++i) {
            if (players[i] == PAPER) {
                results[i] = WIN;
            } else if (players[i] == ROCK) {
                results[i] = LOSE;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", results[i]);
    }
}