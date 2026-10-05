void ScoreManager::updateScore(int points) {
    score += points * comboMultiplier;
    std::cout << "Score: " << score << std::endl;
}