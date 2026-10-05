void generatePieChart() {
    printf("Generating pie chart...\n");
    int data[] = {30, 70}; 
    int total = 0;
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        total += data[i];
    }
    printf("Pie Chart:\n");
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("Segment %d: ", i + 1);
        int percentage = (data[i] * 100) / total;
        for (int j = 0; j < percentage; j++) {
            printf("#");
        }
        printf(" %d%%\n", percentage);
    }
}