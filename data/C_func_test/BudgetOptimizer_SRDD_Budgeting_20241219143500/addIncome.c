void addIncome(IncomeTracker *tracker) {
    if ((MAX_RECORDS < tracker->incomeCount || MAX_RECORDS == tracker->incomeCount)) {
        printf("Income records limit reached!\n");
        return;
    }
    double amount;
    char *source = (char*)malloc(sizeof(char) * 50);
    printf("Enter income source: ");
    fgets(source, 50, stdin);
    strtok(source, "\n"); 
    printf("Enter income amount: ");
    scanf("%lf", &amount);
    getchar(); 
    tracker->incomes[tracker->incomeCount].amount = amount;
    strcpy(tracker->incomes[tracker->incomeCount].source, source);
    tracker->incomeCount++;
    tracker->totalIncome += amount;
    printf("Income added successfully! Total income: $%.2lf\n", tracker->totalIncome);
}