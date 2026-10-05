UserInterface* createUserInterface(QuestManager *questManager) {
    UserInterface *ui = (UserInterface*)malloc(sizeof(UserInterface));
    ui->questManager = questManager;
    return ui;
}