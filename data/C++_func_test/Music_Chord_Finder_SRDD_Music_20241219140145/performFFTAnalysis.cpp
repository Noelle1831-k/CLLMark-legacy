void AudioProcessor::performFFTAnalysis() {
    size_t n = frequencyData.size();
    fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);
    fftw_plan plan = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    int i;
    for (i = 0; i < n; i++) {
        in[i][0] = frequencyData[i]; 
        in[i][1] = 0.0; 
    }
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    for (i = 0; i < n / 2; i++) {
        double frequency = i * 44100 / n; 
        double magnitude = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
        if (magnitude > 0.1) { 
            cout << "Detected frequency: " << frequency << " Hz with magnitude: " << magnitude << endl;
        }
    }
    fftw_free(in);
    fftw_free(out);
}