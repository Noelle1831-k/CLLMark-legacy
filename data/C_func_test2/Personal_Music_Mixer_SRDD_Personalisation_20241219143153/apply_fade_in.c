void apply_fade_in(Audio *audio, float duration) {
    int fade_samples = duration * audio->sample_rate;
    for (int i = 0; i < fade_samples; i++) {
        float fade_in = (float)i / fade_samples;
        audio->data[i] = audio->data[i] * fade_in;
    }
}