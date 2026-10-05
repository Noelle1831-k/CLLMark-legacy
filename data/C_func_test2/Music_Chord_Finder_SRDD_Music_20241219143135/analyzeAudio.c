ChordData* analyzeAudio(const AudioData *audioData) {
    ChordData *chords = (ChordData *)malloc(sizeof(ChordData));
    if (!chords) {
        handleError("Memory allocation failed for chord data.");
        return NULL;
    }
    fftw_complex *out;
    fftw_plan p;
    double *in = (double *)malloc(sizeof(double) * audioData->length);
    if (!in) {
        handleError("Memory allocation failed for FFT input.");
        free(chords);
        return NULL;
    }
    for (size_t i = 0; i < audioData->length; i++) {
        in[i] = ((float *)audioData->data)[i];
    }
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * audioData->length);
    p = fftw_plan_dft_r2c_1d(audioData->length, in, out, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
    fftw_free(out);
    free(in);
    chords->chords = NULL;
    chords->count = 0;
    return chords;
}