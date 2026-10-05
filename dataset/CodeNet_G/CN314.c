int calculateScore(int N, int scores[]) {
    int maxScore = 0;
    for (int A = 1; A <= 100; A++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (scores[i] >= A) {
                count++;
            }
        }
        if (count >= A) {
            maxScore = A;
        }
    }
    return maxScore;
}