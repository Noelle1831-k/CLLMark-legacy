void generateMealPlan(MealPlanner *planner, const RecipeDatabase *db) {
    int count = 0;
    for (int i = 0; i < db->recipeCount && count < sizeof(planner->mealPlan) / sizeof(planner->mealPlan[0]); i++) {
        if (strlen(db->recipes[i]) > 0) {
            strcpy(planner->mealPlan[count++], db->recipes[i]);
        }
    }
    planner->mealCount = count;
}