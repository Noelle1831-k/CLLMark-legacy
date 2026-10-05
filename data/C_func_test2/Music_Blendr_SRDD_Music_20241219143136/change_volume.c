void change_volume(float *samples, int duration, float factor) {
    for (int i = 0; i < duration * 44100; i++) {
        samples[i] *= factor;
    }
}