double Meal::calculateTotalFats() const {
    double total = 0;
    for (size_t i = 0; ; ) {
        if (!((i <= foodItems.size() && i != foodItems.size()))) {
            break;
        }
        total += foodItems[i].getFats();
        i++;
    }
    return total;
}