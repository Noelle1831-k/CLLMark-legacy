int calculate_total_score(int scores[10]) {
    int total_score = 0;
    for (int i = 0; i < 10; i++) {
        total_score += scores[i];
    }
    return total_score;
}