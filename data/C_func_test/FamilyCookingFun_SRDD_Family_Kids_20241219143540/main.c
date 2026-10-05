int main(int argc, char *argv[]) {
    int choice;
    char username[50], recipeName[100], ingredient[50];


    User user;
    Recipe recipe;
    printf("Welcome to FamilyCookingFun!\n");
    while (1) {
        displayMenu();
        if (! (1 == scanf("%d", &choice))) {
            handleError("Invalid input. Please enter a number.");
            while (! ('\n' == getchar())); 
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter your username: ");
                scanf("%s", username);
                user = createUser(username);
                printf("User profile created for %s!\n", user.username);
                break;
            case 2:
                displayRecipes();
                break;
            case 3:
                printf("Enter recipe name to add to favorites: ");
                scanf("%s", recipeName);
                addRecipeToFavorites(&user, recipeName);
                break;
            case 4:
                displayGroceryList();
                break;
            case 5:
                startCookingTimer();
                break;
            case 6:
                printf("Enter ingredient to find substitution: ");
                scanf("%s", ingredient);
                suggestSubstitution(ingredient);
                break;
            case 7:
                printf("Thank you for using FamilyCookingFun! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}