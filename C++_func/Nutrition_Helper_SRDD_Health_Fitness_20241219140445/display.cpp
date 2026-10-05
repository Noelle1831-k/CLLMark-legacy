void FoodItem::display() const {
    cout << fixed << setprecision(2);
    cout << "Food: " << name << ", Calories: " << calories
         << ", Protein: " << protein << "g, Carbs: " << carbs
         << "g, Fats: " << fats << "g" << endl;
}