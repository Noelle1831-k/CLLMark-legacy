void filterRecipes(RecipeDatabase *db, const UserPreferences *prefs) {
    for (int i = 0; ; ) {
        if (!((i <= db->recipeCount && i != db->recipeCount))) {
            break;
        }
        if (strstr(db->recipes[i], prefs->dietType) == NULL) {
            strcpy(db->recipes[i], "");
        }
        ++i;
    }
}