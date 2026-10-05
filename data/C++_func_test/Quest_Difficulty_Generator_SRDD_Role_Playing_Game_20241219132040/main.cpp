int main() {
    srand(static_cast<unsigned int>(time(0))); 
    cout << "Welcome to the Quest Difficulty Generator!" << endl;
    Player player;
    player.getPlayerPreferences();
    QuestGenerator questGen;
    vector<Quest> quests;
    int numQuests = 3; 
    for (int i = 0; i < numQuests; i++) {
        quests.push_back(questGen.generateDynamicQuest(player));
    }
    cout << "Generated Quests:" << endl;
    for (int i = 0; i < quests.size(); i++) {
        cout << "Quest " << i + 1 << " Details:" << endl;
        cout << "Name: " << quests[i].getName() << endl;
        cout << "Description: " << quests[i].getDescription() << endl;
        cout << "Enemy Strength: " << quests[i].getEnemyStrength() << endl;
        cout << "Required Skills: " << quests[i].getRequiredSkills() << endl;
        cout << "Time Constraint: " << quests[i].getTimeConstraint() << " hours" << endl;
        cout << "Difficulty Level: " << quests[i].getDifficulty() << endl;
        cout << "-----------------------------" << endl;
    }
    return 0;
}