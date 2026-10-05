void deserializeSavings(const char *data) {
    sscanf(data, "%lf,%lf", &savingsGoal, &totalSavings);
}