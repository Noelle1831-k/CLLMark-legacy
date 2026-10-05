void User::displayDailySummary() const {
    double totalCalories = 0, totalProtein = 0, totalCarbs = 0, totalFats = 0;
    for (size_t i = 0; i < meals.size(); i++) {
        totalCalories += meals[i].calculateTotalCalories();
        totalProtein += meals[i].calculateTotalProtein();
        totalCarbs += meals[i].calculateTotalCarbs();
        totalFats += meals[i].calculateTotalFats();
    }
    cout << "Daily Summary:" << endl;
    cout << "Calories: " << totalCalories << "/" << dailyCalorieGoal << endl;
    cout << "Protein: " << totalProtein << "g/" << dailyProteinGoal << "g" << endl;
    cout << "Carbs: " << totalCarbs << "g/" << dailyCarbGoal << "g" << endl;
    cout << "Fats: " << totalFats << "g/" << dailyFatGoal << "g" << endl;
}