UIManager* createUIManager() {
    UIManager* manager = (UIManager*)malloc(sizeof(UIManager));
    if (!manager) {
        fprintf(stderr, "Failed to allocate UIManager.\n");
        return NULL;
    }
    manager->screenWidth = 800;
    manager->screenHeight = 600;
    manager->selectedSound = -1;
    manager->selectedPosition = -1;
    return manager;
}