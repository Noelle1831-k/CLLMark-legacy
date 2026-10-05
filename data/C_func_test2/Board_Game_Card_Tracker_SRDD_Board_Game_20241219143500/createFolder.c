void createFolder(FolderManager *manager) {
    if (manager->size >= manager->capacity) {
        manager->capacity *= 2;
        manager->folders = (Folder **)realloc(manager->folders, manager->capacity * sizeof(Folder *));
    }
    char name[50];
    printf("Enter folder name: ");
    scanf("%s", name);
    Folder *folder = (Folder *)malloc(sizeof(Folder));
    strcpy(folder->name, name);
    manager->folders[manager->size++] = folder;
    printf("Folder '%s' created.\n", name);
}