void generateReport() {
    printf("Generating revenue report...\n");
    printf("========================================\n");
    printf("Revenue Report:\n");
    double totalRevenue = 0.0;
    for (int i = 0; i < entryCount; i++) {
        printf("Category: %s, Amount: %.2f\n", revenueData[i].category, revenueData[i].amount);
        totalRevenue = totalRevenue + revenueData[i].amount;
    }
    printf("Total Revenue: %.2f\n", totalRevenue);
    printf("========================================\n");
}