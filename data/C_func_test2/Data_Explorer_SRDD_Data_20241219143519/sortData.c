void sortData(Data *data, int sortChoice) {
    int compare;
    for (int i = 0; i < data->numRecords - 1; i++) {
        for (int j = 0; j < data->numRecords - i - 1; j++) {
            switch (sortChoice) {
                case 1: compare = strcmp(data->records[j].name, data->records[j + 1].name) > 0; break;
                case 2: compare = strcmp(data->records[j].name, data->records[j + 1].name) < 0; break;
                case 3: compare = data->records[j].value > data->records[j + 1].value; break;
                case 4: compare = data->records[j].value < data->records[j + 1].value; break;
                default: printError("Invalid sort choice."); return;
            }
            if (compare) {
                Record temp = data->records[j];
                data->records[j] = data->records[j + 1];
                data->records[j + 1] = temp;
            }
        }
    }
    printf("Data sorted successfully.\n");
}