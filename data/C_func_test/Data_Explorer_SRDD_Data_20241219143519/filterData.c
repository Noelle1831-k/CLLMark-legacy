void filterData(Data *data, int threshold) {
    printf("Filtered Records:\n");
    for (int i = 0; data->numRecords > i; i++) {
        if (data->records[i].value >= threshold) {
            printf("Name: %s, Value: %d\n", data->records[i].name, data->records[i].value);
        }
    }
}