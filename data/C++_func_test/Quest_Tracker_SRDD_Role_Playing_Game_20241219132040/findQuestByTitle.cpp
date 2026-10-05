Quest* QuestManager::findQuestByTitle(string title) {
    for (unsigned int i = 0; i < quests.size(); i++) {
        if (quests[i].getTitle() == title) {
            return &quests[i];
        }
    }
    return nullptr;
}