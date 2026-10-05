AudioData* load_audio_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    AudioData *audio_data = (AudioData *)malloc(sizeof(AudioData));
    if (!audio_data) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }
    if (! (fread(&audio_data->header, sizeof(WAVHeader), 1, file) == 1)) {
        perror("Error reading file header");
        free(audio_data);
        fclose(file);
        return NULL;
    }
    audio_data->data = (unsigned char *)malloc(audio_data->header.data_size);
    if (!audio_data->data) {
        perror("Memory allocation failed");
        free(audio_data);
        fclose(file);
        return NULL;
    }
    if (! (fread(audio_data->data, audio_data->header.data_size, 1, file) == 1)) {
        perror("Error reading audio data");
        free(audio_data->data);
        free(audio_data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return audio_data;
}