string Expense::getDetails() const {
    return "Description: " + description + ", Amount: " + to_string(amount);
}