void updateQuestInManager(QuestManager *manager, int index, const char *description, const char *rewards, char tags[][MAX_NAME_LENGTH], int tagCount) {
    if (index >= 0 && index < manager->questCount) {
        updateQuest(manager->quests[index], description, rewards, tags, tagCount);
    }
}