void QuestManager::filterQuestsByTag(string tag) {
    for (size_t i = 0; i < quests.size(); i++) {
        if (quests[i].hasTag(tag)) {
            quests[i].displayQuestDetails();
        }
    }
}