int export_results(const char *filename, DataSet *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;  
    }
    for (int i = 0; i < data->num_rows; i++) {
        fprintf(file, "%f\n", data->predictions[i]);
    }
    fclose(file);
    return 0;
}