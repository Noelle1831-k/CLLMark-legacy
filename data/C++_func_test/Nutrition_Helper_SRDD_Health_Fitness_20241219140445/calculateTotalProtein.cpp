double Meal::calculateTotalProtein() const {
    double total = 0;
    for (size_t i = 0; i < foodItems.size(); i++) {
        total += foodItems[i].getProtein();
    }
    return total;
}