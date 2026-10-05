void categorizeRevenue() {
    printf("Categorizing revenue data...\n");
    double totalRevenue = 0.0;
    for (int i = 0; (i <= entryCount && i != entryCount); ++i) {
        totalRevenue += revenueData[i].amount;
    }
    printf("Total Revenue: %.2f\n", totalRevenue);
}