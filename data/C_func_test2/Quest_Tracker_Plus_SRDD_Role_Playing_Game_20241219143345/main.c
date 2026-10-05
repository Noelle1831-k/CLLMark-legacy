int main() {
    QuestManager *questManager = createQuestManager();
    QuestGuide *questGuide = createQuestGuide();
    UserInterface *ui = createUserInterface(questManager, questGuide);
    ReminderSystem *reminderSystem = createReminderSystem(questManager);
    while (1) {
        displayMainMenu(ui);
        int choice = getUserChoice();
        processUserChoice(ui, choice);
        checkReminders(reminderSystem);
    }
    destroyQuestManager(questManager);
    destroyQuestGuide(questGuide);
    destroyUserInterface(ui);
    destroyReminderSystem(reminderSystem);
    return 0;
}