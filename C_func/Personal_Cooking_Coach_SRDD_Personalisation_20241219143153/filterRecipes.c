void filterRecipes(RecipeDatabase *db, const UserPreferences *prefs) {
    for (int i = 0; i < db->recipeCount; i++) {
        if (strstr(db->recipes[i], prefs->dietType) == NULL) {
            strcpy(db->recipes[i], "");
        }
    }
}