int main() {
    User user;
    initializeUser(&user);
    inputUserData(&user);
    Budget budget;
    calculateBudget(&user, &budget);
    generateReport(&user, &budget);
    return 0;
}