int main() {
    printf("Welcome to Read--model GPT_4O &Learn!\n");
    loadLibrary();
    loadSettings();
    int choice;
    while (1) {
        printf("\n1. Browse Categories\n2. Search Book\n3. Bookmark Content\n4. Highlight Text\n5. Annotate Text\n6. Customize Reading\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                browseCategories();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                bookmarkContent();
                break;
            case 4:
                highlightText();
                break;
            case 5:
                annotateText();
                break;
            case 6:
                customizeReading();
                break;
            case 7:
                saveSettings();
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}