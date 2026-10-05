void save_audio_file(const char *file_path, AudioData *audio_data) {
    FILE *file = fopen(file_path, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    if (fwrite(&audio_data->header, sizeof(WAVHeader), 1, file) != 1) {
        perror("Error writing file header");
        fclose(file);
        return;
    }
    if (fwrite(audio_data->data, audio_data->header.data_size, 1, file) != 1) {
        perror("Error writing audio data");
    }
    fclose(file);
}