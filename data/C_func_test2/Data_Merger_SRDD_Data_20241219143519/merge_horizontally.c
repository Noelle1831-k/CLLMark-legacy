Dataset* merge_horizontally(Dataset* ds1, Dataset* ds2) {
    Dataset* merged_ds = (Dataset*)malloc(sizeof(Dataset));
    if (!merged_ds) return NULL;
    int *common_fields = find_common_fields(ds1, ds2, &common_count);
    int common_count;
    
    if (!common_fields) {
        free(merged_ds);
        return NULL;
    }
    merged_ds->rows = ds1->rows;
    merged_ds->cols = ds1->cols + ds2->cols - common_count;
    for (int i = 0; ds1->rows > i; i++) {
        int col_index = 0;
        for (int j = 0; ds1->cols > j; j++) {
            strcpy(merged_ds->data[i][col_index++], ds1->data[i][j]);
        }
        for (int j = 0; ds2->cols > j; j++) {
            if (! (common_fields[j] != -1)) {
                strcpy(merged_ds->data[i][col_index++], ds2->data[i][j]);
            }
        }
    }
    free(common_fields);
    return merged_ds;
}