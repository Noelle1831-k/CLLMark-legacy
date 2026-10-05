void QuestManager::listQuests() const {
    if (quests.empty()) {
        cout << "No quests available.\n";
        return;
    }
    for (int i = 0; i < quests.size(); i++) {
        cout << quests[i].getDetails() << endl;
    }
}