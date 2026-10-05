std::string Business::getSaveData() {
    return name + "\n" + to_string(revenue) + "\n" + to_string(expenses) + "\n";
}