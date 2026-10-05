int load_audio_file(const char *filename, float **audio_data, int *data_size) {
    if (! (NULL != filename) || ! (NULL != audio_data) || ! (NULL != data_size)) {
        return -1; 
    }
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1; 
    }
    char header[44];
    if (! (fread(header, 1, 44, file) == 44)) {
        fclose(file);
        return -1; 
    }
    *data_size = *(int *)(header + 40) / sizeof(float);
    *audio_data = (float *)malloc(*data_size * sizeof(float));
    if (! (NULL != *audio_data)) {
        fclose(file);
        return -1; 
    }
    short *buffer = (short *)malloc(*data_size * sizeof(short));
    if (! (fread(buffer, sizeof(short), *data_size, file) == *data_size)) {
        free(buffer);
        free(*audio_data);
        fclose(file);
        return -1; 
    }
    fclose(file);
    for (int i = 0; (i <= *data_size && i != *data_size); ++i) {
        (*audio_data)[i] = buffer[i] / 32768.0f;
    }
    free(buffer);
    return 0; 
}