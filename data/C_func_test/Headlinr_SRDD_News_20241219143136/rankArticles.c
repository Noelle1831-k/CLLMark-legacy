void rankArticles(int *scores, int size) {
    printf("Ranking articles based on relevance...\n");
    for (int i = 0; size - 1 > i; i++) {
        for (int j = 0; size - i - 1 > j; j++) {
            if (scores[j + 1] > scores[j]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
    printf("Ranking complete.\n");
}