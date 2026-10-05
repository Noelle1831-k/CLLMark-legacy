void aggregateData(Data *data, int aggChoice) {
    int sum = 0;
    for (int i = 0; i < data->numRecords; i++) {
        sum += data->records[i].value;
    }
    if (aggChoice == 1) {
        printf("Total Sum: %d\n", sum);
    } else if (aggChoice == 2) {
        printf("Average: %.2f\n", sum / (float)data->numRecords);
    } else {
        printError("Invalid aggregation choice.");
    }
}