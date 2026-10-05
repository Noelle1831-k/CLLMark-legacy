void Quest::generateQuest() {
    name = Utility::getRandomString(10);
    description = Utility::getRandomString(50);
    enemyStrength = Utility::getRandomNumber(1, 100);
    requiredSkills = Utility::getRandomNumber(1, 10);
    timeConstraint = Utility::getRandomNumber(1, 24);
    calculateDifficulty();
}