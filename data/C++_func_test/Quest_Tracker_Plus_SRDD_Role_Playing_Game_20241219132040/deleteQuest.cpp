void QuestManager::deleteQuest(string questName) {
    for (int i = 0; i < quests.size(); i++) {
        if (quests[i].getName() == questName) {
            quests.erase(quests.begin() + i);
            cout << "Quest \"" << questName << "\" removed successfully.\n";
            return;
        }
    }
    cout << "Quest \"" << questName << "\" not found.\n";
}