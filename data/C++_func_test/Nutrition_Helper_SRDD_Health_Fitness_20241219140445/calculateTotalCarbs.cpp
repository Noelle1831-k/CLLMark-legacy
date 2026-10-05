double Meal::calculateTotalCarbs() const {
    double total = 0;
    for (size_t i = 0; i < foodItems.size(); i++) {
        total = total + foodItems[i].getCarbs();
    }
    return total;
}