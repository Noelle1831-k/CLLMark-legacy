void destroyUIManager(UIManager* manager) {
    if (manager) {
        free(manager);
    }
}