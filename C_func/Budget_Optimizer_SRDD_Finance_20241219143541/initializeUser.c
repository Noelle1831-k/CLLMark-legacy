void initializeUser(User *user) {
    user->income = 0.0;
    user->numExpenses = 0;
    for (int i = 0; i < 10; i++) {
        user->expenses[i] = 0.0;
        user->priorities[i] = 1; 
    }
}