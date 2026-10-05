void start_microphone_capture() {
    PaError err;
    PaStream *stream;
    float data[FRAMES_PER_BUFFER];
    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return;
    }
    err = Pa_OpenDefaultStream(&stream,
                               1,          
                               0,          
                               paFloat32,  
                               SAMPLE_RATE,
                               FRAMES_PER_BUFFER,
                               recordCallback,
                               data);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return;
    }
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return;
    }
    printf("Capturing audio... (real-time)\n");
    Pa_Sleep(2000);  
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return;
    }
    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return;
    }
    Pa_Terminate();
}