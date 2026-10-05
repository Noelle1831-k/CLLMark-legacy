void rankArticles(int *scores, int size) {
    printf("Ranking articles based on relevance...\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
    printf("Ranking complete.\n");
}