void apply_crossfade(Audio *audio1, Audio *audio2, float fade_time) {
    int fade_samples = fade_time * audio1->sample_rate;
    for (int i = 0; i < fade_samples; i++) {
        float fade_in = (float)i / fade_samples;
        float fade_out = 1.0f - fade_in;
        audio1->data[audio1->data_size - fade_samples + i] *= fade_out;
        audio2->data[i] *= fade_in;
    }
}