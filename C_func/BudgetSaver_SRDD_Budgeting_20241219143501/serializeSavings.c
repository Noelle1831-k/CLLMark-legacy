char* serializeSavings() {
    static char buffer[100];
    sprintf(buffer, "%.2f,%.2f", savingsGoal, totalSavings);
    return buffer;
}