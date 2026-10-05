void twoSampleTTest() {
    printf("Conducting two-sample t-test...\n");
    double mean1 = 5.0;  
    double mean2 = 4.5;
    double var1 = 1.0;
    double var2 = 1.2;
    int n1 = 30;
    int n2 = 25;
    double tStatistic = (mean1 - mean2) / sqrt((var1 / n1) + (var2 / n2));
    printf("T-Statistic: %.2f\n", tStatistic);
}