UserInterface *createUserInterface(QuestManager *manager, QuestGuide *guide) {
    UserInterface *ui = (UserInterface *)malloc(sizeof(UserInterface));
    ui->questManager = manager;
    ui->questGuide = guide;
    return ui;
}