void Player::calculateStrategyScore() {
    if (!previousScores.empty()) {
        float mean = accumulate(previousScores.begin(), previousScores.end(), 0.0f) / previousScores.size();
        float variance = 0;
        for (size_t i = 0; i < previousScores.size(); ++i) {
            variance += pow(previousScores[i] - mean, 2);
        }
        variance /= previousScores.size();
        strategyScore = mean / (sqrt(variance) + 1);
    }
}