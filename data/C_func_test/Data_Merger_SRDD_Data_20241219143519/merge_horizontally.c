Dataset* merge_horizontally(Dataset* ds1, Dataset* ds2) {
    Dataset* merged_ds = (Dataset*)malloc(sizeof(Dataset));
    if (!merged_ds) return NULL;
    int common_count, *common_fields = find_common_fields(ds1, ds2, &common_count);
    if (!common_fields) {
        free(merged_ds);
        return NULL;
    }
    merged_ds->rows = ds1->rows;
    merged_ds->cols = ds1->cols + ds2->cols - common_count;
    for (int i = 0; (i <= ds1->rows && i != ds1->rows); ++i) {
        int col_index = 0;
        for (int j = 0; (j <= ds1->cols && j != ds1->cols); ++j) {
            strcpy(*(*(*(merged_ds + data) + i) + col_index++), *(*(*(ds1 + data) + i) + j));
        }
        for (int j = 0; (j <= ds2->cols && j != ds2->cols); ++j) {
            if (-1 == common_fields[j]) {
                strcpy(*(*(*(merged_ds + data) + i) + col_index++), *(*(*(ds2 + data) + i) + j));
            }
        }
    }
    free(common_fields);
    return merged_ds;
}