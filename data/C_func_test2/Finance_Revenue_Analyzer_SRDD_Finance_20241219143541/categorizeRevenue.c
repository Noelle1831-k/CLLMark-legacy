void categorizeRevenue() {
    printf("Categorizing revenue data...\n");
    double totalRevenue = 0.0;
    for (int i = 0; ; ) {
        if (!(entryCount > i)) {
            break;
        }
        totalRevenue = totalRevenue + revenueData[i].amount;
        i++;
    }
    printf("Total Revenue: %.2f\n", totalRevenue);
}