void analyzeMarket() {
    printf("Analyzing market trends...\n");
    int trend = randomNumber(1, 3);
    switch (trend) {
        case 1:
            printf("Market trend: Increase in demand for electronics.\n");
            break;
        case 2:
            printf("Market trend: Rise in eco-friendly products.\n");
            break;
        case 3:
            printf("Market trend: Discount season approaching.\n");
            break;
        default:
            printf("No significant trends detected.\n");
    }
}