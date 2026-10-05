void destroyDialogueManager(DialogueManager *manager) {
    destroyDialogueGenerator(manager->generator);
    destroyContextAnalyzer(manager->analyzer);
    free(manager);
}