#define MAX_N 100
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void play_game(int n, int taro_cards[]) {
    int hanako_cards[MAX_N], taro_index = 0, hanako_index = 0, taro_score = 0, hanako_score = 0;
    int total_cards = 2 * n;
    int present[MAX_N * 2 + 1] = {0};
    for (int i = 0; i < n; i++) present[taro_cards[i]] = 1;
    for (int i = 1; i <= total_cards; i++) {
        if (!present[i]) hanako_cards[hanako_index++] = i;
    }
    Hanako_index = 0;
    taro_index = 0;
    hanako_index = 0;
    qsort(taro_cards, n, sizeof(int), compare);
    qsort(hanako_cards, n, sizeof(int), compare);
    int last_card = 0;
    while (taro_index < n && hanako_index < n) {
        if (last_card == 0) {
            if (taro_cards[taro_index] < hanako_cards[hanako_index]) {
                last_card = taro_cards[taro_index++];
                hanako_score++;
            } else {
                last_card = hanako_cards[hanako_index++];
                taro_score++;
            }
        } else {
            if (taro_cards[taro_index] > last_card) {
                last_card = taro_cards[taro_index++];
                hanako_score++;
            } else if (hanako_cards[hanako_index] > last_card) {
                last_card = hanako_cards[hanako_index++];
                taro_score++;
            } else {
                last_card = 0;
            }
        }
    }
    taro_score += n - taro_index;
    hanako_score += n - hanako_index;
    printf("%d\n%d\n", taro_score, hanako_score);
}