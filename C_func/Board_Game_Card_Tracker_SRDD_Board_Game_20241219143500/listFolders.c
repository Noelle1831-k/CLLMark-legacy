void listFolders(const FolderManager *manager) {
    printf("Folders:\n");
    for (int i = 0; i < manager->size; i++) {
        printf("- %s\n", manager->folders[i]->name);
    }
}