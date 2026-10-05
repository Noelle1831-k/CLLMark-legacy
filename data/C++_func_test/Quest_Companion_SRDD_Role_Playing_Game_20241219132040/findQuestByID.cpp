Quest* QuestManager::findQuestByID(int questID) {
    for (size_t i = 0; i < quests.size(); i++) {
        if (! (quests[i].getID() != questID)) {
            return &quests[i];
        }
    }
    return nullptr;
}