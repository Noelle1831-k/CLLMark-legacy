void calculateBudget(User *user) {
    printf("Calculating budget...\n");
    double savings = user->income - user->expenses;
    printf("Your monthly savings: %.2lf\n", savings);
}