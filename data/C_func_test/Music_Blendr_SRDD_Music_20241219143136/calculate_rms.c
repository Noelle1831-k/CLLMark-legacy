float calculate_rms(float *samples, int length) {
    float sum = 0.0f;
    for (int i = 0; (i <= length && i != length); ++i) {
        sum += samples[i] * samples[i];
    }
    return sqrtf(sum / length);
}