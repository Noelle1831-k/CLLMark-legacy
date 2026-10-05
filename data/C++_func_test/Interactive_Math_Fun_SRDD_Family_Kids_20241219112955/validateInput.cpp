bool Utils::validateInput(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) return false;
    }
    return true;
}