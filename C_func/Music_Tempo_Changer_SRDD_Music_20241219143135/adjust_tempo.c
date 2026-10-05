void adjust_tempo(AudioData *audio_data, float factor) {
    unsigned int new_data_size = (unsigned int)(audio_data->header.data_size / factor);
    unsigned char *new_data = (unsigned char *)malloc(new_data_size);
    if (!new_data) {
        perror("Memory allocation failed");
        return;
    }
    for (unsigned int i = 0; i < new_data_size; i++) {
        unsigned int old_index = (unsigned int)(i * factor);
        if (old_index < audio_data->header.data_size) {
            new_data[i] = audio_data->data[old_index];
        }
    }
    free(audio_data->data);
    audio_data->data = new_data;
    audio_data->header.data_size = new_data_size;
    audio_data->header.file_size = new_data_size + sizeof(WAVHeader) - 8;
}