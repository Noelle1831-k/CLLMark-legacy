void freeData(Data *data) {
    if (data) {
        free(data->records);
        free(data);
    }
}