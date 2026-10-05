#define HANDS 5
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void analyze_hand(int *cards) {
    int frequency[14] = {0};
    int i, max_count = 0, pair_count = 0, three_count = 0, four_count = 0;
    int is_straight = 1;
    for (i = 0; i < HANDS; i++) {
        frequency[cards[i]]++;
    }
    for (i = 1; i <= 13; i++) {
        if (frequency[i] > max_count) {
            max_count = frequency[i];
        }
        if (frequency[i] == 2) {
            pair_count++;
        } else if (frequency[i] == 3) {
            three_count++;
        } else if (frequency[i] == 4) {
            four_count++;
        }
    }
    qsort(cards, HANDS, sizeof(int), compare);
    for (i = 0; i < HANDS - 1; i++) {
        if (cards[i] + 1 != cards[i + 1]) {
            is_straight = 0;
            break;
        }
    }
    if (is_straight || (cards[0] == 1 && cards[1] == 10 && cards[2] == 11 && cards[3] == 12 && cards[4] == 13)) {
        printf("straight\n");
    } else if (four_count == 1) {
        printf("four card\n");
    } else if (three_count == 1 && pair_count == 1) {
        printf("full house\n");
    } else if (three_count == 1) {
        printf("three card\n");
    } else if (pair_count == 2) {
        printf("two pair\n");
    } else if (pair_count == 1) {
        printf("one pair\n");
    } else {
        printf("null\n");
    }
}