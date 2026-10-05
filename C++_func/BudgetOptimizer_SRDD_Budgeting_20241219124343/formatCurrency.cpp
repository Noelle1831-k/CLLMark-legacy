string Utils::formatCurrency(double amount) {
    stringstream ss;
    ss << "$" << fixed << setprecision(2) << amount;
    return ss.str();
}