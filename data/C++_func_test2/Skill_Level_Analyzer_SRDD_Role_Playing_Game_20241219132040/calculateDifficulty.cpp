void Skill::calculateDifficulty() {
    difficultyRating = log10(requiredAttributes) * complexity + progression / 10.0;
}