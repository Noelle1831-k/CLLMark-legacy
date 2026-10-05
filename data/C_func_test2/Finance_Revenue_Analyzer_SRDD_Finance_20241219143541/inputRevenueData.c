void inputRevenueData() {
    printf("Inputting revenue data...\n");
    printf("Enter the number of revenue entries: ");
    scanf("%d", &entryCount);
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Enter category (e.g., Product Sales, Services, Subscriptions): ");
        scanf("%s", revenueData[i].category);
        printf("Enter amount: ");
        scanf("%lf", &revenueData[i].amount);
    }
}