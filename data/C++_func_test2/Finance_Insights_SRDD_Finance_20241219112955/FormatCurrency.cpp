string Utility::FormatCurrency(double amount) {
    ostringstream oss;
    oss << fixed << setprecision(2) << "$" << amount;
    return oss.str();
}