FolderManager *createFolderManager() {
    FolderManager *manager = (FolderManager *)malloc(sizeof(FolderManager));
    manager->size = 0;
    manager->capacity = 5;
    manager->folders = (Folder **)malloc(manager->capacity * sizeof(Folder *));
    return manager;
}