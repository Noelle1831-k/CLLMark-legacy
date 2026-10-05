void AudioRecorder::stopRecording() {
    if (isRecording) {
        isRecording = false;
        saveAudioFile();
        cout << "Audio recording stopped." << endl;
    } else {
        cout << "No recording in progress." << endl;
    }
}