void UserInterface::displayMenu(vector<Restaurant>& restaurants) {
    cout << "Available Restaurants and Meal Packages:" << endl;
    for (size_t i = 0; i < restaurants.size(); ++i) {
        cout << "Restaurant: " << restaurants[i].getMenu()[0].getDetails() << endl;
        vector<MealPackage> menu = restaurants[i].getMenu();
        for (size_t j = 0; j < menu.size(); ++j) {
            cout << j + 1 << ". " << menu[j].getDetails() << " - $" << menu[j].getPrice() << endl;
        }
    }
}