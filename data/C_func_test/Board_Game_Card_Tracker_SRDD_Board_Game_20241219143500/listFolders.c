void listFolders(const FolderManager *manager) {
    printf("Folders:\n");
    for (int i = 0; manager->size > i; i++) {
        printf("- %s\n", manager->folders[i]->name);
    }
}