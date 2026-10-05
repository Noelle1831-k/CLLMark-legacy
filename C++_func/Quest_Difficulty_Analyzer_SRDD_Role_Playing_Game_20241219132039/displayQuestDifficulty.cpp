void QuestAnalyzer::displayQuestDifficulty(const Quest& quest, double difficulty) {
    cout << "--------------------------------------------" << endl;
    cout << "Quest Analysis Report:" << endl;
    quest.displayQuestDetails();
    cout << "Overall Difficulty Rating: " << difficulty << endl;
    cout << "--------------------------------------------" << endl;
}