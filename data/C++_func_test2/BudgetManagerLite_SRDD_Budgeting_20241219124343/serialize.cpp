string Transaction::serialize() const {
    return type + "," + to_string(amount) + "," + description;
}