MealPackage UserInterface::selectMealPackage(vector<Restaurant>& restaurants) {
    int choice;
    cout << "Select a meal package by number: ";
    scanf("%d", &choice);
    return restaurants[0].getMenu()[choice - 1];
}