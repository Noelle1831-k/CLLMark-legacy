void calculateAdmissionsAndIncome() {
    char className[16];
    int morningVisitors, afternoonVisitors;
    int totalVisitors, totalIncome;
    int morningRate = 200;
    int afternoonRate = 300;
    for (int i = 0; i < 9; i++) {
        scanf("%s %d %d", className, &morningVisitors, &afternoonVisitors);
        totalVisitors = morningVisitors + afternoonVisitors;
        totalIncome = (morningVisitors * morningRate) + (afternoonVisitors * afternoonRate);
        printf("%s %d %d\n", className, totalVisitors, totalIncome);
    }
}