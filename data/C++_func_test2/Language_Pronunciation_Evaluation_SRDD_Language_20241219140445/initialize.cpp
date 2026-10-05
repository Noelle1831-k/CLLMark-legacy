bool AudioRecorder::initialize() {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        cerr << "PortAudio error: " << Pa_GetErrorText(err) << endl;
        return false;
    }
    return true;
}