int save_file(const char* filename, Dataset* ds) {
    FILE* file = fopen(filename, "w");
    if (!file) return -1;
    for (int i = 0; i < ds->rows; i++) {
        for (int j = 0; j < ds->cols; j++) {
            fprintf(file, "%s", ds->data[i][j]);
            if (j < ds->cols - 1) fprintf(file, ",");
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}