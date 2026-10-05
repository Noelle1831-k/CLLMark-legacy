void calculateNutrition(NutritionalInfo *info, const RecipeDatabase *db) {
    for (int i = 0; i < db->recipeCount; i++) {
        if (strlen(db->recipes[i]) > 0) {
            printf("Nutritional Info for %s: Calories: 200, Protein: 5g, Carbs: 30g, Fat: 10g\n", db->recipes[i]);
        }
    }
}