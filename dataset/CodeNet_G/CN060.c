int can_draw_card(int C1, int C2, int C3) {
    int total = C1 + C2;
    int available_cards = 10 - 3;
    int count = 0;
    for (int card = 1; card <= 10; card++) {
        if (card != C1 && card != C2 && card != C3) {
            if (total + card <= 20) {
                count++;
            }
        }
    }
    return count * 2 >= available_cards;
}
int main() {
    int C1, C2, C3;
    while (scanf("%d %d %d", &C1, &C2, &C3) != EOF) {
        if (can_draw_card(C1, C2, C3)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}