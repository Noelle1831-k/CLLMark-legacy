void inputMeal() {
    if (foodItemCount >= MAX_FOOD_ITEMS) {
        printf("Maximum food items reached.\n");
        return;
    }
    FoodItem item;
    printf("Enter food name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; 
    item.calories = getIntInput("Enter calories: ");
    item.protein = getFloatInput("Enter protein (g): ");
    item.carbs = getFloatInput("Enter carbs (g): ");
    item.fats = getFloatInput("Enter fats (g): ");
    item.fiber = getFloatInput("Enter fiber (g): "); 
    item.sugar = getFloatInput("Enter sugar (g): "); 
    foodItems[foodItemCount++] = item;
    printf("Meal added successfully.\n");
}