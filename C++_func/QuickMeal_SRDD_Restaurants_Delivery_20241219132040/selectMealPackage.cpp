MealPackage UserInterface::selectMealPackage(vector<Restaurant>& restaurants) {
    int choice;
    cout << "Select a meal package by number: ";
    cin >> choice;
    return restaurants[0].getMenu()[choice - 1];
}