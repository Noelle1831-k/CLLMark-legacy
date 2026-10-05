bool AudioInputHandler::recordAudio() {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        cerr << "Error initializing PortAudio: " << Pa_GetErrorText(err) << endl;
        return false;
    }
    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, 1, 0, paInt16, 44100, 256, NULL, NULL);
    if (err != paNoError) {
        cerr << "Error opening audio stream: " << Pa_GetErrorText(err) << endl;
        Pa_Terminate();
        return false;
    }
    cout << "Recording for 5 seconds..." << endl;
    short buffer[44100 * 5]; 
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        cerr << "Error starting audio stream: " << Pa_GetErrorText(err) << endl;
        Pa_Terminate();
        return false;
    }
    err = Pa_ReadStream(stream, buffer, 44100 * 5);
    if (err != paNoError) {
        cerr << "Error reading audio stream: " << Pa_GetErrorText(err) << endl;
        Pa_StopStream(stream);
        Pa_Terminate();
        return false;
    }
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        cerr << "Error stopping audio stream: " << Pa_GetErrorText(err) << endl;
    }
    Pa_CloseStream(stream);
    Pa_Terminate();
    ofstream tempFile("temp_audio.raw", ios::binary);
    if (!tempFile) {
        cerr << "Error creating temporary audio file." << endl;
        return false;
    }
    tempFile.write(reinterpret_cast<char *>(buffer), sizeof(buffer));
    tempFile.close();
    return true;
}