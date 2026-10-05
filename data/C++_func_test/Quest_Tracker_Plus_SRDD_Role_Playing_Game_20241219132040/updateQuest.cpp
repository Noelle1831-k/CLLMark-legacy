void QuestManager::updateQuest(string questName, string newStatus) {
    for (int i = 0; i < quests.size(); i++) {
        if (quests[i].getName() == questName) {
            quests[i].updateStatus(newStatus);
            cout << "Quest \"" << questName << "\" updated successfully.\n";
            return;
        }
    }
    cout << "Quest \"" << questName << "\" not found.\n";
}