#define MAX_PLAYERS 10
#define DECK_SIZE 100
void process_game(int players_count, const char *cards) {
    int players[MAX_PLAYERS] = {0};
    int field = 0;
    int current_player = 0;
    for (int i = 0; i < DECK_SIZE; ++i) {
        char card = cards[i];
        if (card == 'M') {
            players[current_player]++;
        } else if (card == 'S') {
            field += players[current_player] + 1;
            players[current_player] = 0;
        } else if (card == 'L') {
            players[current_player] += field + 1;
            field = 0;
        }
        current_player = (current_player + 1) % players_count;
    }
    int temp;
    for (int i = 0; i < players_count - 1; ++i) {
        for (int j = 0; j < players_count - 1 - i; ++j) {
            if (players[j] > players[j + 1]) {
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < players_count; ++i) {
        printf("%d ", players[i]);
    }
    printf("%d\n", field);
}