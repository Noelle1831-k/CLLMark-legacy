void menu() {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Main Menu ---\n");
        printf("1. Create User Profile\n");
        printf("2. View Profile\n");
        printf("3. Add Recipe\n");
        printf("4. Search Recipes\n");
        printf("5. View Discussions\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                viewProfile();
                break;
            case 3:
                addRecipe();
                break;
            case 4:
                searchRecipes();
                break;
            case 5:
                viewDiscussions();
                break;
            case 0:
                printf("Exiting application...\n");
                saveUserData();
                saveRecipeData();
                saveInteractionData();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}