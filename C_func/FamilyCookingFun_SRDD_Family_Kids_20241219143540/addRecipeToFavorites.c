void addRecipeToFavorites(User *user, const char *recipeName) {
    if (user->favoriteRecipesCount < MAX_FAVORITES) {
        strcpy(user->favoriteRecipes[user->favoriteRecipesCount], recipeName);
        user->favoriteRecipesCount++;
        printf("Recipe '%s' added to favorites!\n", recipeName);
    } else {
        printf("Favorite recipes list is full!\n");
    }
}