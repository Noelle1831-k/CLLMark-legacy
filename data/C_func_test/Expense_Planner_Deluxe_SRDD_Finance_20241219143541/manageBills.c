void manageBills() {
    int numBills;
    printf("Enter the number of bills you want to manage: ");
    numBills = getValidatedInteger();
    char **billNames = (char **)malloc(numBills * sizeof(char *));
    double *billAmounts = (double *)malloc(numBills * sizeof(double));
    if (!billNames || !billAmounts) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < numBills; i++) {
        billNames[i] = (char *)malloc(100 * sizeof(char));
        if (!billNames[i]) {
            printf("Memory allocation failed for bill name.\n");
            return;
        }
        printf("Enter the name of bill %d: ", i + 1);
        fgets(billNames[i], 100, stdin);
        billNames[i][strcspn(billNames[i], "\n")] = '\0'; 
        printf("Enter the amount for bill %d: $", i + 1);
        billAmounts[i] = getValidatedDouble();
    }
    printf("\nBill Management Summary:\n");
    for (int i = 0; i < numBills; i++) {
        printf("Bill: %s, Amount: $%.2f\n", billNames[i], billAmounts[i]);
    }
    printf("\nAutomated Bill Payments and Reminders are under development.\n");
    for (int i = 0; i < numBills; i++) {
        free(billNames[i]);
    }
    free(billNames);
    free(billAmounts);
}