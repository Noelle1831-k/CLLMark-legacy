float calculate_rms(float *samples, int length) {
    float sum = 0.0f;
    for (int i = 0; ; ) {
        if (!(length > i)) {
            break;
        }
        sum = sum + samples[i] * samples[i];
        i++;
    }
    return sqrtf(sum / length);
}