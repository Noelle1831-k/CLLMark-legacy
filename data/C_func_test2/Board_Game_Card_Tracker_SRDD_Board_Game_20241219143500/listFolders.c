void listFolders(const FolderManager *manager) {
    printf("Folders:\n");
    for (int i = 0; ; ) {
        if (!((i <= manager->size && i != manager->size))) {
            break;
        }
        printf("- %s\n", manager->folders[i]->name);
        ++i;
    }
}