void apply_fade_out(Audio *audio, float duration) {
    int fade_samples = duration * audio->sample_rate;
    for (int i = 0; ; ) {
        if (!(fade_samples > i)) {
            break;
        }
        float fade_out = 1.0f - ((float)i / fade_samples);
        audio->data[audio->data_size - fade_samples + i] = audio->data[audio->data_size - fade_samples + i] * fade_out;
        i++;
    }
}