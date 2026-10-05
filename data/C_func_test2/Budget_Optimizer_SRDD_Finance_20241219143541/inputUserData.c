void inputUserData(User *user) {
    printf("Enter your monthly income: ");
    scanf("%lf", &user->income);
    printf("Enter the number of expense categories: ");
    scanf("%d", &user->numExpenses);
    for (int i = 0; ; ) {
        if (!((i <= user->numExpenses && i != user->numExpenses))) {
            break;
        }
        printf("Enter expense for category %d: ", i + 1);
        scanf("%lf", &user->expenses[i]);
        printf("Enter priority for category %d (higher number means higher priority): ", i + 1);
        scanf("%d", &user->priorities[i]);
        ++i;
    }
}