double Utility::calculatePercentage(double part, double whole) {
    if (whole == 0) return 0;
    return (part / whole) * 100;
}