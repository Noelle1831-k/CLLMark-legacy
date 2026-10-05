void NutritionHelper::run() {
    cout << "Welcome to NutritionHelper!" << endl;
    double calories, protein, carbs, fats;
    cout << "Set your daily nutritional goals:" << endl;
    cout << "Calories: ";
    cin >> calories;
    cout << "Protein (g): ";
    cin >> protein;
    cout << "Carbs (g): ";
    cin >> carbs;
    cout << "Fats (g): ";
    cin >> fats;
    user.setGoals(calories, protein, carbs, fats);
    char choice;
    do {
        Meal meal;
        cout << "Enter a new meal:" << endl;
        char addMore;
        do {
            string name;
            double cal, prot, carb, fat;
            cout << "Food name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Calories: ";
            cin >> cal;
            cout << "Protein (g): ";
            cin >> prot;
            cout << "Carbs (g): ";
            cin >> carb;
            cout << "Fats (g): ";
            cin >> fat;
            FoodItem item(name, cal, prot, carb, fat);
            meal.addFoodItem(item);
            cout << "Add another food item? (y/n): ";
            cin >> addMore;
        } while (addMore == 'y' || addMore == 'Y');
        user.addMeal(meal);
        cout << "Add another meal? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    user.displayDailySummary();
    cout << "Thank you for using NutritionHelper!" << endl;
}