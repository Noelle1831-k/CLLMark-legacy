#define MAX_PLAYERS 200
#define GAMES 3
void calculate_scores(int n, int guesses[MAX_PLAYERS][GAMES], int scores[MAX_PLAYERS]) {
    for (int k = 0; k < GAMES; k++) {
        int count[101] = {0};
        for (int i = 0; i < n; i++) {
            count[guesses[i][k]]++;
        }
        for (int i = 0; i < n; i++) {
            if (count[guesses[i][k]] == 1) {
                scores[i] += guesses[i][k];
            }
        }
    }
}
int main() {
    int n;
    int guesses[MAX_PLAYERS][GAMES];
    int scores[MAX_PLAYERS] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < GAMES; j++) {
            scanf("%d", &guesses[i][j]);
        }
    }
    calculate_scores(n, guesses, scores);
    for (int i = 0; i < n; i++) {
        printf("%d\n", scores[i]);
    }
    return 0;
}