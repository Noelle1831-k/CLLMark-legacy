double Utilities::calculateGrowth(double current, double previous) {
    return ((current - previous) / previous) * 100;
}