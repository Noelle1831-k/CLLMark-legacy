void completeQuestInManager(QuestManager *manager, int index) {
    if (index >= 0 && manager->questCount > index) {
        completeQuest(manager->quests[index]);
    }
}