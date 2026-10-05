void Investment::addInvestment(string type, double amount) {
    investments.push_back(make_pair(type, amount));
}