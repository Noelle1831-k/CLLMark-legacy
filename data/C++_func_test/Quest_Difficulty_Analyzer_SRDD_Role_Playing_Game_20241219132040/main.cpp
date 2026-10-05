int main() {
    int enemyStrength, requiredSkills, timeConstraints;
    do {
        std::cout << "Enter enemy strength (positive integer): ";
        std::cin >> enemyStrength;
        if (enemyStrength < 0) {
            std::cout << "Invalid input. Enemy strength must be a positive integer.\n";
        }
    } while (enemyStrength < 0);
    do {
        std::cout << "Enter required skills (positive integer): ";
        std::cin >> requiredSkills;
        if (requiredSkills < 0) {
            std::cout << "Invalid input. Required skills must be a positive integer.\n";
        }
    } while (requiredSkills < 0);
    do {
        std::cout << "Enter time constraints (positive integer): ";
        std::cin >> timeConstraints;
        if (timeConstraints < 0) {
            std::cout << "Invalid input. Time constraints must be a positive integer.\n";
        }
    } while (timeConstraints < 0);
    Quest quest(enemyStrength, requiredSkills, timeConstraints);
    DifficultyCalculator calculator;
    int difficultyRating = calculator.calculateRating(enemyStrength, requiredSkills, timeConstraints);
    std::cout << "The difficulty rating for the quest is: " << difficultyRating << std::endl;
    Player player(10, 5); 
    if (player.canAttemptQuest(quest)) {
        std::cout << "You are ready to take on this quest!" << std::endl;
    } else {
        std::cout << "You need to level up or acquire more resources." << std::endl;
    }
    return 0;
}