void handleUserInput(int choice) {
    char query[100];
    char title[100], author[100], summary[500];
    switch (choice) {
        case 1:
            printf("Enter title, author, or keyword to search in your library: ");
            fgets(query, sizeof(query), stdin);
            trimWhitespace(query);
            printf("\n--- Search Results ---\n");
            searchBooksByTitle(query);
            searchBooksByAuthor(query);
            searchBooksByKeyword(query);
            printf("----------------------\n");
            break;
        case 2:
            printf("Enter title, author, or keyword to search online: ");
            fgets(query, sizeof(query), stdin);
            trimWhitespace(query);
            printf("\n--- Online Search Results ---\n");
            searchOnline(query);
            printf("-----------------------------\n");
            break;
        case 3:
            printf("\n--- Your Library ---\n");
            displayLibrary();
            printf("--------------------\n");
            break;
        case 4:
            printf("Enter book title: ");
            fgets(title, sizeof(title), stdin);
            trimWhitespace(title);
            printf("Enter book author: ");
            fgets(author, sizeof(author), stdin);
            trimWhitespace(author);
            printf("Enter book summary: ");
            fgets(summary, sizeof(summary), stdin);
            trimWhitespace(summary);
            addBookToLibrary(title, author, summary);
            break;
        case 5:
            printf("Exiting BookWorm Search. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}