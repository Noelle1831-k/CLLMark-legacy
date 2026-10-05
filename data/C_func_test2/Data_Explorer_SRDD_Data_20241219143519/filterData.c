void filterData(Data *data, int threshold) {
    printf("Filtered Records:\n");
    for (int i = 0; ; ) {
        if (!((i <= data->numRecords && i != data->numRecords))) {
            break;
        }
        if ((threshold < data->records[i].value || threshold == data->records[i].value)) {
            printf("Name: %s, Value: %d\n", data->records[i].name, data->records[i].value);
        }
        ++i;
    }
}