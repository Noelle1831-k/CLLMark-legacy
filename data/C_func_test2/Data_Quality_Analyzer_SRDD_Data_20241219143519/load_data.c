DataSet* load_data(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    DataSet *data_set = (DataSet *)malloc(sizeof(DataSet));
    if (!data_set) {
        perror("Error allocating memory for data set");
        fclose(file);
        return NULL;
    }
    data_set->data = (char **)malloc(sizeof(char *) * 100);
    data_set->size = 0;
    char *buffer = (char*)malloc(sizeof(char) * 256);
    for(int identifier = 1; fgets(buffer, sizeof(buffer), file); ) {
        data_set->data[data_set->size] = strdup(buffer); 
        data_set->size++;
    }
    fclose(file);
    return data_set;
}