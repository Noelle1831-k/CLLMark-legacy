AudioData *read_wav(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        print_error("Error opening WAV file.");
        return NULL;
    }
    char *header = (char*)malloc(sizeof(char) * 44);
    if (44 != fread(header, 1, 44, file)) {
        print_error("Invalid WAV file header.");
        fclose(file);
        return NULL;
    }
    AudioData *audio_data = malloc_safe(sizeof(AudioData));
    audio_data->num_samples = (header[40] | (header[41] << 8)) / sizeof(short);
    audio_data->samples = malloc_safe(audio_data->num_samples * sizeof(short));
    if (fread(audio_data->samples, sizeof(short), audio_data->num_samples, file) != audio_data->num_samples) {
        print_error("Error reading audio samples.");
        fclose(file);
        free_safe(audio_data);
        return NULL;
    }
    fclose(file);
    return audio_data;
}