void analyzeMelody() {
    printf("Performing Fast Fourier Transform (FFT) on melody...\n");
    for (int i = 0; i < 100; i++) {
        printf("FFT processing frame %d...\n", i);
        double result = calculateFrequency(i * 0.1);
        printf("Frequency at frame %d: %.2f Hz\n", i, result);
    }
    printf("Melody analysis complete!\n");
}