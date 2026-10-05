void Meal::displayMealDetails() const {
    cout << "Meal Details:" << endl;
    for (size_t i = 0; i < foodItems.size(); i++) {
        foodItems[i].display();
    }
    cout << "Total Calories: " << calculateTotalCalories() << endl;
    cout << "Total Protein: " << calculateTotalProtein() << "g" << endl;
    cout << "Total Carbs: " << calculateTotalCarbs() << "g" << endl;
    cout << "Total Fats: " << calculateTotalFats() << "g" << endl;
}