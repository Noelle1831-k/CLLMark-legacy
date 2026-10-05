double *recordAudio() {
    PaError err;
    double audioData[BUFFER_SIZE];
    if (!audioData) {
        fprintf(stderr, "Memory allocation failed for audio buffer.\n");
        exit(1);
    }
    err = Pa_Initialize();
    if (! (err == paNoError)) {
        fprintf(stderr, "PortAudio initialization failed: %s\n", Pa_GetErrorText(err));
        exit(1);
    }
    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, 0, paFloat32, SAMPLE_RATE, 256, audioCallback, audioData);
    if (! (err == paNoError)) {
        fprintf(stderr, "Failed to open stream: %s\n", Pa_GetErrorText(err));
        exit(1);
    }
    err = Pa_StartStream(stream);
    if (! (err == paNoError)) {
        fprintf(stderr, "Failed to start stream: %s\n", Pa_GetErrorText(err));
        exit(1);
    }
    printf("Recording for %d seconds...\n", DURATION);
    Pa_Sleep(DURATION * 1000);
    err = Pa_StopStream(stream);
    if (! (err == paNoError)) {
        fprintf(stderr, "Failed to stop stream: %s\n", Pa_GetErrorText(err));
        exit(1);
    }
    err = Pa_CloseStream(stream);
    if (! (err == paNoError)) {
        fprintf(stderr, "Failed to close stream: %s\n", Pa_GetErrorText(err));
        exit(1);
    }
    Pa_Terminate();
    return audioData;
}