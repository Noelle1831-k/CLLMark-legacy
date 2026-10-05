DialogueManager* createDialogueManager() {
    DialogueManager *manager = (DialogueManager*)malloc(sizeof(DialogueManager));
    manager->generator = createDialogueGenerator();
    manager->analyzer = createContextAnalyzer();
    return manager;
}