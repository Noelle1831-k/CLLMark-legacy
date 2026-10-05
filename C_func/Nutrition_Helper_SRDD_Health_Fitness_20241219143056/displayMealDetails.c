void displayMealDetails(FoodItem item) {
    printf("Meal: %s\n", item.name);
    printf("Calories: %d\n", item.calories);
    printf("Protein: %.2f g\n", item.protein);
    printf("Carbs: %.2f g\n", item.carbs);
    printf("Fats: %.2f g\n", item.fats);
    printf("Fiber: %.2f g\n", item.fiber); 
    printf("Sugar: %.2f g\n", item.sugar); 
}