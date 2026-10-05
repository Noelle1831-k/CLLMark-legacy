Dataset* merge_vertically(Dataset* ds1, Dataset* ds2) {
    Dataset* merged_ds = (Dataset*)malloc(sizeof(Dataset));
    if (!merged_ds) return NULL;
    merged_ds->rows = ds1->rows + ds2->rows;
    merged_ds->cols = ds1->cols;
    for (int i = 0; i < ds1->rows; i++) {
        for (int j = 0; j < ds1->cols; j++) {
            strcpy(merged_ds->data[i][j], ds1->data[i][j]);
        }
    }
    for (int i = 0; i < ds2->rows; i++) {
        for (int j = 0; j < ds2->cols; j++) {
            strcpy(merged_ds->data[ds1->rows + i][j], ds2->data[i][j]);
        }
    }
    return merged_ds;
}