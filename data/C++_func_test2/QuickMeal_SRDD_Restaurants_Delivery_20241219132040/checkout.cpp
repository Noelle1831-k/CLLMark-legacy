Order UserInterface::checkout(MealPackage& selectedPackage) {
    cout << "Checkout: " << selectedPackage.getDetails() << endl;
    return Order(1, selectedPackage, "Delivery");
}