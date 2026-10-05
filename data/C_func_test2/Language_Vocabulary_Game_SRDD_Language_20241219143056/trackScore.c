void trackScore(int *score, int correct) {
    if (correct) {
        (*score)++;
    }
    printf("Current Score: %d\n", *score);
}