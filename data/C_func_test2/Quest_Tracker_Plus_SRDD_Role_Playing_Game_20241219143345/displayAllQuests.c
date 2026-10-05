void displayAllQuests(const QuestManager *manager) {
    for (int i = 0; i < manager->questCount; i++) {
        displayQuest(manager->quests[i]);
    }
}