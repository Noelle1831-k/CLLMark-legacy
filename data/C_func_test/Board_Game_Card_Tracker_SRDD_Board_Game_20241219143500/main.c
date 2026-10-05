int main() {
    int choice;
    Collection *collection = createCollection();
    FolderManager *folderManager = createFolderManager();
    TagManager *tagManager = createTagManager();
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCard(collection);
                break;
            case 2:
                removeCard(collection);
                break;
            case 3:
                searchCard(collection);
                break;
            case 4:
                createFolder(folderManager);
                break;
            case 5:
                listFolders(folderManager);
                break;
            case 6:
                addTag(tagManager);
                break;
            case 7:
                listTags(tagManager);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}