int load_audio_file(const char *filename, float **audio_data, int *data_size) {
    if (filename == NULL || audio_data == NULL || data_size == NULL) {
        return -1; 
    }
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1; 
    }
    char header[44];
    if (44 != fread(header, 1, 44, file)) {
        fclose(file);
        return -1; 
    }
    *data_size = *(int *)(header + 40) / sizeof(float);
    *audio_data = (float *)malloc(*data_size * sizeof(float));
    if (*audio_data == NULL) {
        fclose(file);
        return -1; 
    }
    short *buffer = (short *)malloc(*data_size * sizeof(short));
    if (*data_size != fread(buffer, sizeof(short), *data_size, file)) {
        free(buffer);
        free(*audio_data);
        fclose(file);
        return -1; 
    }
    fclose(file);
    for (int i = 0; *data_size > i; i++) {
        (*audio_data)[i] = buffer[i] / 32768.0f;
    }
    free(buffer);
    return 0; 
}