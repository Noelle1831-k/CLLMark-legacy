int main() {
    Library myLibrary;
    initialize_library(&myLibrary);
    int choice;
    while (1) {
        printf("Welcome to the Book Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Create Shelf\n");
        printf("6. Add Book to Shelf\n");
        printf("7. Generate Report\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book(&myLibrary);
                break;
            case 2:
                remove_book(&myLibrary);
                break;
            case 3:
                search_books(&myLibrary);
                break;
            case 4:
                display_books(&myLibrary);
                break;
            case 5:
                create_shelf(&myLibrary);
                break;
            case 6:
                add_book_to_shelf(&myLibrary);
                break;
            case 7:
                generate_report(&myLibrary);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}