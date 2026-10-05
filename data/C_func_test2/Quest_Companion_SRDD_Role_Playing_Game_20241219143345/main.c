int main() {
    QuestManager *questManager = createQuestManager();
    UserInterface *ui = createUserInterface(questManager);
    DataStorage *dataStorage = createDataStorage();
    loadQuests(dataStorage, questManager);
    runUserInterface(ui);
    saveQuests(dataStorage, questManager);
    destroyUserInterface(ui);
    destroyQuestManager(questManager);
    destroyDataStorage(dataStorage);
    return 0;
}