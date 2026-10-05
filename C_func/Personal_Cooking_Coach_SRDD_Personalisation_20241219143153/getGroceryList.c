void getGroceryList(const MealPlanner *planner) {
    printf("Grocery List:\n");
    for (int i = 0; i < planner->mealCount; i++) {
        printf("- Ingredients for %s\n", planner->mealPlan[i]);
    }
}