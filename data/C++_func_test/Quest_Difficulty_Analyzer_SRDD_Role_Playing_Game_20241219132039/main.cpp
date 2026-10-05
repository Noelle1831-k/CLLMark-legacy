int main() {
    cout << "Welcome to the RPG Quest Difficulty Analyzer!" << endl;
    cout << "--------------------------------------------" << endl;
    QuestAnalyzer analyzer;
    Quest userQuest = analyzer.collectQuestData();
    DifficultyCalculator calculator;
    double difficulty = calculator.getOverallDifficulty(userQuest);
    analyzer.displayQuestDifficulty(userQuest, difficulty);
    cout << "Thank you for using the RPG Quest Difficulty Analyzer. Goodbye!" << endl;
    return 0;
}