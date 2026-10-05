void QuestManager::displayAllQuests(UI &ui) {
    if (quests.empty()) {
        cout << "No quests available." << endl;
        return;
    }
    for (int i = 0; i < quests.size(); i++) {
        cout << i + 1 << ". " << quests[i].getName() << " - " << quests[i].getProgress() << "% complete" << endl;
    }
}