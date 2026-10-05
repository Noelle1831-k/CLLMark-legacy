void process_data(DataSet *data) {
    for (int i = 0; i < data->row_count; i++) {
        if (data->rows[i].value < 0) {
            data->rows[i].valid = 0; 
        }
    }
    for (int j = 0; j < data->column_count; j++) {
        if (strcmp(data->columns[j].type, "string") == 0) {
            convert_column_to_int(data, j);
        }
    }
}