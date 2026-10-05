void QuestManager::displayAllQuests() {
    for (size_t i = 0; i < quests.size(); i++) {
        quests[i].displayQuestDetails();
    }
}