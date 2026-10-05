void viewDailySummary() {
    int totalCalories = 0;
    float totalProtein = 0.0, totalCarbs = 0.0, totalFats = 0.0, totalFiber = 0.0, totalSugar = 0.0;
    for (int i = 0; i < foodItemCount; i++) {
        totalCalories += foodItems[i].calories;
        totalProtein += foodItems[i].protein;
        totalCarbs += foodItems[i].carbs;
        totalFats += foodItems[i].fats;
        totalFiber += foodItems[i].fiber; 
        totalSugar += foodItems[i].sugar; 
    }
    printf("Daily Summary:\n");
    printf("Total Calories: %d\n", totalCalories);
    printf("Total Protein: %.2f g\n", totalProtein);
    printf("Total Carbs: %.2f g\n", totalCarbs);
    printf("Total Fats: %.2f g\n", totalFats);
    printf("Total Fiber: %.2f g\n", totalFiber); 
    printf("Total Sugar: %.2f g\n", totalSugar); 
}