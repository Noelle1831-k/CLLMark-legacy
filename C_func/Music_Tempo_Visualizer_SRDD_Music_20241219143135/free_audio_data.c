void free_audio_data(AudioData *audio_data) {
    if (audio_data) {
        free(audio_data->data);
        free(audio_data);
    }
}