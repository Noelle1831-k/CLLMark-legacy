void free_memory(double *data) {
    if (data != NULL) {
        free(data);
    }
}