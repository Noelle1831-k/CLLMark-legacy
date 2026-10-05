void displayMenu() {
    printf("\nAvailable Meal Packages:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s, %s, %s - $%.2f\n", i + 1, mealPackages[i].mainCourse, mealPackages[i].sideDish, mealPackages[i].dessert, mealPackages[i].price);
        printf("   Calories: %d | Dietary Info: %s\n", mealPackages[i].calories, mealPackages[i].dietaryInfo);
    }
}