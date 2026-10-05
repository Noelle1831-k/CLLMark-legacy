void generateRecommendations() {
    printf("Generating revenue optimization recommendations...\n");
    printf("========================================\n");
    printf("Recommendations:\n");
    for (int i = 0; i < entryCount; i++) {
        if (revenueData[i].amount < 1000) {
            printf("Consider increasing focus on %s to boost revenue.\n", revenueData[i].category);
        } else {
            printf("Maintain strong performance in %s.\n", revenueData[i].category);
        }
    }
    printf("========================================\n");
}