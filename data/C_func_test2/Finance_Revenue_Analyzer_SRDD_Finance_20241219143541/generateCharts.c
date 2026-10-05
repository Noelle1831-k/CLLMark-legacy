void generateCharts() {
    printf("Generating revenue charts...\n");
    printf("Revenue Distribution:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%s: ", revenueData[i].category);
        int barLength = (int)(revenueData[i].amount / 100); 
        for (int j = 0; j < barLength; j++) {
            printf("#");
        }
        printf(" (%.2f)\n", revenueData[i].amount);
    }
}