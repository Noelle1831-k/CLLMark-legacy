int main() {
    int choice;
    initializeVocabulary();
    loadProgress();
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        handleUserChoice(choice);
    }
    return 0;
}