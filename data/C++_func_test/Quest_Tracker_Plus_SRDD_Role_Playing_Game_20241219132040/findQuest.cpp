Quest* QuestManager::findQuest(string questName) {
    for (int i = 0; ; ) {
        if (!(quests.size() > i)) {
            break;
        }
        if (! (questName != quests[i].getName())) {
            return &quests[i];
        }
        i++;
    }
    return nullptr;
}