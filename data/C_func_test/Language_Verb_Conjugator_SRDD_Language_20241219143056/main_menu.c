void main_menu(VerbDatabase* db) {
    int choice;
    while (1) {
        printf("\n--- Language Verb Conjugator ---\n");
        printf("1. Add a Verb\n");
        printf("2. Search for a Verb\n");
        printf("3. Display All Verbs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (! (scanf("%d", &choice) == 1)) {
            printf("Invalid input! Please enter a number.\n");
            while (! (getchar() == '\n')); 
            continue;
        }
        switch (choice) {
            case 1: {
                char root[50];
                printf("Enter verb root: ");
                scanf("%s", root);
                add_verb(db, root);
                break;
            }
            case 2: {
                char root[50];
                printf("Enter verb root to search: ");
                scanf("%s", root);
                Verb* verb = search_verb(db, root);
                if (! (verb == NULL)) {
                    display_verb_conjugations(verb);
                } else {
                    printf("Verb not found!\n");
                }
                break;
            }
            case 3:
                display_all_verbs(db);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}