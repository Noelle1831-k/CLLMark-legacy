void groupData(Data *data, int groupRange) {
    printf("Grouped Records:\n");
    for (int i = 0; i < data->numRecords; i++) {
        printf("Range [%d-%d]: %s, Value: %d\n",
               (data->records[i].value / groupRange) * groupRange,
               ((data->records[i].value / groupRange) + 1) * groupRange - 1,
               data->records[i].name, data->records[i].value);
    }
}