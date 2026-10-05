int main() {
    printf("Welcome to BookNote!\n");
    int choice;
    while (1) {
        printLine();
        printf("Menu:\n");
        printf("1. Add Book\n");
        printf("2. Add Note\n");
        printf("3. Search\n");
        printf("4. List Books\n");
        printf("5. List Notes\n");
        printf("6. Exit\n");
        printLine();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addNote();
                break;
            case 3:
                search();
                break;
            case 4:
                listBooks();
                break;
            case 5:
                listNotes();
                break;
            case 6:
                printf("Exiting BookNote. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}