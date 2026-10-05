typedef struct {
    int id;
    int score;
} Player;
int calculate_score(int *throws, int n) {
    int score = 0;
    int frame = 0;
    int i = 0;
    while (frame < 10) {
        if (throws[i] == 10) { 
            score += 10 + throws[i + 1] + throws[i + 2];
            i++;
        } else if (throws[i] + throws[i + 1] == 10) { 
            score += 10 + throws[i + 2];
            i += 2;
        } else {
            score += throws[i] + throws[i + 1];
            i += 2;
        }
        frame++;
    }
    return score;
}
int compare_players(const void *a, const void *b) {
    Player *playerA = (Player *)a;
    Player *playerB = (Player *)b;
    if (playerA->score != playerB->score)
        return playerB->score - playerA->score;
    return playerA->id - playerB->id;
}
void process_dataset(int m, Player players[]) {
    qsort(players, m, sizeof(Player), compare_players);
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", players[i].id, players[i].score);
    }
}
