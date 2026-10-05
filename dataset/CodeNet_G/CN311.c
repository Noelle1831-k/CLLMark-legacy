int calculateScore(int fishCount1, int fishCount2, int scorePerFish1, int scorePerFish2, int bonus1, int bonus2) {
    int totalScore = fishCount1 * scorePerFish1 + fishCount2 * scorePerFish2;
    totalScore += (fishCount1 / 10) * bonus1;
    totalScore += (fishCount2 / 20) * bonus2;
    return totalScore;
}
void determineWinner(int h1, int h2, int k1, int k2, int a, int b, int c, int d) {
    int hiroshiScore = calculateScore(h1, h2, a, b, c, d);
    int kenjiroScore = calculateScore(k1, k2, a, b, c, d);
    if (hiroshiScore > kenjiroScore) {
        printf("hiroshi\n");
    } else if (kenjiroScore > hiroshiScore) {
        printf("kenjiro\n");
    } else {
        printf("even\n");
    }
}