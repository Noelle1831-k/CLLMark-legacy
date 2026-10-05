Quest* QuestManager::findQuest(string questName) {
    for (int i = 0; i < quests.size(); i++) {
        if (quests[i].getName() == questName) {
            return &quests[i];
        }
    }
    return nullptr;
}