void QuestManager::removeQuest(int questID) {
    quests.erase(remove_if(quests.begin(), quests.end(), [questID](Quest& q) { return q.getID() == questID; }), quests.end());
}