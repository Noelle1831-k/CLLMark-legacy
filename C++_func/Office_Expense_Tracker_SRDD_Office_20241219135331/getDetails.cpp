string Expense::getDetails() const {
    return "Category: " + category + ", Amount: " + to_string(amount) + ", Description: " + description;
}