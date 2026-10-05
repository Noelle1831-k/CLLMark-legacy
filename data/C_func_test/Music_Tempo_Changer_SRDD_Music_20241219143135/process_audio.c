void process_audio(AudioData *audio_data) {
    if (!audio_data) {
        printf("No audio data to process.\n");
        return;
    }
    unsigned char max_amplitude = 0;
    for (unsigned int i = 0; i < audio_data->header.data_size; i++) {
        if (audio_data->data[i] > max_amplitude) {
            max_amplitude = audio_data->data[i];
        }
    }
    if (max_amplitude == 0) {
        printf("Audio data is silent.\n");
        return;
    }
    float normalization_factor = 255.0 / max_amplitude;
    for (unsigned int i = 0; i < audio_data->header.data_size; i++) {
        audio_data->data[i] = (unsigned char)(audio_data->data[i] * normalization_factor);
    }
    printf("Audio normalization complete.\n");
}