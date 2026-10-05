UserInterface::~UserInterface() {
    if (savingsGoal != nullptr) {
        delete savingsGoal;
    }
}