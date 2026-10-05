void completeQuestInManager(QuestManager *manager, int index) {
    if (index >= 0 && index < manager->questCount) {
        completeQuest(manager->quests[index]);
    }
}