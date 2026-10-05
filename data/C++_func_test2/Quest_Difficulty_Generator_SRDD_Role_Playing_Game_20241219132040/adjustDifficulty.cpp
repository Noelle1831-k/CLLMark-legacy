void Quest::adjustDifficulty(int playerSkillLevel) {
    difficulty -= playerSkillLevel * 2; 
    if (difficulty < 1) {
        difficulty = 1; 
    }
}