void saveRecipeToUser(char *userName, int recipeID) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            if (users[i].recipeCount < 50) {
                users[i].favoriteRecipes[users[i].recipeCount++] = recipeID;
                printf("Recipe saved to favorites.\n");
                return;
            } else {
                printf("Favorite list is full.\n");
                return;
            }
        }
    }
    printf("User not found.\n");
}