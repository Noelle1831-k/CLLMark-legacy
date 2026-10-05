bool AudioRecorder::initialize() {
    PaError err = Pa_Initialize();
    if (paNoError != err) {
        cerr << "PortAudio error: " << Pa_GetErrorText(err) << endl;
        return false;
    }
    return true;
}