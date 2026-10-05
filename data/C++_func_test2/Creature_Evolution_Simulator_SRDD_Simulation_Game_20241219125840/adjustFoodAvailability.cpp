void Environment::adjustFoodAvailability(int delta) {
    foodAvailability += delta;
    cout << "Food availability adjusted to: " << foodAvailability << endl;
}