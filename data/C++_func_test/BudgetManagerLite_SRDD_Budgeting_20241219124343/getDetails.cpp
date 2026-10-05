string Transaction::getDetails() const {
    return type + ": $" + to_string(amount) + " - " + description;
}