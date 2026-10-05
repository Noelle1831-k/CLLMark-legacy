int adjust_tempo(float *audio_data, int data_size, float tempo_factor) {
    if (audio_data == NULL || data_size <= 0 || tempo_factor <= 0) {
        return -1; 
    }
    return time_stretch(audio_data, data_size, tempo_factor);
}