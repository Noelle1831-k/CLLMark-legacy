AudioData* load_music_file(const char *filename) {
    if (!validate_file_format(filename)) {
        return NULL;
    }
    AudioData *audio_data = (AudioData *)malloc(sizeof(AudioData));
    if (!audio_data) {
        return NULL;
    }
    audio_data->length = 1000;
    audio_data->data = (int *)malloc(audio_data->length * sizeof(int));
    if (!audio_data->data) {
        free(audio_data);
        return NULL;
    }
    for (int i = 0; i < audio_data->length; i++) {
        audio_data->data[i] = rand() % 100;
    }
    return audio_data;
}