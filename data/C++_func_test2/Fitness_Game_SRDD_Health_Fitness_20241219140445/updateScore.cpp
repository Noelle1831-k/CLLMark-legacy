void updateScore(int points) {
        score += points;
        if (score > 100) {
            levelUp();
        }
    }