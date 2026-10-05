void AudioRecorder::startRecording() {
    PaError err = Pa_OpenDefaultStream(&stream, 1, 0, paFloat32, 44100, 256, audioCallback, this);
    if (err != paNoError) {
        cerr << "PortAudio error: " << Pa_GetErrorText(err) << endl;
        return;
    }
    audioData.clear();
    isRecording = true;
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        cerr << "PortAudio error: " << Pa_GetErrorText(err) << endl;
        return;
    }
}