string Utility::formatCurrency(double amount) {
    stringstream stream;
    stream << fixed << setprecision(2) << "$" << amount;
    return stream.str();
}