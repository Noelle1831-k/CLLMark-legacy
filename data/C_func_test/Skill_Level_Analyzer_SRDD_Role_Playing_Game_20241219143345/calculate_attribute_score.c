int calculate_attribute_score(int attributes[]) {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        score += attributes[i] * (i + 1);
    }
    return score;
}