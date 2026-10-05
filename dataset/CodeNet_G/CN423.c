int main() {
    int n, aCard, bCard;
    while (1) {
        int aScore = 0, bScore = 0;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &aCard, &bCard);
            if (aCard > bCard) {
                aScore += aCard + bCard;
            } else if (aCard < bCard) {
                bScore += aCard + bCard;
            }
        }
        printf("%d %d\n", aScore, bScore);
    }
    return 0;
}