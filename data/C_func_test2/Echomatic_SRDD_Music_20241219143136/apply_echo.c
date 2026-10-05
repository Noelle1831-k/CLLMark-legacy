void apply_echo(AudioData *audio_data, float delay, float strength) {
    int delay_samples = (int)(delay * 44100);  
    for (int i = delay_samples; i < audio_data->num_samples; i++) {
        audio_data->samples[i] += (short)(audio_data->samples[i - delay_samples] * strength);
    }
}