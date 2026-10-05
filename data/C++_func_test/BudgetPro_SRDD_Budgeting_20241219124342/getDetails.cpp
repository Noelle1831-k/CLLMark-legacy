string Transaction::getDetails() const {
    return "ID: " + to_string(id) + ", Amount: " + to_string(amount) +
           ", Date: " + date + ", Category: " + category;
}