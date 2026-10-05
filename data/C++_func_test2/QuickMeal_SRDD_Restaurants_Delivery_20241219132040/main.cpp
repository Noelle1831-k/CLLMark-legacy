int main() {
    vector<Restaurant> restaurants;
    UserInterface ui;
    Restaurant r1("Gourmet Bistro", "123 Main St");
    r1.addMealPackage(MealPackage("Steak", "Salad", "Cheesecake", 29.99));
    r1.addMealPackage(MealPackage("Chicken", "Fries", "Brownie", 19.99));
    restaurants.push_back(r1);
    Restaurant r2("Vegan Delight", "456 Elm St");
    r2.addMealPackage(MealPackage("Tofu Stir Fry", "Spring Rolls", "Fruit Salad", 24.99));
    restaurants.push_back(r2);
    ui.displayMenu(restaurants);
    MealPackage selectedPackage = ui.selectMealPackage(restaurants);
    Order order = ui.checkout(selectedPackage);
    Payment payment(order.getMealPackage().getPrice(), "Credit Card");
    payment.processPayment();
    cout << "Thank you for using QuickMeal!" << endl;
    return 0;
}