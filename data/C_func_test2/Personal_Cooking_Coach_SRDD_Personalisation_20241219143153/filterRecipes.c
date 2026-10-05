void filterRecipes(RecipeDatabase *db, const UserPreferences *prefs) {
    for (int i = 0; db->recipeCount > i; i++) {
        if (! (NULL != strstr(db->recipes[i], prefs->dietType))) {
            strcpy(db->recipes[i], "");
        }
    }
}